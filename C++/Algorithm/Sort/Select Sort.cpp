//����ʼ��ѡ�����Ԫ������Сֵ��������Ԫ�ؽ���
//�ӵ�ǰ�ѽ���λ������ִ�У�ֱ�����һ��Ԫ��

#include<iostream>
using namespace std;

void selection_sort(int nums[],int n)
{
    for (int i = 0; i < n; i++) { // position
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}

int main(void)
{
	int a[]={3,2,5,8,4,7,6,9};
	selection_sort(a,8);
	for(int i=0;i<8;i++)
    	cout<<a[i]<<" ";
	
	
	return 0;	
} 
