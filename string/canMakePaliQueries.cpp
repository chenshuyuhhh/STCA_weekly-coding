#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;


vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    vector<bool> result;
    map<char, int> statictis[s.size() + 1];
    map<char, int> m;
    statictis[0] = m;
    for (int i = 0; i < s.size(); ++i) {
        ++m[s[i]];
        statictis[i + 1] = m;
    }

    for (vector<int> query:queries) {
        string str = s.substr(query[0], query[1] - query[0] + 1);
        // 如果字符串是奇数，则本身存在一个奇数字符，所以就可以为更改数+1
        int k = query[2];
        int change = 0;
        map<char, int> mleft = statictis[query[0]];
        map<char, int> mright = statictis[query[1] + 1];
        for (auto &it : mright) {
            if ((it.second - mleft[it.first]) % 2 != 0) {
                ++change;
            }
        }
        result.push_back((change >> 1) <= k);
    }
    return result;
}

//int main() {
//    string s = "hunu";
//    vector<vector<int>> queries = {
//            {3, 3, 0},
//            {1, 2, 0},
//            {0, 3, 1}};
//    string s2 = "abcda";
//    vector<vector<int>> queries2 = {
////            {3, 3, 0},
////            {1, 2, 0},
////            {0, 3, 1},
//            {0, 3, 2},
//            {0, 4, 1}};
//    canMakePaliQueries(s2, queries2);
//}