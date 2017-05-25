#include<iostream>
#include<cstring>
#include<string>
using namespace std;

/*
����Ҫ��:

1.���ȳ���8λ

2.������Сд��ĸ.����.��������,����������������

3.��������ͬ���ȳ�2���Ӵ��ظ�

˵��:���ȳ���2���Ӵ�
*/

bool checkPassword(string p)
{
    int len=p.size();
    if(len<8)
        return false;

    int a[4]={0};
    int count=0;
    for(int i=0;i<len;i++){
        if(p[i]>='A'&&p[i]<='Z')
            a[0]=1;
        else if(p[i]>='a'&&p[i]<='z')
            a[1]=1;
        else if(p[i]>='0'&&p[i]<='9')
            a[2]=1;
        else
            a[3]=1;
        count=0;
        for(auto t:a){
            count+=a[t];
        }
        if(count>=3)
            break;
    }
    if(count<3)
        return false;

    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(p[i]==p[j]&&p[j]==p[j+1])
                return false;
        }
    }

    return true;
}

int main(void)
{
    string p;
    bool result;
    while(getline(cin,p)){
        result=checkPassword(p);
        if(result)
            cout<<"OK"<<endl;
        else
            cout<<"NG"<<endl;
    }

    return 0;
}
