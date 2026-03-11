#include<stdio.h>
#include<cstdlib>
typedef struct{
    //此处线性表数据类型定义为int
    int data[100];
    int length;
}sequenlist;
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
void print(sequenlist* L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
void reverse(sequenlist* L,int left,int right){
    for(int i=0;i<(right-left+1)/2;i++){
        int temp=L->data[left+i];
        L->data[left+i]=L->data[right-i];
        L->data[right-i]=temp;
    }
}
void pushright(sequenlist* L,int x){
    reverse(L,0,L->length-1);
    reverse(L,0,x-1);
    reverse(L,x,L->length-1);
}
int main(){
    sequenlist *L=create();
    getchar();
    int k;
    scanf("%d",&k);
    pushright(L,k);
    print(L);
    //此处观察状态，右移k位等于将前k个元素逆序，后n-k个元素逆序，再将整个数组逆序
    //以-1结尾输入，可以修改为其他结尾输入方式
    return 0;
}