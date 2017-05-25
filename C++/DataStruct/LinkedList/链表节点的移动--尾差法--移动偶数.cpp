#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}ElemSN;

ElemSN *CreatLink(int *a,int n){
	ElemSN *h=NULL,*newp,*t;
	for(int i=0;i<n;i++){
		newp=(ElemSN *)malloc(sizeof(ElemSN));
		newp->data=a[i];
		newp->next=NULL;
		if(!h) h=t=newp;
		else t=t->next=newp;
	}
	return h;
}

ElemSN *MoveOddNode(ElemSN *h){//�����ڵ��ƶ���ż���ڵ�֮ǰ
	ElemSN *p,*q,*end,*t,*Del;
	for(t=h;t->next;t=t->next);
	end=t;//���ø���
	while(p-end){
		if(p->data%2){
			q=p;
			p=p->next;
		}
		else {
			Del=p;
			if(p==h) h=p=h->next;
			else q->next=p=p->next;
			Del->next=NULL;
			t=t->next=Del;
		}
	}
	return h;
}

int main(void){
	int a[8]={3,2,5,8,4,7,6,9};
	ElemSN *h=CreatLink(a,8);
	ElemSN *d=MoveOddNode(h);
	while(d){
		cout<<d->data<<" ";
		d=d->next;
	}
	return 0;
}
