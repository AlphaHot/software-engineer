#include<iostream> 
#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}ElemSN;

ElemSN * CreatLink(int a[],int n)
{
	ElemSN *h=NULL,*newp,*t;
	for(int i=0;i<n;i++){
		newp=(ElemSN *)malloc(sizeof(ElemSN));
		newp->data=a[i];
		newp->next=NULL;
		if(!h)
			h=t=newp;
		else t=t->next=newp;
	}
	return h;
}

int CountNode(ElemSN *h){//ͳ�Ƶ�������Ľڵ���� 
	int cnt=0;
	while(h!=NULL){
		cnt++;
		h=h->next;	
	}
	return cnt;
} 
int Count_J_Node(ElemSN *h){
	int cnt=0;
	for(ElemSN *p=h;p;cnt+=p->data%2,p=p->next);
	return cnt;
}
int main(void){
	int a[8]={3,2,5,8,4,7,6,9};
	ElemSN *h=CreatLink(a,8);
	ElemSN *p=h; 
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	cout<<"�ڵ����Ϊ��"<<CountNode(h)<<endl;
	cout<<"������ֵΪ�����Ľڵ����Ϊ��"<<Count_J_Node(h)<<endl;
	return 0;
} 
