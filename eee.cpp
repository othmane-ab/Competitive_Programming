#include <bits/stdc++.h>
#include <ext/pd_ds/tree_policy.hpp>
#include <ext/pd_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
const int mxN = 2e5;
int n,k;
int x[mxN];

typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_stastics_node_update>;

Tree<pii> T;

int main() {
  cin >> n >> k;
  for(int i=0; i<n; ++i){
    cin >> x[i];
  }
  for(int i=0; i<k; ++i){
    T.insert({x[i], i});
  }
  for(int i=k; i<n+1; ++i){
    cout << T.find_by_order((k-1)/2)->first << " ";
    if(i!=n){
      T.erase({x[i-k], i-k});
      T.insert({x[i], i});
    }
  }

}