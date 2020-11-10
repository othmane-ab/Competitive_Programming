// Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

// Input

// The only input line has a string of length n consisting of characters A–Z.

// Output

// Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

// Constraints
// 1≤n≤106
// Example

// Input:
// AAAACACBA

// Output:
// AACABACAA

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
