// There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

// Input

// The first input line has an integer n: the number of apples.

// The next line has n integers p1,p2,…,pn: the weight of each apple.

// Output

// Print one integer: the minimum difference between the weights of the groups.

// Constraints
// 1≤n≤20
// 1≤pi≤109
// Example

// Input:
// 5
// 3 2 7 4 1

// Output:
// 1

// Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
ll p[20];
int n;
 
int main(){
    cin >> n;
    ll s=0, ans=0;
    for(int i=0;i<n;++i){
        cin >> p[i], s+=p[i];
    }
    for(int i=0;i<1<<n;++i){
        ll cs=0;// subset sum
        for(int j=0;j<n; ++j){// this part goes through the subsets
            if(i>>j&1){
                cs += p[j];
            }
        }
        if(cs<=s/2){
            ans = max(ans, cs);
        }
    }
    cout << abs(ans - (s - ans));
}
