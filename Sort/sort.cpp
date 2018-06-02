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

#define MAXSIZE 1000      //要排序数组的大小
typedef struct SqList     //
{
	int r[MAXSIZE];       //r[0] 作为临时结点或者哨兵结点 
	int length;
}SqList;

//用以交换两个数组下标为i和j的值
void swap(SqList *L, int i, int j)
{
	int tmp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = tmp;
}

void print(SqList L)
{
	for (int i = 1; i <= L.length; ++i)
	{
		printf("%d ", L.r[i]);
	}
	printf("\n");
}

//对顺序表L做交换排序（冒泡排序初级版,民科版）
//思想就是普通的思想，依次拿一个元素去与剩余的元素进行比较
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
//对顺序表L做交换排序（冒泡排序初级版,正宗版）
//从底向高处两两进行比较，每一次循环冒出一个数，
void BubbleSort_v1(SqList *L)
{
	for (int i = 1; i < L->length; ++i) //只用冒出n - 1个，最后一个不用冒出
	{
		for (int j = L->length - 1; j >= i; --j) //当然是要用新冒出的值去与已排序的最后一个元素比较
		{
			if (L->r[j] > L->r[j + 1])
				swap(L, j, j + 1);
		}
	}
}
//对顺序表L做交换排序（冒泡排序升级版，加入了标志位，避免不必要的重排序）
//加入标志位，相当于对一次外循环进行与运算，如果都没有进行交换，这说明原序列有序；
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

//简单选择排序
//思想就是减少swap()的数量，每次循环找出最小数值的下标，更新的是下标，而不是每一次的交换；
void selectSort(SqList *L)
{
	for (int i = 1; i < L->length; ++i)
	{
		int min = i;
		for (int j = i + 1; j <= L->length; ++j)
		{
			if (L->r[min] > L->r[j])
			{
				min = j;
			}
		}
		if (i != min)     //如果不相等，则代表找到
			swap(L, i, min);
	}
}

//直接插入排序
//
void InsertSort(SqList *L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i]<L->r[i - 1]) /* 需将L->r[i]插入有序子表 */
		{
			L->r[0] = L->r[i]; /* 设置哨兵 */
			for (j = i - 1; L->r[j]>L->r[0]; j--)
				L->r[j + 1] = L->r[j]; /* 记录后移 */
			L->r[j + 1] = L->r[0]; /* 插入到正确位置 */
		}
	}
}
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

	//BubbleSort_v0(&L);
	//print(L);
	//BubbleSort_v1(&L);
	//print(L);
	//BubbleSort_v2(&L);
	//print(L);
	InsertSort(&L);
	print(L);
	system("pause");

	return 0;
}





