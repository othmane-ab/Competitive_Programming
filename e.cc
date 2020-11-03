#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <vector>

#define ll long long
#define ar array 
using namespace std;

const int nxM=20;
int n, d[nxM];
ll ans[nxM];
vector<int> adj[nxM];


void dfs(int u=0, int p=-1){
    for(int v : adj[u]){
        if(v==p){
            continue;
        }
        dfs(v, u);
        d[u] = max(d[u] , d[v] + 1);
    }
}

bool greater2d(ar<int,2> a, ar<int,2> b){
    return a[1]>b[1];
}

void dfs2(int u=0, int p=-1,  int pd=0){
    ans[u] = max(d[u], pd);
    // cout << u << " pd " << pd << "\n";
    vector<ar<int,2>> w{{pd, -1}};
    for(int v:adj[u]){
        if(v==p){
            continue;
        }
        w.push_back({d[v]+1, v});
    }
    w.push_back({0, -1});
    sort(w.begin(), w.end(), greater<ar<int,2>>());

    for(int v : adj[u]){
        if(v==p){
            continue;
        }
        dfs2(v, u, (w[0][1]==v)?w[1][0]+1:w[0][0]+1);
    }
}

int main(){
    cin >> n;
    for(int i=1; i<n; ++i){
        int p, q;
        cin >> p >> q, --p, --q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    dfs();
    dfs2();
    for(int i=0; i<n; ++i)
        cout << ans[i] << " ";
}