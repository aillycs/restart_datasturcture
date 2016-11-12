/*************************************************************************
    > File Name: heap_sort.c
    > Author: ailly
    > Mail: ailly@fudan.com 
    > Created Time: 2016年10月15日 星期六 20时27分41秒
 ************************************************************************/

#include<stdio.h>

void SwapInt(int *a, int *b);
void BuildMaxHeap(int *L, int num);
void HeapSort(int *L, int num);
void MaxHeapify(int *L, int start, int end);

int main(){
	int a[] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 100, 110};
	int length = sizeof(a) / sizeof(int);
	HeapSort(a, length);
	for(int i = 0; i < length; i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

void HeapSort(int *L, int num){
	BuildMaxHeap(L, num);
	for (int i = num-1; i > 0; --i){
		SwapInt(&L[i], &L[0]);
		MaxHeapify(L,0,i);
	}
}

void BuildMaxHeap(int *L, int num){
	for (int i = (num/2)-1; i >= 0; --i)
		MaxHeapify(L, i, num);
}

void MaxHeapify(int *L, int start, int end){
	int lchild = 2 * start + 1;
	int rchild = 2 * start + 2;
	int largest;

	if (lchild <= end-1 && L[lchild] > L[start])
		largest = lchild;
	else
		largest = start;

	if (rchild <= end-1 && L[rchild] > L[largest])
		largest = rchild;

	if (largest != start){
		SwapInt(&L[start], &L[largest]);
		MaxHeapify(L, largest, end);
	}
}

void SwapInt(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
