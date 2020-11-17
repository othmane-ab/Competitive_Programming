// There is a street of length x whose positions are numbered 0,1,…,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.

// Your task is to calculate the length of the longest passage without traffic lights after each addition.

// Input

// The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.

// Then, the next line contains n integers p1,p2,…,pn: the position of each set of traffic lights. Each position is distinct.

// Output

// Print the length of the longest passage without traffic lights after each addition.

// Constraints
// 1≤x≤109
// 1≤n≤2⋅105
// 0<pi<x
// Example

// Input:
// 8 3
// 3 6 2

// Output:
// 5 3 3

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int x,n,p[nxM];       
map<int, int> mp;
 
int main(){
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    mp[x]=1;
    for(int i=0;i<n;++i){
        cin >> p[i];
        auto it = s.lower_bound(p[i]);
        int r=*it;
        --it;
        int l=*it;
        --mp[r-l];
        if(!mp[r-l])
            mp.erase(r-l);
        s.insert(p[i]);
        ++mp[r-p[i]];
        ++mp[p[i]-l];
        cout << (--mp.end())->first << " ";
    }
}