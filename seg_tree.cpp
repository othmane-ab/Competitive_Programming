#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=10;//2e5;
int n,m;
int t[4*mxN];
int h[mxN];
int r[mxN];

void build(int a[], int v, int tl, int tr){
    if(tl==tr){
        t[v] = a[tl];
    }else{
        int tm = (tl+tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }   
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        t[v] = new_val;
    }else{
        int tm = (tr+tl)/2;
        if(pos < tm){
            update(v*2, tl, tm, pos, new_val);
        }else{
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void updateRange(int v, int low, int high, int qlow, int qhigh, int u){
    if(qlow<=low&&qhigh>=high){
         
    }
    if(qlow>low||qhigh<high){

    }
    
    if(tl==tr){
        t[v] += u;
    }else{
        int tm = (tr+tl)/2;
        if(pos < tm){
            update(v*2, tl, tm, pos, new_val);
        }else{
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int qlow, int qhigh, int low, int high, int pos){
    if(qlow<=low&&qhigh>=high){

    }
    if(qlow>low||qhigh<high){

    }
    int mid = (low+high)/2;
    return query(qlow,qhigh,low,mid,2*pos)
}


int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> h[i];
    }
    build(h, 1, 0, n-1);
    for(int i=0; i<m; ++i){
        cin >> r[i];
    }
}