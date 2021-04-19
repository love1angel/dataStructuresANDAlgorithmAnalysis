/*
 * @Author: xiepeng
 * @Email: xp1762638547@163.com
 * @Date: 2021-04-18 00:41:08
 * @LastEditTime: 2021-04-18 01:01:01
 * @Description: 一元多项式求前 n 项和利用秦九韶算法优化
 */
#include<stdio.h>
#define CoefficientType double

// 利用秦九韶算法减少乘法次数，优化算法速度一个量级
CoefficientType SumofPolynomial(CoefficientType x, int N, const CoefficientType a[]) {
    CoefficientType sum = a[N];
    for (int i = N; i > 0; i--) {
        sum = a[i-1] + x * sum;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    CoefficientType a[] = {1, 2, 3};
    CoefficientType sum = SumofPolynomial(2.0, 2, a);
    printf("%lf", sum);
    return 0;
}
