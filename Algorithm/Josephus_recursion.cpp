#include<iostream>
using namespace std;

void Josphus_Ring(int *Q,int n,int s)
{
	int frant=0,real=n;
	while(frant-real){
		for(int i=0;i<s-1;i++){//���� s-1 ��
			frant=(frant+1)%n;//ÿ��ǰ��һ����ֱ�� s-1 ��
			real=(real+1)%n; //real ͬ��ǰ��
			Q[real]=Q[frant];//���� frant ���ߵ�ÿһ��
		}
		frant=(frant+1)%n;// �ߵ��� s ��
		cout<<Q[frant]<<" "; //�� s �����
	}
 }

int main(void)
{
	int *Q;
	int n,s;
	cin>>n>>s;
	Q=(int *)malloc((n+1)*sizeof(int));
	for(int i=1;i<n+1;i++)
		Q[i]=i;
    Q[0]=n;// %n ֻ�ܵõ�0��n-1 �Ľ����Q[0]��Ҫ������ʼ��
	Josphus_Ring(Q,n,s);
	return 0;
}
