#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/7/8.
//
struct fileNode {
    int cnt;
    int cap;
    vector<int> blocks;

    // empty initial
    fileNode() : cnt(0), cap(0), blocks({}) {};
};

int main() {
    int n; // n files
    int m; // m blocks
    int k; // k ops
    int size; // block size
    cin >> n >> m >> k >> size;

    bool isUse[m];
    string blocks[m];
    for (int l = 0; l < m; ++l) {
        isUse[l] = false;
        string s;
        blocks[l] = s;
    }

    fileNode *files[n + 1];
    for (int j = 1; j <= n; ++j) {
        files[j] = new fileNode();
    }

    // 1≤𝑥≤𝑛，0≤𝑜𝑓𝑓𝑠𝑒𝑡≤10^9，1≤𝑦≤10^9
    for (int i = 0; i < k; ++i) {
        char op;
        int x;
        cin >> op >> x;

        fileNode *file = files[x];
        switch (op) {
            case 'A': {
                long offset;
                string str;
                cin >> offset >> str;

                if (offset > file->cnt) {
                    // exceed end of file
                    offset = file->cnt;
                }
                if (file->cnt == 0) {
                    int p = 0;
                    int b = 0;
                    for (int j = 0; j < m; ++j) { // j blocks
                        if (!isUse[j]) { // no used
                            isUse[j] = true;
                            file->blocks.push_back(j);
                            int rev = str.size() - p;
                            if (size >= rev) { // not exceed
                                blocks[j] = str.substr(p, rev);
                                break;
                            } else { // exceed block size
                                blocks[j] = str.substr(p, size);
                                p = p + size;
                                // find another block;
                            }
                            ++b;
                        }
                    }
                    file->cap += b * size;
                    file->cnt += p;
                } else if (offset + str.size() > file->cap) {
                    int lastblock = file->blocks.back();
                    int p = file->cap - offset;
                    blocks[lastblock] += str.substr(0, p);
                    // write exceed str
                    int b = 0;
                    for (int j = 0; j < m && p < str.size(); ++j) { // j blocks
                        if (!isUse[j]) { // no used
                            file->blocks.push_back(j);
                            isUse[j] = true;
                            int rev = str.size() - p;
                            if (size >= rev) { // not exceed
                                blocks[j] = str.substr(p, rev);
                                break;
                            } else { // exceed block size
                                blocks[j] = str.substr(p, size);
                                p = p + size;
                                // find another block;
                            }
                            ++b;
                        }
                    }
                    file->cap += b * size;
                    file->cnt += (p + 1);
                    // in cap str
                } else {
                    int lastblock = file->blocks.back();
                    blocks[lastblock] += str;
                    file->cnt += str.size();
                }

                sort(file->blocks.begin(), file->blocks.end());
                break;
            }
            case 'D': {
                int offset;
                int y;
                cin >> offset >> y;
                if (offset >= file->cnt) break;
                // exceed file content
                if (offset + y >= file->cnt) {
                    y = file->cnt - offset;
                    while (y >= size) {
                        int b_num = file->blocks.back();
                        blocks[b_num] = "";
                        isUse[b_num] = false;
                        file->blocks.pop_back();

                        file->cap -= size;
                        y -= size;
                    }
                    if (y > 0) {
                        int b_num = file->blocks.back();
                        blocks[b_num] = blocks[b_num].substr(0, size - y);
                    }
                } else {
                    int begin = offset / size;
                    int p = offset % size;
                    vector<int> v = file->blocks;
                    while (y > 0) {
                        if (p == 0 && p + y == size) {
                            file->cap -= size;
                            blocks[v[begin]] = "";
                            vector<int> newv;
                            for (int j = 0; j < v.size(); ++j) {
                                if (j != begin) {
                                    newv.push_back(j);
                                }
                            }
                            v.assign(newv.begin(), newv.end());
                            break;
                        } else if (p + y <= size) {
                            string temp = blocks[v[begin]];
                            string s2 = temp.substr(p + y, size - p);
                            string s1 = temp.substr(0, p);
                            blocks[v[begin]] = s2 + s1;
                            break;
                        } else if (p == 0) {
                            file->cap -= size;
                            y = y - size;
                            blocks[v[begin]] = "";
                            vector<int> newv;
                            for (int j = 0; j < v.size(); ++j) {
                                if (j != begin) {
                                    newv.push_back(j);
                                }
                            }
                            v.assign(newv.begin(), newv.end());
                            ++begin;
                        } else {
                            string temp = blocks[v[begin]].substr(0, p);
                            blocks[v[begin]] = temp;
                            ++begin;
                        }
                    }
                }

                file->cnt -= y;

                break;
            }
            case 'B': {
                vector<int> v = file->blocks;
                int size = v.size();
                printf("%d ", size);
                for (int j = 0; j < size; ++j) {
                    printf("%d ", v[j] + 1);
                }
                printf("\n");
                break;
            }
            case 'C': {
                long offset;
                int y;
                cin >> offset >> y;
                if (offset >= file->cnt) printf("-2");
                else if (offset + y > file->cnt) printf("-1");
                else {
                    vector<int> v = file->blocks;
                    int begin = offset / size;
                    int p = offset % size;
                    string result;
                    while (y > 0) {
                        if (p + y <= size) {
                            result += blocks[v[begin]].substr(p, y);
                            break;
                        } else {
                            int l = size - p;
                            result += blocks[v[begin]].substr(p, l);
                            p = 0;
                            y -= l;
                            ++begin;
                        }
                    }
                    cout << result << endl;
                }
                break;
            }
            default:
                break;
        }
    }
}