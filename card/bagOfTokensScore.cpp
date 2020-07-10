#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


int bagOfTokensScore(vector<int> tokens, int P) {
    sort(tokens.begin(), tokens.end());

    int isTop[tokens.size()];
    memset(isTop, 0, sizeof(isTop));
    int score = 0;
    int l = 0;
    int r = tokens.size() - 1;
    int maxscore = 0;
    while (l <= r && (P >= tokens[l] || score > 0)) {
        while (l <= r && P > 0 && P >= tokens[l]) {
            P -= tokens[l];
            ++l;
            ++score;
            cout << score << " ";
        }
        maxscore = max(maxscore, score);
        if (l <= r && score > 0) {
            cout << score << " ";
            P += tokens[r];
            --r;
            --score;
        }
    }
    return maxscore;
}

//int main() {
//    bagOfTokensScore({26}, 51);
//}