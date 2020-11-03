#include <iostream>
#include <bits/stdc++.h> 
#include <cstring>
#include<algorithm>

#define ll long long
#define ar array 
using namespace std;
 
string s;
int arr[26];
int ans;


void down(int arr[26], int d, string s){
    if(d==s.length()){
        cout << s;
        ans += 1;
    }else{
        int arr_[26];
        char* s_;
        s.copy(s_, s.length(), 0);
        copy_n(arr,26,arr_);
        for(int i=0; i<26; ++i){
            if(arr_[i]>0){
                arr_[i] -= 1;
                ++d;
                s[d] = 'a'+i;
                down(arr_,d,s);
            }
        }
    }
}

int main(){
    cin >> s;
    int n = s.length();
    for(char c :s){
        arr[c-'a'] += 1;
    }
    down(arr, 0, s);    
}