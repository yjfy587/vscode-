/*将无重复的由小到大顺序表AB合并成表c*/
/*思路，全部合并进表c中，并且进行排序*/
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
struct sequenlist{
    int data[1000];
    int last=0;
};
bool cmp(int a,int b){
    return a<b;
}
sequenlist* create(int m){
    sequenlist *l=new sequenlist;
    for(int i=0;i<m;i++){
        cin>>l->data[i];
        l->last++;
    }
    return l;
}
sequenlist* hebing(sequenlist*a,sequenlist *b){
    sequenlist *c=new sequenlist;
    for(int i=0;i<a->last;i++){
        c->data[i]=a->data[i];
    }
    for(int j=a->last;j<=a->last+b->last-1;j++){
        c->data[j]=b->data[j-a->last];
    }
    c->last=a->last+b->last;
    sort(c->data,c->data+c->last,cmp);
    return c;
}
int main(){

    cin>>m>>n;
    sequenlist *a;
    sequenlist *b;
    sequenlist *c;
    a=create(m);
    b=create(n);
    c=hebing(a,b);
    for(int i=0;i<=c->last-1;i++){
        cout<<c->data[i]<<endl;
    }
    delete a;
    delete b;
    delete c;
    return 0;
}