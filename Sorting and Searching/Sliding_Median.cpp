// You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.

// The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.

// Input

// The first input line contains two integers n and k: the number of elements and the size of the window.

// Then there are n integers x1,x2,…,xn: the contents of the array.

// Output

// Print n−k+1 values: the medians.

// Constraints
// 1≤k≤n≤2⋅105
// 1≤xi≤109
// Example

// Input:
// 8 3
// 2 4 3 5 8 1 2 1

// Output:
// 3 4 5 5 2 1

#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;
 
const int mxN=2e5;
int n,k;
ll a[mxN];
ar<int, 2> med={-1};
set<ar<int,2>> bot, top;
 
void fix(){
    int m = 1 + bot.size() + top.size();
 
    if(bot.size()<(m-1)/2){
        bot.insert(med);
        med = *top.begin();
        top.erase(med);
    }
    if(bot.size()>(m-1)/2){
        top.insert(med);
        med = *--bot.end();
        bot.erase(med);
    }
 
}
 
void add(ar<int,2> x){
    if(med[0]==-1){
        med=x; return;
    }
    if(x<med){
        bot.insert(x);
    }else{
        top.insert(x);
    }
    fix();
}
 
void rem(ar<int,2> x){
    if(x==med){
        med = *top.begin();
        top.erase(med);
    }else if(x<med){
        bot.erase(x);
    }else{
        top.erase(x);
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
            cout << a[i] << " ";
        }
        return 0;
    }
    for(int i=0; i<k-1; ++i){
        add({a[i],i});
    }
    for(int i=k-1; i<n; ++i){
        add({a[i],i});
        cout << med[0] << " ";
        rem({a[i-k+1], i-k+1});
    }
}