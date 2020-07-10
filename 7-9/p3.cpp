#include <iostream>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

//
// Created by 陈姝宇 on 2020/7/8.
//
int visit[100001];
vector<int> metrix[100001];
vector<int> future[100001];
set<int> notin;
set<int> hasin;
int m, n; // 𝑛  个点，𝑚 条边
long cnt = 0;

void dfs(int i) {
    visit[i] = 1;
    for (int next:metrix[i]) {
        if (!visit[next])dfs(next);
    }
}

void backTrack(int node) {
    if (hasin.size() == n) {
        ++cnt;
        return;
    }

    for (int next:future[node]) {
        if (notin.find(next) != notin.end() && visit[next] == 0) {
            notin.erase(next);
            hasin.insert(next);
            visit[next] = 1;
            backTrack(next);
            visit[next] = 0;
            notin.insert(next);
            hasin.erase(next);
        }
    }

}

void backTrack2(int i) {
    visit[i] = 1;
    for (int next:future[i]) {
        if (!visit[next])dfs(next);
    }
}

int mainp3() {
    cin >> n >> m;
//    vector<int> metrix[n + 1];
//    vector<int> future[n + 1];

    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            metrix[x].push_back(y);
            metrix[y].push_back(x);
        } else {
            future[x].push_back(y);
            future[y].push_back(x);
        }
    }

    for (int j = 1; j <= n; ++j) {
        visit[j] = 0;
    }

    dfs(0);

    for (int j = 1; j <= n; ++j) {
        if (visit[j] == 0) notin.insert(j);
        else hasin.insert(j);
    }

    int line = 0;
    for (int node:hasin) {
        for (int next:future[node]) {
            if (hasin.find(next) != hasin.end())++line;
        }
    }
    for (int node:hasin) {
        backTrack(node);
    }
    cnt = (pow(2, cnt) - 1) * pow(2, line);

    cout << cnt % 998244353;

}