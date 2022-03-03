#define _CRT_SECURE_NO_WARNINGS 1
#include "Mult.h"

Polynomial* CreatPolynomial(int MaxPower)
{
	Polynomial* P = (Polynomial*)malloc(sizeof(Polynomial));
	assert(P);
	Polynomial* TempP1 = P;
	Polynomial* TempP2;
	int i;
	for (i = 0; i <= MaxPower; i++)
	{
		TempP2 = (Polynomial*)malloc(sizeof(Polynomial));
		assert(TempP2);
		TempP1->Next = TempP2;
		TempP1 = TempP2;
	}
	TempP1->Next = NULL;
	return P;
}

// 初始化
void InitPolynomial(Polynomial* Poly)
{
	while (Poly != NULL)
	{
		Poly->Coefficient = 0;
		Poly->Exponent = 0;
		Poly = Poly->Next;
	}
}

// +
Polynomial* AddPolynomial(Polynomial* Poly1, Polynomial* Poly2)
{
	// first
	int i;
	Polynomial* P = (Polynomial*)malloc(sizeof(Polynomial));
	assert(P);
	Polynomial* TempP1 = P;
	// Exponent 指数相同时，Coeddicient相加
	int MaxExponent = max(Poly1->Exponent, Poly2->Exponent);
	for (i = 0; i < MaxExponent; i++)
	{
		TempP1->Coefficient = Poly1->Coefficient + Poly2->Coefficient;
		assert(TempP1);
		// 申请空间
		Polynomial* TempP2 = (Polynomial*)malloc(sizeof(Polynomial));
		assert(TempP2);
		TempP1->Next = TempP2;
		TempP1 = TempP2;
		Poly1 = Poly1->Next;
		Poly2 = Poly2->Next;
	}
	return P;
}

// *
//Polynomial* MultPolynomial(Polynomial* Poly1, Polynomial* Poly2)
//{
//
//}


void PrintPolynomial(Polynomial* P, int MaxExponent)
{
	int flag = 1;
	while (P != NULL)
	{
		if (P->Coefficient == 0)
		{
			// 系数为0
			;
		}


		else if (P->Coefficient == 1)
		{
			// 系数为1
			if (P->Exponent != MaxExponent)
			{
				printf(" + ");
			}
			if (P->Exponent == 0)
			{
				// 指数为0
				printf("1");
			}
			else if (P->Exponent == 1)
			{
				// 指数为1
				printf("X");
			}
			else
			{
				printf("X^%d", P->Exponent);
			}
		}


		else
		{
			if (P->Coefficient > 0 && P->Exponent != MaxExponent)
			{
				printf(" + ");
			}
			else if(P->Coefficient < 0 && P->Exponent != MaxExponent)
			{
				printf(" - ");
			}
			if (P->Exponent == 0)
			{
				// 指数为0
				printf("%d", P->Coefficient);
			}
			else if (P->Exponent == 1)
			{
				// 指数为1
				printf("%dX", P->Coefficient);
			}
			else
			{
				printf("%dX^%d", P->Coefficient, P->Exponent);
			}
		}
		P = P->Next;
	}
	printf("\n");
}
