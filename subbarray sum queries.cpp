#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=2e5;

struct node {
    ll sum, pref, suff, ans;
    // sum is max subarray sum
    // pref is maximum possible sum of some prefix
};
node t[4*mxN];

node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    //The maximum sum prefix could be the same as prefix_of_left_child or it could be the entire left_child_range UNION prefix_of_right_child
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);// either left ans or right ans or of form suffix UNION prefix
    return res;
}

node make_data(int val) {
    node res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int n,m,k,x,p[mxN];

int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> p[i];
    }
    build(p, 1, 0, n-1);
    for(int i=0;i<m;++i){
        cin >> k >> x, --k;
        update(1, 0, n-1, k, x);
        node ans = query(1, 0, n-1, 0, n-1);
        cout << ans.ans << "\n" << flush;
    }
}
