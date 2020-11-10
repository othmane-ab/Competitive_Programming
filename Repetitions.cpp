// You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

// Input

// The only input line contains a string of n characters.

// Output

// Print one integer: the length of the longest repetition.

// Constraints
// 1≤n≤106
// Example

// Input:
// ATTCGGGA

// Output:
// 3

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <cstring>
 
 
using namespace std;
 
const int nxM=1e6;
string s;
int ans;
 
int main(){
    cin >> s;
    char p;
    int l;
    for(char c: s){
        if(p==c){
            l+=1;
            ans = max(ans, l);
        }else{
            p = c;
            l = 0;
        }
    }
    
    cout << ans + 1;
}