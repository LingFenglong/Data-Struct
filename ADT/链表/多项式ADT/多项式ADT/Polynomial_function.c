#define _CRT_SECURE_NO_WARNINGS 1
#include "Polynomial.h"

// 初始化为0;
void InitPolynomial(Polynomial Poly)
{
	int i;
	for (i = 0; i < MaxDegree + 1; i++)
	{
		Poly->CoeffArry[i] = 0;
	}
	Poly->HighPower = 0;
}

// 打印
void PrintPolynomial(Polynomial P)
{
	int i;
	for (i = P->HighPower; i >= 0; i--)
	{
		if (i == P->HighPower)
		{

			printf("%dx^%d ", P->CoeffArry[i], i);
		}


		else if (i == 0)
		{
			if (P->CoeffArry[i] > 0)
			{
				printf("+%d", P->CoeffArry[i]);
			}
			else if (P->CoeffArry[i] < 0)
			{
				printf("%d", P->CoeffArry[i]);
			}
		}


		else if (i == 1)
		{
			if (P->CoeffArry[i] > 0)
			{
				printf("+%dx", P->CoeffArry[i]);
			}
			else if (P->CoeffArry[i] < 0)
			{
				printf("%dx", P->CoeffArry[i]);
			}
		}


		else
		{
			if (P->CoeffArry[i] > 0)
			{
				printf("+%dx^%d", P->CoeffArry[i], i);
			}
			else if (P->CoeffArry[i] < 0)
			{
				printf("%dx^%d", P->CoeffArry[i], i);
			}
		}
	}
	printf("\n");
}

// 多项式加法
Polynomial AddPolynomial(const Polynomial const Poly1, const Polynomial const Poly2)
{
	Polynomial P = (Polynomial)malloc(sizeof(struct Polynomial));
	assert(P);
	int i;
	P->HighPower = max(Poly1->HighPower, Poly2->HighPower);
	for (i = 0; i < P->HighPower + 1; i++)
	{
		P->CoeffArry[i] = Poly1->CoeffArry[i] + Poly2->CoeffArry[i];
	}
	return P;
}

// 多项式乘法
Polynomial MultPolynomial(const Polynomial const Poly1, const Polynomial const Poly2, Polynomial P)
{
	int i, j;
	assert(P);
	P->HighPower = Poly1->HighPower + Poly2->HighPower;
	InitPolynomial(P);
	for (i = 0; i <= Poly1->HighPower; i++)
	{
		for (j = 0; j <= Poly2->HighPower; j++)
		{
			// i, j	第i, j项的power
			// P->CoeffArry[i+j] 要放入数据的下标
			P->CoeffArry[i + j] += Poly1->CoeffArry[i] * Poly2->CoeffArry[j];
		}
	}
	return P;
}

