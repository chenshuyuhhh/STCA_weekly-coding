#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

int gcd(int x, int y) {
    while (y != 0) {
        int re = x % y;
        x = y;
        y = re;
    }
    return x;
}

bool hasGroupsSizeX(vector<int> &deck) {
    map<int, int> count;
    for (int de:deck) ++count[de];

    auto cnt = count.begin();
    int gcdnum = cnt->second;
    ++cnt;
    for (; cnt != count.end(); ++cnt) {
        gcdnum = gcd(gcdnum, cnt->second);
    }
    return gcdnum >= 2;
}
