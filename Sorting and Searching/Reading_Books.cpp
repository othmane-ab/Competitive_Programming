// There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.

// They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?

// Input

// The first input line has an integer n: the number of books.

// The second line has n integers t1,t2,…,tn: the time required to read each book.

// Output

// Print one integer: the minimum total time.

// Constraints
// 1≤n≤2⋅105
// 1≤ti≤109
// Example

// Input:
// 3
// 2 8 3

// Output:
// 16
#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int mxN=2e5;
int n, t[mxN];
 
int main()
{
    
    cin >> n;
    ll s=0;
    for(int i=0; i<n; ++i){
        cin >> t[i];
        s += t[i];
    }
    sort(t, t + n);
    cout << max(s, 2ll*t[n-1]);
    
    return 0;
}
