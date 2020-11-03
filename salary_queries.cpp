#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;
// A company has n employees with certain salaries. Your task is to keep track of the salaries and process queries.

// Input

// The first input line contains two integers n and q: the number of employees and queries. The employees are numbered 1,2,…,n.

// The next line has n integers p1,p2,…,pn: each employee's salary.

// After this, there are q lines describing the queries. Each line has one of the following forms:
// ! k x: change the salary of employee k to x
// ? a b: count the number of employees whose salary is between a…b
// Output

// For this problem we can use a segment tree with lazy propagation to store the employee salaries, 
// for each node, we need to have the max and min of the subtree salaries
// in case of update of salary k, we only need to update the tree (lazy elements)
// in case of query, we go up to bottom if the condition of salary between a..b is met and keep track of 
// discuss cases in case of total overlap, partial overlap

// Print the answer to each ? query.

// Constraints
// 1≤n,q≤2⋅105
// 1≤pi≤109
// 1≤k≤n
// 1≤x≤109
// 1≤a≤b≤109
// Example

// Input:
// 5 3
// 3 7 2 2 5
// ? 2 3
// ! 3 6
// ? 2 3

// Output:
// 3
// 2
const int mxN=2e5;
int p[mxN];
int n,q,a,b;
char q_type;

int t[4*mxN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int count(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return count(v*2, tl, tm, l, min(r, tm))
           + count(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main(){
    cin >> n >> q;
    for(int i=0; i<n; ++i){
        cin >> p[i];
    }
    for(int i=0; i<q; ++i){
        cin >> q_type >> a >> b;
        if(q_type=='?'){

        }
        if(q_type=='!'){

        }
    }
}