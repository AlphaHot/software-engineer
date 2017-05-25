#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/*
    ���Һ�ֵΪS���ҳ˻���С��������
*/

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int count=INT_MAX;
        vector<int> vec;
        auto beg=array.begin();
        auto end=array.end()-1;
        while(beg<end){

           if(*beg+*end>sum)
               end--;
           else if(*beg+*end<sum)
               beg++;
           else {
                if(*beg*(*end)<count){
                    count=*beg*(*end);
                    vec.clear();
                	vec.push_back(*beg);
               		vec.push_back(*end);
                }
                beg++;
                end--;
            }

        }
        return vec;

}
int main(void)
{
    vector<int> vec={1,2,3,4,5,6,7,8};

    vector<int> result=FindNumbersWithSum(vec,8);
    for(auto data:result)
        cout<<data<<"|";

    return 0;
}
