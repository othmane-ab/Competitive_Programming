#include <bits/stdc++.h>  
#define ll long long
#define ar array 
using namespace std;

const int mxN=2e5;
int n;
ll x;
map<int, int> mp;
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i){
        int t;
        cin >> t;
        auto it = mp.find(x-t);
        if(it!=mp.end()){
            cout << i+1 << " " << it->second+1;
            return 0;
        }else{
            mp[t] = i;
        }
    }
    cout << "IMPOSSIBLE";

}