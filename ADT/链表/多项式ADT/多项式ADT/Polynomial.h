#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MaxDegree 3

typedef struct Polynomial
{
	int CoeffArry[MaxDegree + 1];
	// ϵ�������飬���Ϊ��λ
	int HighPower;
	// ��ߴ���
}* Polynomial;

#ifndef _Polynomial_H_

//typedef struct Polynomial* Polynomial;

// ����ʽ�ӷ�
Polynomial AddPolynomial(const Polynomial const Poly1, const Polynomial const Poly2);

// ��ʼ��Ϊ0;
void InitPolynomial(Polynomial Poly);

// ����ʽ�˷�
Polynomial MultPolynomial(const Polynomial const Poly1, const Polynomial const Poly2, Polynomial P);

// ��ӡ
void PrintPolynomial(Polynomial P);
#endif
