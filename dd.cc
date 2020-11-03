#include <bits/stdc++.h> 

#define ll long long
#define ar array 
using namespace std;

int n;
int main(){
    cin >> n;
    set<int> s;
    for(int i=0; i<n; ++i){
        ll t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size();
}