#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,* Linklist;        
LNode * Getlist();           //创建链表
LNode * delElem(Linklist);   //删除结点 
LNode * insElem(Linklist);   //插入结点 
void findElem(Linklist);   //查找结点 
void Printflist(Linklist);   //访问每个结点并输出值  
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
	printf("输入要存储的链表元素："); 
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
	printf("\n输入要删除的结点：");
	scanf("%d",&a); 
	Linklist t=p;
	for (int i=1; i<a; i++) {
		if(t->next==NULL){
			printf("删除位置无效\n");
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
	printf("\n输入要插入的结点值和位置(空格隔开)：");
	scanf("%d",&x);
	scanf("%d",&a);
    Linklist t = p;
    for (int i=1; i<a; i++) {
		if(t->next==NULL){
			printf("插入位置无效\n");
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
	printf("\n输入要查找的元素：");
	scanf("%d",&x);
	Linklist t=p;
	for (i=0;t->data!=x;i++){
		if(t->next==NULL){
			printf("查找失败，无该元素\n");
		}
		t=t->next; 
	}
	printf("%d位于第%d个结点的数据域",x,i);
}
void Printflist(Linklist p){
	printf("链表各节点元素值："); 
	Linklist L=p->next;
	while(L){	
	printf("%d   ", (L->data));
	L=L->next;
	}
} 

