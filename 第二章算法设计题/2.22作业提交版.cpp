#include<stdio.h>
#include<cstdlib>
typedef struct{
    //此处线性表数据类型定义为int
    int data[100];
    int length;
}sequenlist;
typedef struct node{
    int data1;
    struct node* next;
};
sequenlist* create(){
    sequenlist* L=(sequenlist*)malloc(sizeof(sequenlist));
    L->length=0;
    while(1){
        int a;
        scanf("%d",&a);
        if(a==-1)
            break;
        L->data[L->length++]=a;
    }
    return L;
}
node* create1(){
    node *head=NULL;
    node *r=NULL;
    while(1){
        int a;
        scanf("%d",&a);
        if(a==-1)
            break;
        node *p=(node*)malloc(sizeof(node));
        p->data1=a;
        p->next=NULL;
        if(head==NULL){
            head=p;
            r=p;
        }
        else{
            r->next=p;
            r=p;
        }

    }
    return head;
}///尾插法建单向链表
//此处延用2.18中的代码与函数，处理顺序表的逆置问题
void reverse(sequenlist* L,int left,int right){
    for(int i=0;i<(right-left+1)/2;i++){
        int temp=L->data[left+i];
        L->data[left+i]=L->data[right-i];
        L->data[right-i]=temp;
    }
}
node* reverse1(node* head){
    node* pre=NULL;
    node *cur=head;
    node *next=NULL;
    while(cur!=NULL){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}
void print(sequenlist* L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
void print1(node* head){
    node *p=head;
    while(p!=NULL){
        printf("%d ",p->data1);
        p=p->next;
    }
}
int main(){
    sequenlist *L1=create();
    getchar();
    reverse(L1,0,L1->length-1);
    print(L1);
    //线性表逆置较为简单
    node *L2=create1();
    getchar();
    print1(reverse1(L2));
    //链表逆置
    return 0;
}