#include<stdio.h>
#include<cstdlib>
typedef struct node{
    int data1;
    struct node* next;
};
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
}//尾插法建表
node* hebing(node* head1,node* head2){
    node*p1=head1;
    node*p2=head2;
    node *prev=NULL;
    node *next=NULL;
    while(p1!=NULL&&p2!=NULL){
        if(p1->data1>p2->data1){
            next=p2->next;
            p2->next=prev;
            prev=p2;
            p2=next;
        }
        else{
            next=p1->next;
            p1->next=prev;
            prev=p1;
            p1=next;
        }
    }//此处将两个链表进行合并，合并过程中进行逆置
    if(p2==NULL){
        while(p1!=NULL){
            next=p1->next;
            p1->next=prev;
            prev=p1;
            p1=next;
        }
    }
    else{
        while(p2!=NULL){
            next=p2->next;
            p2->next=prev;
            prev=p2;
            p2=next;
        }
    }//此处将剩余链表进行逆置
    return prev;
}
void print(node *head){
    while(head!=NULL){
        printf("%d ",head->data1);
        head=head->next;
    }
}
int main(){
    node *head1=create1();
    getchar();
    node *head2=create1();
    node *head=hebing(head1,head2);
    print(head);
    return 0;    
}
//解决链表反转等问题的通用思路是寻找好需要几个指针 确定好指针含义和移动先后 确保每一个结点在箭头反转过程中不会丢失 将指针反转拆成一个一个子任务 最后再去确认指针为空的逆置 实际上此时就与2.22无异了