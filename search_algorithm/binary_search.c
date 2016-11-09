/*************************************************************************
    > File Name: binary_search.c
    > Author: ailly
    > Mail: ailly@fudan.com 
    > Created Time: 2016年11月09日 星期三 20时14分39秒
 ************************************************************************/

#include<stdio.h>

int BinarySearch(int *a, int len, int key);

int main(){
	int a[] = {-10, 0, 1, 5, 7, 12, 30, 100, 543, 20234, 1000000};
	int key;
	while (scanf("%d",&key)){
		int index =  BinarySearch(a, 11, key);
		if (index != -1)
			printf("find key at %d\n", index);
		else
			printf("no such element\n");
	}
}



int BinarySearch(int *a, int len, int key){
	int low = 0;
	int high = len-1;
	int mid;
	while (low <= high){
		mid = (high + low) / 2;
		if (key > a[mid])
			low = mid + 1;
		else if (key < a[mid])
			high = mid - 1;
		else
			return mid;
	}
	return -1;	
}
