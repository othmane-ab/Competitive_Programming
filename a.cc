#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <cstring>
 
#define ll long long
#define ar array 
using namespace std;

ll n;

int main(){
    cin >> n;
    cout << n << " ";
    while(n>1){
        if(n%2==0){
            n = n/2;
        }else{
            n = n*3+1;
        }
        cout << n << " ";
    }
}