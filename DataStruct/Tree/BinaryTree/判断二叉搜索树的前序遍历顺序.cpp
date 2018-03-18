#include<iostream>
using namespace std;

bool VerifySequenceAST(int sequence[],int length)
{
    if(sequence==NULL||length<=0)
        return false;

    int root=sequence[0];

    //ȷ����������Χ;
    int i=1;
    for(;i<length;++i){
        if(sequence[i]>root)
            break;
    }

    //�ж��������Ƿ����㶼����root
    for(int j=i;j<length;j++){
        if(sequence[j]<root)
            return false;
    }
    //�ж��������ǲ��Ƕ���������
    bool left=true;
    if(i>1)
        left=VerifySequenceAST(sequence+1,i-1);
    //
    bool right=true;
    if(i<length)
        right=VerifySequenceAST(sequence+i,length-i);

    return (left&&right);
}

int main(void)
{
    int a[7]={8,6,5,7,10,9,11};
    bool result=VerifySequenceAST(a,7);
    cout<<(result==1?"Yes, it's sequence Of AST":"No,it's not.")<<endl;
    return 0;
}
