#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

int gcd3(int x, int y) {
    while (y != 0) {
        int re = x % y;
        x = y;
        y = re;
    }
    return x;
}

int main3() {
    int n;
    int q;
    cin >> n >> q;

    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    map<int, set<int>> mmap;
    //map<int,vector<int>>
    int result = 0;

    if (q <= 1) {
        for (int i = 0; i < q; ++i) cout << 0;
    } else {
        for (int i = 0; i < q; ++i) {
            int x;
            cin >> x;
            x = a[x];
            if (mmap.find(x) == mmap.end()) {
                mmap[x] = {};
                //x-->m
                for (auto &m : mmap) {
                    if (m.first != x && gcd3(m.first, x) == 1) {
                        ++result;
                        mmap[m.first].insert(x);
                        mmap[x].insert(m.first);
                    }
                }
            } else {
                set<int> v = mmap[x];
                result -= mmap[x].size();
                for (int vnum:v) {
                    mmap[vnum].erase(x);
                }
                mmap.erase(x);
            }
            cout << result << endl;
        }
    }
}
