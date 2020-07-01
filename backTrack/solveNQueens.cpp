#include <vector>
#include <iostream>
#include <set>

using namespace std;

int snq_n;

string getStr(int x) {
    string s = "";
    for (int i = 0; i < snq_n; ++i) {
        if (i == x)s += 'Q';
        else s += '.';
    }
    return s;
}

void backTrack(int n, vector<string> state,vector<vector<string>>& result) {
    if (n == 4) {
        result.push_back(state);
        return;
    }

    // this line -- n
    for (int i = 0; i < snq_n; ++i) {
        bool notUse = true; // notUse has not same

        for (int j = n - 1; j >= 0; --j) { // check before line
            // check top || check left diagonal || check right diagonal
            if (state[j][i] != '.'
                || ((i + j - n) >= 0 && (state[j][i + j - n] != '.'))
                || ((i + n - j) < snq_n && (state[j][i + n - j] != '.'))) {
                notUse = false;
                break;
            }
        }

        if (!notUse) continue; // hasUsed, cannot, visit next

        // satify
        state.push_back(getStr(i));
        backTrack(n + 1, state,result);
        state.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    snq_n = n;
    backTrack(0, {},result);
    return result;
}

void printStrTwoVec(vector<vector<string>> v) {
    for (auto &i : v) {
        for (string s:i) {
            cout << s << endl;
        }
        cout << endl;
    }
}

//int main() {
//    printStrTwoVec(solveNQueens(4));
//}