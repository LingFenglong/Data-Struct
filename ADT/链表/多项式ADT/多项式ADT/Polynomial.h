#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MaxDegree 3

typedef struct Polynomial
{
	int CoeffArry[MaxDegree + 1];
	// 系数的数组，左边为低位
	int HighPower;
	// 最高次数
}* Polynomial;

#ifndef _Polynomial_H_

//typedef struct Polynomial* Polynomial;

// 多项式加法
Polynomial AddPolynomial(const Polynomial const Poly1, const Polynomial const Poly2);

// 初始化为0;
void InitPolynomial(Polynomial Poly);

// 多项式乘法
Polynomial MultPolynomial(const Polynomial const Poly1, const Polynomial const Poly2, Polynomial P);

// 打印
void PrintPolynomial(Polynomial P);
#endif
