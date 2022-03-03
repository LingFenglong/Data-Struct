#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
struct Polynomial
{
	int Coefficient;	// ϵ��
	int Exponent;		// ָ��
	struct Polynomial* Next; 
};
// �Ӹ�λָ���λ

typedef struct Polynomial Polynomial;

// ��������ʽ
Polynomial* CreatPolynomial(int MaxPower);

// ��ʼ��Ϊ0
void InitPolynomial(Polynomial* Poly);

// ����ʽ�ӷ�
Polynomial* AddPolynomial(Polynomial* Poly1, Polynomial* Poly2);

// ����ʽ�˷�
Polynomial* MultPolynomial(Polynomial* Poly1, Polynomial* Poly2);

// ��ӡ����ʽ
void PrintPolynomial(Polynomial* Poly, int MaxExponent);
