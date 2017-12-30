#include<iostream >
#include<deque>
#include<vector>
#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *left,*right;
}BTnode;

BTnode * CreateBTree(int a[],int n){
	BTnode *root,*p,*c,*pa;
	root=(BTnode *)malloc(sizeof(BTnode));
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){
		p=(BTnode *)malloc(sizeof(BTnode));
		p->data=a[i];
		p->left=p->right=NULL;
		c=root;
		while(c-NULL){//Ѱ��Ӧ�ò����λ��
			pa=c;
			if(c->data>p->data) c=c->left;
			else c=c->right;
		}
		if(pa->data>p->data) pa->left=p;//�жϲ�������
		else pa->right=p;
	}
	return root;
}

//ǰ�����

void Forder(BTnode *root){
	if(root){
		cout<<root->data<<" ";
		Forder(root->left);
		Forder(root->right);
	}
}

void Inorder(BTnode *root){
	if(root){
		Forder(root->left);
		cout<<root->data<<" ";
		Forder(root->right);
	}
}

void Horder(BTnode *root){
	if(root){
		Horder(root->left);
		Horder(root->right);
		cout<<root->data<<" ";
	}
}
void MirrorRecursively(BTnode* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
        return;
    BTnode *temp=root->left;
    root->left=root->right;
    root->right=temp;

    if(root->left)
        MirrorRecursively(root->left);

    if(root->right)
        MirrorRecursively(root->right);
}

vector<int> PrintFromTopToBottom(BTnode *root) {

		deque<BTnode* > data;
        data.push_back(root);
        vector<int> vec;

        while(data.size()){
            BTnode* node=data.front();
            data.pop_front();
            vec.push_back(node->data);

            if(node->right)
                data.push_back(node->right);
            if(node->left)
                data.push_back(node->left);

        }
        return vec;
    }

int main(void){
	BTnode *root;
	int numbers[8]={3,2,5,8,4,7,6,9};
	root=CreateBTree(numbers,8);
	cout<<"ǰ�����: "<<endl;
	Forder(root);

	cout<<endl<<"���������"<<endl;
	Inorder(root);

	cout<<endl<<"��������: "<<endl;
	Horder(root);

	MirrorRecursively(root);
	cout<<endl<<"Mirror Tree ��ǰ������� "<<endl;
	Forder(root);

    cout<<endl<<"���������"<<endl;
	vector<int> vecint=PrintFromTopToBottom(root);
	for(auto i:vecint)
        cout<<i<<" ";
	return 0;
}
