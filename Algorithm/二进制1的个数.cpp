#include<iostream>
using namespace std;

/*
�����n�Ķ�������1�ĸ���һ��������ӽ�������

*/

int getNext(int n){
    int c=n;
    int c0=0;
    int c1=0;
//
    while((c&1)==0&&(c!=0)){
        c0++;
        c>>=1;
    }

    while((c&1)==1){
        c1++;
        c>>=1;
    }

    if(c0+c1==31||c0+c1==0)//c0+c1+1=32,1��ʾp����λ��
        return -1;

    int p=c0+c1;//���ұߴ�������β0��λ�á�
    n|=(1<<p);//��ת0Ϊ1
    n&=~((1<<p)-1);//��p�ұߵ�����λ����
    n|=(1<<(c1-1))-1;//���ұ����루c1-1����1

    return n;
}

int main(void)
{
    int n;
    cin>>n;
    cout<<getNext(n)<<endl;

    return 0;
}
