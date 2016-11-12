/*************************************************************************
    > File Name: binary_search_tree.c
    > Author: lyx
    > Mail: lyx@163.com 
    > Created Time: 2016年11月12日 星期六 18时35分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


int SearchBST(BiTree T, int key, BiTree f, BiTree *p);
int InsertBST(BiTree *T, int key);
int DeleteBST(BiTree *T, int key);
int DeleteNode(BiTree *p);
void InOrderTraverse(BiTree T);


int main(){
	BiTree bst;
	int status = InsertBST(&bst, 5);
	printf("%d ", status);
	//InOrderTraverse(bst);

}

void InOrderTraverse(BiTree T){
	printf("in");
	if (!T)
		return;
	InOrderTraverse(T->lchild);
	printf("%d ", T->data);
	InOrderTraverse(T->rchild);
}

int SearchBST(BiTree T, int key, BiTree f, BiTree *p){
	if (!T){
		*p = f;
		return 0;
	} else if (key == T->data){
		*p = T;
		return 1;
	} else if (key < T->data)
		return SearchBST(T->lchild, key, T, p);
	else
		return SearchBST(T->rchild, key, T, p);
}

int InsertBST(BiTree *T, int key){
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)){
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return 1;
	}
	return 0;
}

int DeleteBST(BiTree *T, int key){
	if (!*T)
		return 0;
	else{
		if (key == (*T)->data)
			return DeleteNode(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}

int DeleteNode(BiTree *p){
	BiTree q, s;
	if ((*p)->rchild == NULL){
		q = *p;
		*p = (*p)->lchild;
		free(q);
	} else if ((*p)->lchild == NULL){
		q = *p;
		*p = (*p)->rchild; 
		free(q);
	} else {
		q = *p;
		s = (*p)->lchild;
		while (s->rchild){
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return 1;
}
