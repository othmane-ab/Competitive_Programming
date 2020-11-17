// There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

// You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.

// What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

// Input

// The first input line contains an integer n: the number of customers.

// Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.

// Output

// Print first an integer k: the minimum number of rooms required.

// After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,…,k. You can print any valid solution.

// Constraints
// 1≤n≤2⋅105
// 1≤a≤b≤109
// Example

// Input:
// 3
// 1 2
// 2 4
// 4 4

// Output:
// 2
// 1 2 1
#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n, ans[nxM];
ar<int, 3> a[nxM];
 
 
int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a[i][1] >> a[i][0]; // checkin departure
        a[i][2] = i;// to keep track of the original indices
    }
    sort(a, a+n);// sort by departure time
    set<ar<int,2>> s;
    for(int i=0; i<n; ++i){
        auto it=s.lower_bound({a[i][1]});
        if(it!=s.begin()){
            --it;
            ans[a[i][2]] = (*it)[1];//take vacated room
            s.erase(it);
        }else{
            ans[a[i][2]] = s.size();//new room
        }
        s.insert({a[i][0], ans[a[i][2]]});// new stay
    }
    cout << s.size() << "\n";
    for(int i=0; i<n; ++i){
        cout << ans[i]+1 << " ";
    }
}
