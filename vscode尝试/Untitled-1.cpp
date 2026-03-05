#include<iostream>
using namespace std;
struct node{
    int data;
    node *lchild=NULL;
    node *rchild=NULL;
}node[100];
void pushtree(node *root){
    cout<<root->data<<endl;
    pushtree(root->lchild);
    pushtree(root->rchild);
}
int main(){
    int n;
    cin>>n;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        node[i].data=c;
        if(a!=-1){
            node[i].lchild=&node[a];
        }
        if(b!=-1){
            node[i].rchild=*node[b];
        }
    }
    return 0;
}