/*

   һ�����ͨ��
   		��һͨ��
		ָ��ͨ��
		�����ͨ�ţ������б�ͨ�ţ� 

	�����̳�ͨ�� 

*/ 
#include<iostream>
#include<vector>
using namespace std;

class A{
	private:
		int x;
	public:
		A(int x=0){
			this->x=x;
		} 
	void fun(){
		cout<<x<<endl;
	}
}; 

class B{
	private:
		vector<A> obj;
	public:
		void Add(A a){
			obj.push_back(a);
		}
		void out(){
			for(auto c:obj){
				c.fun();
			}
		}
};
int main(void)
{
	class B b;
	for(int i=0;i<5;i++){
		b.Add(A(i));
	}
	b.out();
	return 0;
}

