/*************************************************************************
    > File Name: insertion_sort.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年10月20日 星期四 21时51分09秒
 ************************************************************************/

#include<stdio.h>

void InsertionSort(int *L, int length);

int main(){
	int a[] = {0, 10, 50, -8, 20, 11, 99, 100};
	
	InsertionSort(a, 7);

	for (int i = 0; i < 7; ++i)
		printf("%d ", a[i]);
}

void InsertionSort(int *L, int length){
	for (int i = 1; i < length; i++){
		if (L[i] < L[i - 1]){
			int key  = L[i];
			int j;
			for (j = i - 1; L[j] > key && j >= 0; j--)
				L[j + 1] = L[j];
			L[j + 1] = key;
		}
	}
}

