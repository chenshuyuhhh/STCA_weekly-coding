//
// Created by 陈姝宇 on 2020/7/5.
//

#include <iostream>

void quickSort(int a[], int begin, int end);
//
//int main(int argc, char *argv[]) {
//    int a[] = {3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
//    int length = sizeof(a) / sizeof(int);
//
//    quickSort(a, 0, length - 1);      // 快速排序
//
//    for (int i = 0; i < length; i++)
//        std::cout << a[i] << "  ";
//    std::cout << std::endl;
//    return 0;
//}

/* 快速排序 */
void quickSort(int a[], int begin, int end) {
    if (begin >= end)
        return;
    int left = begin, right = end;
    int pivot_value = a[left];
    while (left < right) {
        if (a[left + 1] < pivot_value) {
            a[left] = a[left + 1];
            left++;
        } else if (a[left + 1] >= pivot_value) {
            std::swap(a[left + 1], a[right]); // std::swap()
            right--;
        }
    }
    a[left] = pivot_value;
    quickSort(a, begin, left - 1);    // 递归
    quickSort(a, left + 1, end);
}

