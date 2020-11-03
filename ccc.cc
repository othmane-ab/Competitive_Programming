#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=2e5;
int n,q;
ll x[mxN];

struct node {
    ll minimum, sum, lazy;
} segment_tree[1<<19];

void app(int _s_index, ll _value, int _a_index_left, int _a_index_right){
    segment_tree[_s_index].minimum += _value;
    segment_tree[_s_index].sum += _value*(_a_index_right-_a_index_left+1);
    segment_tree[_s_index].lazy += _value;
}

void psh(int _s_index, int _a_index_left, int _a_index_mid, int _a_index_right){
    app(2*_s_index, segment_tree[_s_index].lazy, _a_index_left, _a_index_mid);
    app(2*_s_index+1, segment_tree[_s_index].lazy, _a_index_mid+1, _a_index_right);
    segment_tree[_s_index].lazy=0;
}

void upd(int _a_index, ll _value, int _s_index=1, int _a_index_left=0, int _a_index_right=n-1){
    if(_a_index_left==_a_index_right){
        segment_tree[_s_index].minimum = _value;
        segment_tree[_s_index].sum = _value;
        return;
    }
    int a_index_mid =(_a_index_left+_a_index_right)/2;
    psh(_s_index,_a_index_left,a_index_mid,_a_index_right);
    if(_a_index<=a_index_mid){
        upd(_a_index,_value,2*_s_index,_a_index_left,a_index_mid);
    }else{
        upd(_a_index,_value,2*_s_index+1,a_index_mid+1,_a_index_right);
    }
    segment_tree[_s_index].minimum = min(segment_tree[2*_s_index].minimum, segment_tree[2*_s_index+1].minimum);
    segment_tree[_s_index].sum = segment_tree[2*_s_index].sum+segment_tree[2*_s_index+1].sum;
}

void upd2(int _a_index, int _a_index_2, ll _value, int _s_index=1, int _a_index_left=0, int _a_index_right=n-1){
    if(_a_index<=_a_index_left&&_a_index_right<=_a_index_2){
        app(_s_index,_value,_a_index_left,_a_index_right);
        return;
    }
    int a_index_mid=(_a_index_left+_a_index_right)/2;
    psh(_s_index,_a_index_left,a_index_mid,_a_index_right);
    if(_a_index<=a_index_mid){
        upd2(_a_index,_a_index_2,_value,2*_s_index,_a_index_left,a_index_mid);
    }
    if(a_index_mid<_a_index_2){
        upd2(_a_index,_a_index_2,_value,2*_s_index+1,a_index_mid+1,_a_index_right);
    }
    segment_tree[_s_index].minimum = min(segment_tree[2*_s_index].minimum, segment_tree[2*_s_index+1].minimum);
    segment_tree[_s_index].sum = segment_tree[2*_s_index].sum+segment_tree[2*_s_index+1].sum;
}

ll qry(int _a_index, int _a_index_2, int _s_index=1, int _a_index_left=0, int _a_index_right=n-1){
    // if(segment_tree[_s_index].lazy!=0){
    //     segment_tree[_s_index].sum += (_a_index_right-_a_index_left+1)*segment_tree[_s_index].lazy;
    //     if(_a_index_left!=_a_index_right){
    //         segment_tree[2*_s_index].lazy += segment_tree[_s_index].lazy;
    //         segment_tree[2*_s_index+1].lazy += segment_tree[_s_index].lazy;
    //     }
    //     segment_tree[_s_index].lazy = 0;
    // }
    if(_a_index<=_a_index_left&&_a_index_right<=_a_index_2){
        return segment_tree[_s_index].sum;
    }
    int a_index_mid=(_a_index_left+_a_index_right)/2;
    return (_a_index<=a_index_mid?qry(_a_index,_a_index_2,2*_s_index,_a_index_left,a_index_mid):0)+(a_index_mid<_a_index_2?qry(_a_index,_a_index_2,2*_s_index+1,a_index_mid+1,_a_index_right):0);
}


int main(){
    cin >> n >> q;
    for(int i=0; i<n;++i){
        cin >> x[i], upd(i,x[i]);
    }
    while(q--){
        int qt;
        cin >> qt;
        if(qt==1){
            int a,b,u;
            cin >> a >> b >> u, --a, --b;
            upd2(a,b,u);
        }else{
            int k;
            cin >> k, --k;
            cout << qry(k,k) << "\n";
        }
    }
    
}