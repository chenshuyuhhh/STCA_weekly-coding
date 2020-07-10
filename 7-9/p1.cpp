#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//
// Created by 陈姝宇 on 2020/7/8.
//

// 0,10^9

int mainp1() {
    int n, m;
    cin >> n >> m;
    long files[n + 1];
    for (int j = 0; j <= n; ++j) {
        files[j] = 0;
    }
    long maxsize = pow(10, 9);

    for (int i = 0; i < m; ++i) {
        char op;
        cin >> op;
        int x;
        long y;
        cin >> x >> y;

        if (op == 'A') {
            // add op
            files[x] = min(maxsize,files[x]+y);
        } else if (op == 'D') {
            if (files[x] < y) files[x] = 0;
            else files[x] -= y;
        }
    }

    for (int j = 1; j <= n; ++j) {
        printf("%ld\n",files[j]);
    }
}