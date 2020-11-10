// A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

// Your task is to find out the number in row y and column x.
// 1   2   9   10  25
// 4   3   8   11  24
// 5   6   7   12  23
// 16  15  14  13  22
// 17  18  19  20  21


// Input

// The first input line contains an integer t: the number of tests.

// After this, there are t lines, each containing integers y and x.

// Output

// For each test, print the number in row y and column x.

// Constraints
// 1≤t≤105
// 1≤y,x≤109
// Example

// Input:
// 3
// 2 3
// 1 1
// 4 2

// Output:
// 8
// 1
// 15

#include <iostream>
 
#define ll long long
 
using namespace std;
 
int t;
ll y,x;
 
int main(){
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> y >> x;
        
        if(x>y){
            cout << (x%2==1)*(x*x-(y-1)) + (x%2==0)*((x-1)*(x-1) + y) << "\n";
        }else if(y>x){
            cout << (y%2==1)*((y-1)*(y-1) + x) + (y%2==0)*(y*y - (x-1)) << "\n";
        }else{
            cout << x*x - (x-1) << "\n";
        }
    }
}
// 689913499 770079066
// 586095107 933655238
// 593021767041187724
// 871712102163621276