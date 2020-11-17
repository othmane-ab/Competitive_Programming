// You are given an array containing n positive integers.

// Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

// Input

// The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.

// The next line contains n integers x1,x2,…,xn: the contents of the array.

// Output

// Print one integer: the maximum sum in a subarray in the optimal division.

// Constraints
// 1≤n≤2⋅105
// 1≤k≤n
// 1≤xi≤109
// Example

// Input:
// 5 3
// 2 4 7 3 5

// Output:
// 8

#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;
 
const int mxN=2e5;
int n,k;
ll a[mxN];
 
int main(){
    cin >> n >> k;
    ll mx = 0;
    ll s = 0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(a[i]>mx) mx=a[i];
        s += a[i];
    }
// assume you have max_sum. 
// Then you can divide the array into some number x of subarrays such that every subarray has sum < max_sum. 
// If you increase the max_sum, then the number of subarrays either stays the same or decreases
// x = f(max_sum) is a decreasing function
// solution to f(max_sum)=k 
    ll lb=mx,rb=s;
    while(lb<rb){
        ll mb = (lb+rb)/2;
        // compare nbr of subarrays with max sum = mb with k
        // max_sum k
        int c=0;
        ll ls=0;
        for(int i=0; i<n; ++i){
            if(ls+a[i]>mb){
                ++c;
                ls = 0;
            }
            ls += a[i];
        }
        ++c;
        if(c>k){
            lb = mb + 1;
        }else{
            rb = mb;
        }
    }
    cout << lb;
 
}
