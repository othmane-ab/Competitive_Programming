#include <bits/stdc++.h>

using namespace std;

int n,x;

struct node{
    node* left;
    node* right;
    int value;
    void ins(int u){
        node* p = root;
        bool exist = 0;
        while(p){
            if(u < p->value){
                p = p->left;
            }else if(u > p->value){
                p = p->right;
            }else{
                exist = 1;
            }
        }
        if(!exist){
            p = new node();
            p->value = u;
        }
    }
}* root;

int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        if(i==0){
            cin >> root.value ;
        }else{
            cin >> x, root.ins(x);
        }
    }
}