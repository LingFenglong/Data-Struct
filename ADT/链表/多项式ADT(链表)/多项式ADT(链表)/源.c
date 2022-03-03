#define _CRT_SECURE_NO_WARNINGS 1
#include "Mult.h"

int main()
{
	int i;
	Polynomial* Poly1 = CreatPolynomial(3);
	InitPolynomial(Poly1);

	Polynomial* Poly2 = CreatPolynomial(2);
	InitPolynomial(Poly2);
	
	// 第一个多项式	X^2 + 2X + 3
	Polynomial* TempP1 = Poly1;
	for (i = 1; i <= 3; i++)
	{
		TempP1->Coefficient = i;
		TempP1->Exponent = 3 - i;
		TempP1 = TempP1->Next;
	}

	// 第二个多项式
	Polynomial* TempP2 = Poly2;
	for (i = 0; i < 2; i++)
	{
		TempP2->Coefficient = i;
		TempP2->Exponent = 2 - i;
		TempP2 = TempP2->Next;
	}

	PrintPolynomial(Poly1, 2);
	PrintPolynomial(Poly2, 1);
	
	
	// 测试加法
	Polynomial* P = AddPolynomial(Poly1, Poly2);
	PrintPolynomial(P, 2);

	return 0;
}