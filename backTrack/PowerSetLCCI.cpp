#include <vector>
#include <iostream>

using namespace std;

// result = []
// def backtrack(路径, 选择列表):
// if 满足结束条件:
// result.add(路径)
// return
//
// for 选择 in 选择列表:
// 做选择
//        backtrack(路径, 选择列表)
// 撤销选择


vector<int> mnums;;

vector<vector<int>> back(vector<int> &line, int start,vector<vector<int>> &result) {
    for (int i = start; i < mnums.size(); ++i) {
        line.push_back(mnums[i]);
        result.push_back(line);
        back(line, i + 1,result);
        line.pop_back();
    }
    return result;
}


vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> line;
    if (nums.size() == 0) return {};

    mnums = nums;
    vector<vector<int>> result;

    result.push_back(line);
    return back(line, 0,result);
}