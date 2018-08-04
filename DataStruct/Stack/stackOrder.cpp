#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsOrder(int *pPush,int *pPop,int Length)
{
    bool isStack=false;
    const int* pNewPush=pPush;
    const int* pNewPop=pPop;

    stack<int> dataStack;
    if(pPush!=NULL&&pPop!=NULL&&Length>0){
        while(pNewPop-pPop<Length){
            //������ջʱ�����ʱ�����ѭ��
            while(dataStack.empty()||dataStack.top()!=*pNewPop){
                if(pNewPush-pPush!=Length){
                    dataStack.push(*pNewPush);
                    pNewPush++;
                }else{
                    break;
                }
            }
            //�ж�ʱ����ջ�������
            if(dataStack.top()==*pNewPop){
                dataStack.pop();
                pNewPop++;
            }else{
                break;
            }
        }
        //�ɹ�ʱջΪ�ղ��ҳ�ջ���
        if(dataStack.empty()&&pNewPop-pPop==Length)
            isStack=true;
    }
    return isStack;

}

bool isPopOrder(const vector<int> &pushV, const vector<int> &popV) {
    if (pushV.size() == 0)
        return false;

    stack<int> stk;
    int i, j;
    for (i = 0, j = 0; i < pushV.size();) {
        stk.push(pushV[i++]);
        // when stack empty, top() is undefined
        while (j < popV.size() && !stk.empty() && stk.top() == popV[j]) {
            stk.pop();
            ++j;
        }
    }
    return stk.empty() && j == popV.size();
}


int main(void){

    int pPush[5]={1,2,3,4,5};
    int pPop[5]={3,4,2,1,5};
    int pPop2[5]={3,1,2,4,5};

    vector<int> push={1,2,3,4,5};
    vector<int> pop={5,4,3,2,1,6,7,8};

    cout<< "result: " << isPopOrder(push,pop)<<endl;
    return 0;
}
