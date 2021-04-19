/*
 * @Author: xiepeng
 * @Email: xp1762638547@163.com
 * @Date: 2021-04-19 22:02:30
 * @LastEditTime: 2021-04-19 22:48:57
 * @Description: bubble sort
 */
#include<stdio.h>
#define ELEMENTTYPE int
/**
 * T(n): both avg and worst are O(n^2)
 * >= : unstable > : stable
 */
ELEMENTTYPE a[] = {5, 2, 1, 6, 4}, len = sizeof(a)/sizeof(int);
void swap(ELEMENTTYPE *a, ELEMENTTYPE *b) {
    ELEMENTTYPE temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * order by desc
 */
void BubbleSortDESC(ELEMENTTYPE a[], int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = len-1; j > i; j--) {
            if (a[j] > a[j-1]) {
                swap(&a[j], &a[j-1]);
            }            
        }        
    }
}
/**
 * order by asc
 */
void BubbleSortASC(ELEMENTTYPE a[], int len) {
    for (int i = len-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }            
        }        
    }
}
int main(int argc, char const *argv[]) {
    ELEMENTTYPE a[] = {5, 2, 1, 6, 4}, len = sizeof(a)/sizeof(int);
    BubbleSortASC(a, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
