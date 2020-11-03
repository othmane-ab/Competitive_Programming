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
char arr[27];

int main(){
    cin >> s;
    int i=0, n=s.length();
    char* s_ = new char[n];
    for(char c:s){
        arr[c-'A'] += 1;
        if(arr[c-'A']==2){
            s_[i] = c;
            s_[n-i-1] = c;
            arr[c-'A'] = 0;
            i += 1;
        }
    }
    int sum=0;
    for(int j=0; j<27; j++){
        sum += arr[j];
        if(arr[j]==1){
            s_[i] = 'A'+j;
        }
    }
    if(sum>1){
        cout << "NO SOLUTION";
    }else{
        cout << s_;
    }
}