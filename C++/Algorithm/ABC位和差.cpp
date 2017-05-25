#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;

/*

����A-B������λ����֮����C����λ����֮�͵Ĳ�ֵ��С�����֣����ж�������С�ġ�
*/

int search(int a,int b,int c)
{
    int min=0;
    int result=INT_MAX;
    int cSum=0;
    int sum=0;

    while(c){
        cSum+=c%10;
        c/=10;
    }

    int cur=0;
    for(int i=a;i<=b;i++){
        sum=0;
        int temp=i;
        while(temp){
            sum+=temp%10;
            temp/=10;
        }

        min=abs(sum-cSum);
        if(min<result){
            cur=i;
            result=min;
        }
        else
            break;
    }
    return cur;
}

int main(void)
{
    int a,b,c;
    cin>>a>>b>>c;
    int reuslt=search(a,b,c);
    cout<<reuslt<<endl;
    return 0;
}
