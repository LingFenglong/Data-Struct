#define _CRT_SECURE_NO_WARNINGS 1
#include "Polynomial.h"

// ��ʼ��Ϊ0;
void InitPolynomial(Polynomial Poly)
{
	int i;
	for (i = 0; i < MaxDegree + 1; i++)
	{
		Poly->CoeffArry[i] = 0;
	}
	Poly->HighPower = 0;
}

// ��ӡ
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

// ����ʽ�ӷ�
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

// ����ʽ�˷�
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
			// i, j	��i, j���power
			// P->CoeffArry[i+j] Ҫ�������ݵ��±�
			P->CoeffArry[i + j] += Poly1->CoeffArry[i] * Poly2->CoeffArry[j];
		}
	}
	return P;
}

