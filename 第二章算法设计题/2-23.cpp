/*将含有头结点的单链表A分解成A和B，A中是奇序数，B中是偶序数*/
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *create(){
    node *head=new node;
    head->next=NULL;
    node *tail=head;
    cout<<"请输入数据（输入-1建表结束"<<endl;
    while(1){
        int data;
        cin>>data;
        if(data==-1){
            break;
        }
        node *s=new node;
        s->data=data;
        s->next=NULL;
        tail->next=s;
        tail=s;
    }
    return head;
}
void split(node* A,node *&B){
    B=new node;
    B->next=NULL;

    node*p=A->next;
    node *tailA=A;
    node *tailB=B;
    int count=1;

    while(p!=NULL){
        if(count%2==1){
            tailA->next=p;
            tailA=p;
        }
        else{
            tailB->next=p;
            tailB=p;
        }
        p=p->next;
        count++;
    }
    tailA->next=NULL;
    tailB->next=NULL;
}
void print(node *head){
    node *p=head->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    node *A=create();
    print(A);
    node *B=NULL;
    split(A,B);
    print(A);
    print(B);

    return 0;
}