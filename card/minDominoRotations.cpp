#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int minDominoRotations(vector<int> &A, vector<int> &B) {
    int size = A.size();
    if (size == 0)
        return 0;
    if (size == 1)
        return A[0];

    int num = A[0];
    bool isSuccess = true;
    int swap = 0;
    for (int i = 1; i < size; ++i) {
        if (A[i] != num) {
            if (B[i] != num) {
                isSuccess = false;
                break;
            } else ++swap;
        }
    }

    if (isSuccess)
        return min(swap, size - swap);
    // not success
    num = B[0];
    swap = 0;
    isSuccess = true;
    for (int i = 1; i < size; ++i) {
        if (A[i] != num && B[i] != num) {
            if (B[i] != num) {
                isSuccess = false;
                break;
            } else ++swap;
        }
    }
    if (isSuccess)
        return min(swap, size - swap);
    return -1;
}