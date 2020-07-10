//#include <iostream>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
////
//// Created by 陈姝宇 on 2020/7/5.
////
//long long cnt = 0;
//int size;
//char chars[3] = {'1', '2', '3'};
//
//void backTrack(string x) {
//    if (x.size() == size) {
//        ++cnt;
//        return;
//    }
//
//    for (char c : chars) {
//        if (x.size() < 2) {
//            backTrack(x + c);
//        } else {
//            bool isC = true;
//            for (int j = 0; j < 2; ++j) {
//                if (x[j] != c) {
//                    isC = false;
//                    break;
//                }
//            }
//            if (!isC) backTrack(x + c);
//        }
//    }
//}
//
//long long cntNum(int n) {
//    long long sum = pow(3, n);
//    if (n < 3)
//        return sum;
//    sum -= 3;
//    if (n == 3)
//        return sum;
//    // n-1
//    sum -= 12;
//    if (n == 4)
//        return sum;
//    for (int i = 3; i < n - 2; ++i) {
//        sum -= pow(3, n - i - 1) * 12;
//        sum -= pow(3, n - i - 2) * 4 * (n - i + 1);
//    }
//    return sum;
//}
//
//long long cntnum(int n) {
//    if (n < 3)
//        return pow(3, n);
//    if (n == 3)
//        return pow(3, n) - 3;
//    // n-1
//    if (n == 4)
//        return pow(3, n) - 15;
//    long long sum = 3 * cntnum(n - 1) - cntnum(n - 3);
//    return sum;
//}
//
//int main1_1() {
//    int n;
//    cin >> n;
//    size = n;
//    backTrack("");
//    cout << cnt;
//    return 0;
//}
//
//int main1() {
//    int n;
//    cin >> n;
//    size = n;
//    cout << cntnum(n) << endl;
//}
