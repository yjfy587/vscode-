#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node *create(){
    node *head=new node;
    head->next=NULL;
    node *tail=head;
    while(1){
        int data;
        cin>>data;
        if(data==-1){
            break;
        }
        node* s=new node;
        s->next=NULL;
        s->data=data;
        tail->next=s;
        tail=s;
    }
    return head;
}
node* reverse(node *A){
    node *curr=A;
    node *prev=NULL;
    node *next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void hebing(node *A, node *B, node *&C) {
    C = new node;
    C->next = NULL;
    node *tail = C;
    node *tailA = A;
    node *tailB = B;
    while (tailA != NULL || tailB != NULL) {
        if (tailA != NULL && (tailB == NULL || tailA->data >= tailB->data)) {
            node *s = new node;
            s->data = tailA->data;
            s->next = NULL;
            tail->next = s;
            tail = s;
            tailA = tailA->next;
        } else if (tailB != NULL && (tailA == NULL || tailA->data < tailB->data)) {
            node *s = new node;
            s->data = tailB->data;
            s->next = NULL;
            tail->next = s;
            tail = s;
            tailB = tailB->next;
        }
    }
    tail->next=NULL;
}
void print(node *head){
    node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    node *A=NULL;
    node *B=NULL;
    A=create();
    B=create();
    print(A);
    print(B);
    node *C=NULL;
    hebing(reverse(A),reverse(B),C);
    print(C);
    return 0;
}