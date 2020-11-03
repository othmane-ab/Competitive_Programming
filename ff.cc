#include <bits/stdc++.h>  
#define ll long long
#define ar array 
using namespace std;
 
const int mxN=1e3, mxX=1e5;
int n, x, h[mxN], s[mxN], dp[mxX+1];
// state dp[i][j] will denote the max value of nbr_pages considering all book prices 0 to x
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i){
        cin >> h[i];//price
    }
    for(int i=0; i<n; ++i){
        cin >> s[i];//nbr pages
    }
    for(int i=0; i<n; ++i){
        for(int j=x; j>=h[i]; --j){// to update the max value of dp[i][x]
            dp[j] = max(dp[j], dp[j-h[i]] + s[i]);// 
        }
    }
    cout << dp[x];
}