//2147483647
//9223372036854775807
//
// Created by 陈姝宇 on 2020/7/5.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int begin, int end) {
    int pivot = v[begin];
    int left = begin + 1;
    int right = end;
    while (true) {
        while (left < right && v[right] >= pivot)
            right--;
        while (left < right && v[left] < pivot)
            left++;
        if (left == right)
            break;
        swap(v[left], v[right]);
    }
    if (v[left] >= pivot)
        return begin;
    v[begin] = v[left];
    v[left] = pivot;
    return left;
}

void quickSort(vector<int> &v, int begin, int end) {
    if (begin >= end)
        return;
    int boundary = partition(v, begin, end);
    quickSort(v, begin, boundary - 1);
    quickSort(v, boundary + 1, end);
}

void sort(vector<int> &v) {
    quickSort(v, 0, v.size() - 1);
}

void display(vector<int> &v) {
    for (int &iter : v)
        cout << iter << "  ";
    cout << endl;
}

//int main(int argc, char *argv[]) {
//
//    int a[] = {3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
//
//    vector<int> vec(a, a + 10);
//
//    sort(vec);
//    display(vec);
//    return 0;
//}
