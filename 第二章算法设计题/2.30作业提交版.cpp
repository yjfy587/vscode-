/*已知存在单链表表示的线性表 含有三类字符的数据元素（字母、数字、特殊字符） 构造三个以循环链表表示的线性表 使每个列表中仅含有一种类型的字符*/
#include <stdio.h>
#include <cstdlib>
#include <stack>
typedef struct node{
    char data;
    struct node* next;
}node;
node* create(){
    node *head=NULL;
    node *r=NULL;
    while(1){
        char c;
        scanf("%c",&c);
        int data=c-'0';
        if(c=='\n') break;
/*       else if(c>='0'&&c<='9'){
            std::stack <char> s;
            while(scanf("%c",&c)&&c>='0'&&c<='9'){
                s.push(c);
            }
            while(!s.empty()){
                char ch=s.top();
                s.pop();
                data=data*10+(ch-'0');
            }
        }
        c=char(data+'0');
*/
        node *s=(node*)malloc(sizeof(node));
        s->data=c;
        s->next=NULL;
        if(head==NULL){
            head=s;
            r=s;
        }
        else{
            r->next=s;
            r=s;
        }
    }
    return head;
}
void split(node *head,node *&head1,node *&head2,node *&head3){
    node* p=head;
    node *r1=head1;
    node *r2=head2;
    node *r3=head3;
    while(p!=NULL){
        if(p->data>='0'&&p->data<='9'){
            r1->next=p;
            r1=r1->next;
        }
        else if(p->data==' '){
            p=p->next;
            continue;
        }
        else if (p->data>='a'&&p->data<='z'||p->data>='A'&&p->data<='Z'){
            r2->next=p;
            r2=r2->next;
        }
        else{
            r3->next=p;
            r3=r3->next;
        }
        p=p->next;
    }
    r1->next=head1;
    r2->next=head2;
    r3->next=head3;
}
void print(node* head){
    node* p=head->next;
    while(p!=head){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    node *head=create();
    node *head1=(node*)malloc(sizeof(node));
    node *head2=(node*)malloc(sizeof(node));
    node *head3=(node*)malloc(sizeof(node));
    split(head,head1,head2,head3);
    print(head1);
    print(head2);
    print(head3);
    free(head);
    free(head1);
    free(head2);
    free(head3);
}