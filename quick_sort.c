/*************************************************************************
    > File Name: quick_sort.c
    > Author: ailly
    > Mail: ailly@fudan.com
    > Created Time: 2016年10月16日 星期日 20时20分14秒
 ************************************************************************/

#include<stdio.h>

void swap(int *a, int *b);	
void QuickSort(int *L, int length);
void QSort(int *L, int low, int high);
void QSort1(int *L, int low, int high);
int Partition(int *L, int low, int high);
int Partition2(int *L, int low, int high);
int Partition3(int *L, int low, int high);


int main(){
	int a[] = {50, 10, 90, 30, 70, 40, 80, 60, 20, 100, 110};

	QuickSort(a, sizeof(a) / sizeof(int));
	for(int i = 0; i < 11; i++){
		printf("%d ",a[i]);
	}

	return 0;
}


void QuickSort(int L[], int length){
	QSort1(L, 0, length-1);
}

void QSort(int *L, int low, int high){
	if (low < high){
		int pivot = Partition3(L, low, high);
		QSort(L, low, pivot - 1);
		//QSort(L, pivot + 1, high);

	}
}

// optimize recursion
void QSort1(int *L, int low, int high){
	while(low < high){
		int pivot =  Partition(L, low, high);
		QSort(L, low, pivot);
		low = pivot + 1;
	}
}

// datastucture - style
int Partition(int *L, int low, int high){
	int pivotkey = L[low];
	//optimize the selection of pivotkey: find the median of three numbers
	while (low < high){
        while (low < high && L[high] >= pivotkey)
			high--;
        L[low] = L[high];
		while (low < high && L[low] <= pivotkey)
			low++;
		L[high] = L[low];
	}
    L[low] =  pivotkey;
	return low;
}

// intro to algo - cs - style
int Partition2(int *L, int low, int high){
	int pivotkey = L[high];
	int j = low;
	int i = j - 1;
	while (j < high){
		if (L[j] > pivotkey)
			++j;
		else {
			swap(&L[j], &L[++i]);
			++j;
		}
	}
	swap(&L[high], &L[++i]);

	return i;
}

// intro to algo - style
int Partition3(int* L, int low, int high){
	int pivotkey = L[high];
	int i = low;
	for (int j = low; j < high; ++j){
		if (L[j] < pivotkey)
			swap(&L[j], &L[i++]);
	}
	swap(&L[high], &L[i]);
	return i;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}



