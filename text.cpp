#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,* Linklist;        
LNode * Getlist();           //��������
LNode * delElem(Linklist);   //ɾ����� 
LNode * insElem(Linklist);   //������ 
void findElem(Linklist);   //���ҽ�� 
void Printflist(Linklist);   //����ÿ����㲢���ֵ  
int main() {
	Linklist head=Getlist();
	Printflist(head);
	head=delElem(head);
	Printflist(head);
	head=insElem(head);
	Printflist(head);
	findElem(head);
	return 0;
}	
LNode * Getlist(){
	Linklist p,h,d;;
	d = (Linklist)malloc(sizeof(LNode));
	p = d;
	printf("����Ҫ�洢������Ԫ�أ�"); 
	for (int i = 0; i < 10; i++) { 
		h = (Linklist)malloc(sizeof(LNode));
		scanf("%d",&(h->data));
		h->next =NULL;
		p->next = h;
		p = p->next;
	}	
	return d;
}
LNode * delElem(Linklist p){
	int a;
	printf("\n����Ҫɾ���Ľ�㣺");
	scanf("%d",&a); 
	Linklist t=p;
	for (int i=1; i<a; i++) {
		if(t->next==NULL){
			printf("ɾ��λ����Ч\n");
			return p;
		}
		t=t->next;
	}
	Linklist del = t->next;
	t->next = del->next;
	free(del);
	return p;
}
LNode * insElem(Linklist p){
	int a,x;
	printf("\n����Ҫ����Ľ��ֵ��λ��(�ո����)��");
	scanf("%d",&x);
	scanf("%d",&a);
    Linklist t = p;
    for (int i=1; i<a; i++) {
		if(t->next==NULL){
			printf("����λ����Ч\n");
			return p;
		}
		t=t->next;
	}
	Linklist c;
	c->data=x;
	c->next=t->next;
	t->next=c;
	return p;
}
void findElem(Linklist p){
	int x,i;
	printf("\n����Ҫ���ҵ�Ԫ�أ�");
	scanf("%d",&x);
	Linklist t=p;
	for (i=0;t->data!=x;i++){
		if(t->next==NULL){
			printf("����ʧ�ܣ��޸�Ԫ��\n");
		}
		t=t->next; 
	}
	printf("%dλ�ڵ�%d������������",x,i);
}
void Printflist(Linklist p){
	printf("������ڵ�Ԫ��ֵ��"); 
	Linklist L=p->next;
	while(L){	
	printf("%d   ", (L->data));
	L=L->next;
	}
} 

