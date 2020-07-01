#include <vector>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int ntp_cnt = 0;
string titleS;

void backTrack(int n, int use[], string s) {
    if (s.size() == titleS.size())
        return;
    set<char> repeated;
    for (int i = 0; i < titleS.size(); ++i) {
        if (use[i] == 0 && repeated.find(titleS[i]) == repeated.end()) {
            repeated.insert(titleS[i]);
            use[i] = 1;
            s += titleS[i];
            //cout << s << endl;
            ++ntp_cnt;
            backTrack(n + 1, use, s);
            use[i] = 0;
            s = s.substr(0, s.size() - 1);
        }
    }
}

int numTilePossibilities(string tiles) {
    titleS = tiles;
    int use[tiles.size()];
    memset(use, 0, sizeof(use));
    backTrack(0, use, "");
    return ntp_cnt;
}

//int main() {
//    cout << numTilePossibilities("AAABBC");
//}