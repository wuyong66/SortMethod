#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

#define MAXSIZE 1000      //Ҫ��������Ĵ�С
typedef struct SqList     //
{
	int r[MAXSIZE];       //r[0] ��Ϊ��ʱ�������ڱ���� 
	int length;
}SqList;

//���Խ������������±�Ϊi��j��ֵ
void swap(SqList *L, int i, int j)
{
	int tmp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = tmp;
}

void print(SqList L)
{
	for (int i = 1; i < L.length + 1; ++i)
	{
		printf("%d ", L.r[i]);
	}
	printf("\n");
}

//��˳���L����������ð�����������,��ư棩
void BubbleSort_v0(SqList *L)
{
	for (int i = 1; i <= L->length; ++i)
	{
		for (int j = i + 1; j <= L->length; ++j)
		{
			if (L->r[i] > L->r[j])
			{
				swap(L, i, j);
			}
		}
	}
}
//��˳���L����������ð�����������,���ڰ棩
void BubbleSort_v1(SqList *L)
{
	for (int i = 1; i < L->length; ++i) //ֻ��ð��n - 1�������һ������ð��
	{
		for (int j = L->length - 1; j >= i; --j) //��Ȼ��Ҫ����ð����ֵȥ������������һ��Ԫ�رȽ�
		{
			if (L->r[j] > L->r[j + 1])
				swap(L, j, j + 1);
		}
	}
}
//��˳���L����������ð�����������棬�����˱�־λ�����ⲻ��Ҫ��������
void BubbleSort_v2(SqList *L)
{
	Status flag = TRUE;
	for (int i = 1; i < L->length && flag; ++i)
	{
		flag = FALSE;
		for (int j = L->length - 1; j >= i; --j)
		{
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				flag = TRUE;
			}
		}
	}
}

//��ѡ������
int main()
{
	SqList L;
	L.length = 5;
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 5; ++i)
	{
		L.r[i] = rand() % 10 + 1;
	}
	print(L);
	BubbleSort_v0(&L);
	print(L);
	BubbleSort_v1(&L);
	print(L);
	BubbleSort_v2(&L);
	print(L);
	system("pause");

	return 0;
}





