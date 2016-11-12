/*************************************************************************
    > File Name: restart/select_sort.c
    > Author: ailly
    > Mail: ailly@fudan.com 
    > Created Time: 2016年10月19日 星期三 17时50分06秒
 ************************************************************************/

#include<stdio.h>

void SwapInt(int *a, int *b);
void SelectSort(int *L, int length);

int main(){
	int a[] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 100, 111, -50};
	SelectSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		printf("%d ", a[i]);
	return 0;
}

void SwapInt(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void SelectSort(int *L, int length){
	for (int i = 0; i < length - 1; i++){
		int min = i;
		for (int j = i + 1; j < length; j++){
			if (L[j] < L[min])
				min = j;
		}
		if (i != min)
			SwapInt(&L[i], &L[min]);
	}
}


