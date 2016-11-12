/*************************************************************************
    > File Name: restart/bubble_sort.c
    > Author: ailly
    > Mail: ailly@fudan.com 
    > Created Time: 2016年10月19日 星期三 16时04分22秒
 ************************************************************************/

#include<stdio.h>

void BubbleSort (int *L, int length);
void SwapInt (int *a , int *b);

int main(){
	int a[] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 100, 111, -50};
	BubbleSort(a ,sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		printf("%d ",a[i]);
	return 0;
}

void BubbleSort(int *L, int length){
	int flag = 1;
	for (int i = 0; i < length - 1 && flag; i++){
		flag = 0;
		for (int j = length - 2; j >= i; j--){
			if (L[j] >  L[j+1])
				SwapInt(&L[j], &L[j+1]);
				flag = 1;
		}
	}
}

void SwapInt(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
