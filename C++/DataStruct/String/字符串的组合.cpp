#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

void Combination(char *str)
{
	if(str == NULL)
		return ;
	int len = strlen(str);
	int n = 1<<len;
	for(int i=0;i<n;i++)    //�� 1 ѭ���� 2^len -1���մ����κ��ַ������Ӵ�
	{
		for(int j=0;j<len;j++)
		{
			int temp = i;
			if(temp & (1<<j)){   //��Ӧλ��Ϊ1���������Ӧ���ַ�
				printf("%c",*(str+j));
            }
		}
		printf("\n");
	}
}

int main(void)
{
	char str[] = "abc";
	Combination(str);
//	for(int i=0;i<3;i++){
//        cout<<str[i]<<endl;
//	}

	return 0;
}
