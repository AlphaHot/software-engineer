#include<iostream>
using namespace std;

bool VerifySequenceBST(int sequence[],int length)
{
    if(sequence==NULL||length<=0)
        return false;

    int root=sequence[length-1];

    //ȷ����������Χ;
    int i=0;
    for(;i<length-1;++i){
        if(sequence[i]>root)
            break;
    }

    //�ж��������Ƿ����㶼����root
    for(int j=i;j<length-1;j++){
        if(sequence[j]<root)
            return false;
    }
    //�ж��������ǲ��Ƕ���������
    bool left=true;
    if(i>0)
        left=VerifySequenceBST(sequence,i);
    //
    bool right=true;
    if(i<length-1)
        right=VerifySequenceBST(sequence+i,length-i-1);

    return (left&&right);
}

int main(void)
{
    int a[6]={6,7,6,9,10,8};
    bool result=VerifySequenceBST(a,6);
    cout<<(result==1?"Yes, it's sequence Of BST":"No,it's not.")<<endl;
    return 0;
}
