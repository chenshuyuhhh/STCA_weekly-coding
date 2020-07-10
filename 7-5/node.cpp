#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;
//
// Created by 陈姝宇 on 2020/7/5.
//

struct Node {
    int val;
    vector<Node *> childs;
    Node *parent;

    Node(int val, Node *node) : val(val), childs({node}) {};
};

//void findNode() {
//
//}

int main2() {
    int N;
    cin >> N;
    int size = N - 1;
    set<int> m[N + 1];
    set<int> ones;
    for (int i = 0; i < size; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        m[n1].insert(n2);
        m[n2].insert(n1);
    }
    for (int i = 1; i <= N; ++i) {
        if (m[N].size() == 1) ones.insert(N);
    }
    int ai[1];
    for (int i = 1; i <= N; ++i) {
        cin >> ai[i];
    }

    Node *head;
    set<int> hasnode;
    while (!ones.empty()) {
        for (int one:ones) {
            //  m[one][0] is parent of one
            Node *n = new Node(one, nullptr);
//            if (hasnode.find(m[one]) != hasnode.end()) {
//
//            }
        }
    }
}
