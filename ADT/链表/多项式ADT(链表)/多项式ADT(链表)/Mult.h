#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
struct Polynomial
{
	int Coefficient;	// 系数
	int Exponent;		// 指数
	struct Polynomial* Next; 
};
// 从高位指向低位

typedef struct Polynomial Polynomial;

// 创建多项式
Polynomial* CreatPolynomial(int MaxPower);

// 初始化为0
void InitPolynomial(Polynomial* Poly);

// 多项式加法
Polynomial* AddPolynomial(Polynomial* Poly1, Polynomial* Poly2);

// 多项式乘法
Polynomial* MultPolynomial(Polynomial* Poly1, Polynomial* Poly2);

// 打印多项式
void PrintPolynomial(Polynomial* Poly, int MaxExponent);
