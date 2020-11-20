// You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.
// Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

// Input
// The first input line has two integers n and m: the array size and the upper bound for each value.
// The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.

// Output
// Print one integer: the number of arrays modulo 109+7.

// Constraints
// 1≤n≤105
// 1≤m≤100
// 0≤xi≤m
// Example

// Input:
// 3 5
// 2 0 2

// Output:
// 3

// Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.

// dp state
// dp(i,x): nbr of valid arrays of size i s.t. last element is x
// dp(i,x) = 0 if a[i-1]!=0 and a[i-1]!=x
//           dp(i-1,x) + dp(i-1,x-1) + dp(i-1,x+1) otherwise
// dp(1,x) = 0 if and a[0]!=0 and a[0]!=x
//           1 if a[0]==0 or a[0]==x 

// answer is dp(n,m) + dp(n,m-1) + ... + dp(n,0)

// intuition
// _ _ _ _ x
// suppose x is not fixed
// ex _ _ _ _ 2 nbr of valid arrays ending with 2 is the nbr of arrays of size lesser by 1 and ending in 0 or 1 


#include <bits/stdc++.h>  
#define ll long long
#define ar array 
using namespace std;
 
const int mxN=1e5, mxM=100, M=1e9+7;

int solve(int n, int m, vector<int>& v){
    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);
 
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= m; x++){
            if(i == 1){
                if(v[i] == 0 || v[i] == x) dp[i][x] = 1;
                else dp[i][x] = 0;
            }else{
                if(v[i] == 0 || v[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%M + dp[i-1][x+1])%M;
                }else dp[i][x] = 0;
            }
        }
    }
    int ans = 0;
    for(int x = 1; x <= m; x++) ans = (ans + dp[n][x]) % M;
    return ans;
}
 
int main() {
   ll t,n,m,x,i,j,k,q;
   t = 1;
   while(t--)
   {
        int n,m;
        cin >> n >> m;
        vector<int> v(n+1);
        for(int i=1;i<n+1;++i) cin >> v[i];
        cout << solve(n,m,v);
   }
   return 0;
}