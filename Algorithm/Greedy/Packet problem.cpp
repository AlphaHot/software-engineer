#include<stdio.h>
#include<stdlib.h>
#define v 10
typedef struct {//������Ʒ�ṹ�� 
	int gno,gv;
}Goods;
typedef struct gnode{//������Ʒ���ṹ�� 
	int gno;
	struct gnode *link;
}Gnode;
typedef struct bnode{//�������ӽ��ṹ�� 
	int remainder;
	Gnode *hg;
	struct bnode *next;
}Bnode;
void SortD(Goods *g,int n)//�������ݽ������� 
{
	int i,j;
	Goods t;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(g[i].gv>g[j].gv){
				t=g[i];
				g[i]=g[j];
				g[j]=t;
			}
		}
	}
 } 
Bnode *CreatBnode(Goods *g,int n)
{
 	int i;
 	Bnode *hbox,*tb,*p;
 	Gnode *tg,*pg;
 	hbox=NULL;
	 
	 for(i=0;i<n;i++){
 		
	 	pg=tg=(Gnode *)malloc(sizeof(Gnode));//����0��n��Ʒ��� 
		pg->gno=g[i].gno;
		pg->link=NULL;
	
		for(p=hbox;p&&p->remainder<g[i].gv;p=p->next);//Ѱ�Ҳ���� 
		if(!p){
 			p=(Bnode *)malloc(sizeof(Bnode));
 			p->remainder=v;
 			p->hg=pg;
			p->next=NULL;
			if(!hbox)	hbox=tb=p;	
			else tb=tb->next=p;
		}
		else {
			for(tg=p->hg;tg->link;tg=tg->link);
			tg->link=pg; 
		 }
		p->remainder-=g[i].gv; 			
	}
	return hbox;
 }
 int main(void)
 {
	int i,n,x;
	Goods *g;
	Gnode *G;
	Bnode *B,*c;
	printf("��������Ʒ����n,�Լ��������\n");
	scanf("%d",&n);
	g=(Goods *)malloc(n*sizeof(Goods));
	for(i=0;i<n;i++){
		g[i].gno=i+1;
		scanf("%d",&g[i].gv);
	}
	SortD(g,n);
	for(i=0;i<n;i++) printf("%5d%5d\n",g[i].gno,g[i].gv);
	B=CreatBnode(g,n);
	i=0;
	for(c=B;c;c=c->next){
		printf("��%d�����ӣ�",++i);
		for(G=c->hg;G;G=G->link) printf("%3d",G->gno);
		printf("\n");
	} 
	return 0;
 }
