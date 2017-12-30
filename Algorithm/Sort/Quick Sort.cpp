//1.��һ����׼��������ֳ�����������
//2.�����ڻ�׼�����Ƶ��ұߣ�С�ڵ��Ƶ����
//�ݹ�Ķ��������ظ�ִ��1��2��ֱ��������������

#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int>& nums, int b, int e, vector<int>& temp)
{
    int m = (b + e) / 2;
    if (m != b) {
        int lb = b, rb = e - 1;

        for (int i = b; i < e; i++) {
            if (i == m)
                continue;
            if (nums[i] < nums[m])
                temp[lb++] = nums[i];
            else
                temp[rb--] = nums[i];
        }
        temp[lb] = nums[m];

        for (int i = b; i < e; i++)
            nums[i] = temp[i];

        quick_sort(nums, b, lb-1, temp);
        quick_sort(nums, lb + 1, e, temp);
    }
}


int main(void)
{
	vector<int> ivec={3,2,5,8,4,7,6,9};
	vector<int> temp(8);

	quick_sort(ivec,0,7,temp);
	for(auto a:ivec)
		cout<<a<<" ";
    return 0;
}
