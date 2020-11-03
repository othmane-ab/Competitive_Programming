#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

#define ll long long

const int nxM=2e5;
ll x[nxM];
ll q,n;
int a,b;
int main(){
    cin >> n >> q;
    for(int i=0; i<n; ++i){
        cin >> x[i], x[i] += ((i==0)?0:x[i-1]);
    }
    for(int i=0; i<q; ++i){
        cin >> a >> b;
        ll s = x[b-1] - x[a-2]; //(x+(ll)(a-1), x+(ll)b, 0);
        cout << s << "\n";
    }
}