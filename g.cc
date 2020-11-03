#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <cstring>
 
#define ll long long
#define ar array 
using namespace std;

string s;
string p;
int* temp;

int main(){
    cin >> s;
    cin >> p;
    int m = p.length();
    int n = s.length();
    temp = new int [m];
    int i,j,k;
    int ans = 0;


    for(j=1; j<m; ++j){
        i = 0;
        k = j;
        while(p[k]==p[i]){
            ++i;
            temp[k] = i;
            ++k;
        }
    }

    i = 0;
    j = 0;

    while(i<n){
        for(j; s[i+j]==p[j]; j++){}
        if(j < m){
            j = j>0?temp[j-1]:0;
        }else{
            j = 0;
            ++ans;
        }
        ++i;
    }
    cout << ans;
//abbaba
//aba
    // a b b d a a b b d 
    // 0 0 0 0 1 1 2 3 4  
    // a b a
    // 0 0 1

    return 0;
}