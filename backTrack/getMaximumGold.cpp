//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<vector<int>> gmg_grid;
//int **visit;
//int gmg_m;
//int gmg_n;
//int max_money = 0;
//
//void backTrack(int i, int j, int money) {
//    visit[i][j] = true;
//    money += gmg_grid[i][j];
//
//    bool hasRoad = false;
//
//    if (i - 1 >= 0 && visit[i - 1][j] == 0 && gmg_grid[i - 1][j] != 0) {
//        backTrack(i - 1, j, money);
//        visit[i - 1][j] = 0;
//        hasRoad = true;
//    }
//    if (i + 1 < gmg_m && visit[i + 1][j] == 0 && gmg_grid[i + 1][j] != 0) {
//        backTrack(i + 1, j, money);
//        visit[i + 1][j] = 0;
//        hasRoad = true;
//    }
//    if (j - 1 >= 0 && visit[i][j - 1] == 0 && gmg_grid[i][j - 1] != 0) {
//        backTrack(i, j - 1, money);
//        hasRoad = true;
//    }
//    if (j + 1 < gmg_n && visit[i][j + 1] == 0 && gmg_grid[i][j + 1] != 0) {
//        backTrack(i, j + 1, money);
//        visit[i][j - 1] = 0;
//        hasRoad = true;
//    }
//    if (!hasRoad && max_money < money) max_money = money;
//}
//
//int getMaximumGold(vector<vector<int>> &grid) {
//    if (grid.size() == 0)
//        return 0;
//    gmg_m = grid.size();
//    gmg_n = grid[0].size();
//    gmg_grid = grid;
//    visit = new int *[gmg_m];
//    for (int m = 0; m < gmg_m; ++m) {
//        for (int n = 0; n < gmg_n; ++n) {
//            for (int i = 0; i < gmg_m; ++i) {
//                visit[i] = new int[gmg_n];
//                memset(visit[i], 0, sizeof(int) * gmg_n);
//            }
//            backTrack(m, n, 0);
//        }
//    }
//
//    return max_money;
//}
//
////int main() {
////    vector<vector<int>> v = {
////            {0, 6, 0},
////            {5, 8, 7},
////            {0, 9, 0}
////    };
////
////    cout << getMaximumGold(v);
////}