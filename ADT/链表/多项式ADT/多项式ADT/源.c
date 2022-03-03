#define _CRT_SECURE_NO_WARNINGS 1
#include "Polynomial.h"

int main()
{
	Polynomial Poly1 = (Polynomial)malloc(sizeof(struct Polynomial));
	Polynomial Poly2 = (Polynomial)malloc(sizeof(struct Polynomial));
	assert(Poly1);
	assert(Poly2);
	// Poly1  8x^3 + 4x^2 + 999x^1 + 188
	Poly1->CoeffArry[0] = 188;
	Poly1->CoeffArry[1] = 999;
	Poly1->CoeffArry[2] = 4;
	Poly1->CoeffArry[3] = 8;
	Poly1->HighPower = 3;

	Poly2->CoeffArry[0] = 1;
	Poly2->CoeffArry[1] = 1;
	Poly2->CoeffArry[2] = 1;
	Poly2->CoeffArry[3] = 1;
	Poly2->HighPower = 3;

	//PrintPolynomial(Poly1);
	//PrintPolynomial(Poly2);
	//// ¼Ó·¨
	//Polynomial Poly3 = AddPolynomial(Poly1, Poly2);
	//PrintPolynomial(Poly3);

	MultPolynomial(Poly1, Poly2, P);

	return 0;
}