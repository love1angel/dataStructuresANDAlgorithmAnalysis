/*
 * @Author: xiepeng
 * @email: xp1762638547@163.com
 * @Date: 2021-04-17 23:40:49
 * @LastEditTime: 2021-04-18 00:45:21
 * @Description: 二分查找
 */
#include<stdio.h>
#define NotFind -1
#define Position int
#define ElementType int

/**
 * 二分查找
 * T(n) 最好：O(1) 最坏：O(n)
 */
Position BinarySearch(const ElementType list[], int len, ElementType x) {
    ElementType left = 0, right = len - 1;
    while (left <= right) {
        ElementType middle = (left + right) / 2;
        if (list[middle] == x) {
            return middle;
        } else if (x < list[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return NotFind;
}
int main(int argc, char const *argv[]) {
    ElementType list[] = {1, 2, 3, 4, 6, 7};
    Position idx =  BinarySearch(list, sizeof(list)/sizeof(ElementType), 5);
    printf("%d", idx);
    return 0;
}
