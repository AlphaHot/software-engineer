#include<iostream>
using namespace std;
//�ӿ�
class CPrototype
{
    public:
        int m_counter;
    public:
        CPrototype():m_counter(10){
            cout<<"CProtoType(){}"<<endl;
        }

        virtual ~CPrototype(){}

        virtual CPrototype* Clone() = 0;
};

//ʵ��
class CConcretePrototype : public CPrototype
{
//    private:
//        int m_counter;
    public:
    CConcretePrototype(){}

    //�������캯��
    CConcretePrototype(const CConcretePrototype& rhs)
    {
        m_counter = rhs.m_counter+1;
    }

    //��������
    CPrototype* Clone(){
        //���ÿ������캯��
        return new CConcretePrototype(*this);
    }
    ~CConcretePrototype(){}


};

int main(void)
{
    //���ɶ���
    CPrototype* conProA = new CConcretePrototype();
    //��������
    CPrototype* conProB = conProA->Clone();

    cout<<conProA->m_counter<<endl;
    cout<<conProB->m_counter<<endl;
    delete conProA; conProA=NULL;
    delete conProB; conProB=NULL;

    return 0;
}
