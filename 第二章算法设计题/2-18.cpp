/*用顺序存储结构设计算法，仅用一个辅助节点，实现将线性表中的节点循环右移k位的运算*/
#include<stdio.h>

typedef struct{
    char data[110];
    int last;
}sequenlist;
int n;
sequenlist *create(){
    int i=0;
    char ch;
    sequenlist* l;
    l=(sequenlist*)malloc(sizeof(sequenlist));
    l->last=-1;
    while((ch=getche())!='#'){
        l->data[i++]=ch;
        l->last++;
    }
    return l;
}
void reverse(sequenlist *l,int start,int end){
    while(start<end){
        char temp;
        temp=l->data[start];
        l->data[start]=l->data[end];
        l->data[end]=temp;
        start++;
        end--;
    }
}
void movek(sequenlist *l,int k){
    if(l->data+1==0){
        return;
    }
    k=k%n;
    reverse(l,0,n-1);
    reverse(l,0,k-1);
    reverse(l,k,n-1);


}
int main(){
    int k;
    scanf("%d",k);
    scanf("%d",n);
    sequenlist *s;
    s=create();
    s=movek(s,k);

    return 0;
}