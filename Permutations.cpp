// A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

// Given n, construct a beautiful permutation if such a permutation exists.

// Input

// The only input line contains an integer n.

// Output

// Print a beautiful permutation of integers 1,2,…,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

// Constraints
// 1≤n≤106
// Example 1

// Input:
// 5

// Output:
// 4 2 5 3 1

// Example 2

// Input:
// 3

// Output:
// NO SOLUTION

#include <iostream>
 
using namespace std;
 
int n;
 
int main(){
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    if(n<4){
        cout << "NO SOLUTION";
    }else{
        if(n%2==0){
            for(int i=2; i<=n; i+=2){
                cout << i << " ";
            }
            for(int i=1; i<=n-1; i+=2){
                cout << i << " ";
            }
        }else{
            for(int i=2; i<=n-1; i+=2){
                cout << i << " ";
            }
            for(int i=1; i<=n; i+=2){
                cout << i << " ";
            }
        }
    }
}
