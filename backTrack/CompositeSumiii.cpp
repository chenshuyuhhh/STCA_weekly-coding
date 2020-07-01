#include <vector>
#include <iostream>

using namespace std;
// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
// 说明：
//
// 所有数字都是正整数。
// 解集不能包含重复的组合。

int csiii_n;

void backtrack(vector<int> status, int k, int start, int sum,vector<vector<int>>& result) {
    if (k == 0) {
        if (sum == csiii_n) result.push_back(status);
        return;
    }

    for (int i = start; i <= 9; ++i) {
        int sumtemp = sum + i;
        if (sumtemp <= csiii_n) {
            status.push_back(i);
            backtrack(status, k - 1, i + 1, sumtemp,result);
            status.pop_back();
        } else break; // else is also exceed
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    csiii_n = n;
    backtrack({}, k, 1, 0,result);
    return result;
}

void printIntVec(vector<vector<int>> v) {
    for (auto & i : v) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

//int main() {
//    printIntVec(combinationSum3(3, 9));
//}