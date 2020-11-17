// You are given an array of n integers. Your task is to calculate for each window of k elements, from left to right, the minimum total cost of making all elements equal.

// You can increase or decrease each element with cost x where x is the difference between the new and the original value. The total cost is the sum of such costs.

// Input

// The first input line contains two integers n and k: the number of elements and the size of the window.

// Then there are n integers x1,x2,…,xn: the contents of the array.

// Output

// Output n−k+1 values: the costs.

// Constraints
// 1≤k≤n≤2⋅105
// 1≤xi≤109
// Example

// Input:
// 8 3
// 2 4 3 5 8 1 2 1

// Output:
// 2 2 5 7 7 1

#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;
 
const int mxN=2e5;
int n,k;
ll a[mxN];
ar<int, 2> med={-1};
set<ar<int,2>> bot, top;
ll sb,st;
 
void fix(){
    int m = 1 + bot.size() + top.size();
 
    if(bot.size()<(m-1)/2){
        bot.insert(med);
        sb += med[0];
        med = *top.begin();
        top.erase(med);
        st-= med[0];
    }
    if(bot.size()>(m-1)/2){
        top.insert(med);
        st += med[0];
        med = *--bot.end();
        bot.erase(med);
        sb -= med[0];
    }
 
}
 
void add(ar<int,2> x){
    if(med[0]==-1){
        med=x; return;
    }
    if(x<med){
        bot.insert(x), sb+=x[0];
    }else{
        top.insert(x), st+=x[0];
    }
    fix();
}
 
void rem(ar<int,2> x){
    if(x==med){
        med = *top.begin();
        st -= med[0];
        top.erase(med);
    }else if(x<med){
        bot.erase(x);
        sb -= x[0];
    }else{
        top.erase(x);
        st-= x[0];
    }
    fix();
}
 
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    if(k==1){
        for(int i=0; i<n; ++i){
            cout << 0 << " ";
        }
        return 0;
    }
    for(int i=0; i<k-1; ++i){
        add({a[i],i});
    }
    for(int i=k-1; i<n; ++i){
        add({a[i],i});
        cout << st-med[0]*(ll)top.size() + med[0]*(ll)bot.size()-sb<< " " << flush;
        rem({a[i-k+1], i-k+1});
    }
}
