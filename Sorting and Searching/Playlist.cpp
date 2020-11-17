// You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.

// What is the longest sequence of successive songs where each song is unique?

// Input

// The first input line contains an integer n: the number of songs.

// The next line has n integers k1,k2,…,kn: the id number of each song.

// Output

// Print the length of the longest sequence of unique songs.

// Constraints
// 1≤n≤2⋅105
// 1≤ki≤109
// Example

// Input:
// 8
// 1 2 1 3 2 7 4 2

// Output:
// 5

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n, k[nxM];
int ans;
 
int main(){
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; ++i){
        cin >> k[i];
    }
    for(int i=0,j=0; i<n; ++i){
        while(j<n&&mp[k[j]]<1){
            mp[k[j]]++;
            ++j;
        }
        ans = max(j-i, ans);
        --mp[k[i]];
    }
    cout << ans;
}