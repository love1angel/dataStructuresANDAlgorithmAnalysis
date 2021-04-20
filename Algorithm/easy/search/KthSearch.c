/*
 * @Author: xiepeng
 * @Email: xp1762638547@163.com
 * @Date: 2021-04-19 22:52:27
 * @LastEditTime: 2021-04-20 13:42:49
 * @Description: Kth search
 */
#include<stdio.h>
#include<stdlib.h>
#define ELEMENTTYPE int
void swap(ELEMENTTYPE *a, ELEMENTTYPE *b) {
    ELEMENTTYPE temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSortDESC(ELEMENTTYPE a[], int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = len-1; j > i; j--) {
            if (a[j] > a[j-1]) {
                swap(&a[j], &a[j-1]);
            }            
        }        
    }
}
void makeit(ELEMENTTYPE *knums, int len, ELEMENTTYPE value) {
    int i = 0;
    for (; i < len; i++) {
        if (knums[i] < value) {
            break;
        }        
    }
    for (int j = len-1; j > i; j--) {
        knums[j] = knums[j-1];
    }
    knums[i] = value;
}
ELEMENTTYPE KthSearch(ELEMENTTYPE a[], int len, int k) {
    ELEMENTTYPE *knums = (ELEMENTTYPE *)malloc(k*sizeof(ELEMENTTYPE));
    // 原数组必须大于 k ，暂时不讨论
    for (int i = 0; i < k; i++) {
        knums[i]  = a[i];
    }
    BubbleSortDESC(knums, k);
    for (int i = k; i < len; i++) {
        if (a[i] > knums[k-1]) {
            makeit(knums, k, a[i]);
        }        
    }
    return knums[k-1];
}
int main(int argc, char const *argv[]) {
    ELEMENTTYPE a[] = {5, 4, 2 ,6, 1, 8, 9};
    ELEMENTTYPE result = KthSearch(a, sizeof(a)/sizeof(ELEMENTTYPE), 3);
    printf("%d", result);
    return 0;
}
