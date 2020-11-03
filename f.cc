#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <cstring>
 
 
using namespace std;
 
const int nxM=10;//1e5;
const int mxM=10;//2e5;
int n,m;
int a,b;
int id_group[nxM];
int d;
int visited[nxM],visited2[nxM];
 
vector<int> adj[nxM];
 
void dfs(int u=0, int p=-1){
    if (visited[u]==0){
        id_group[u] = d;
        d++;
    }
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v]==0){
            dfs(v, u);
        }
        id_group[u] = min(id_group[u],id_group[v]);
    }
}
void dfs2(int u, int p=-1, int id){
    visited2[u] = 1;
    for(int v: adj[u]){
        if((visited2[1]==0)&&(id_group[v]==id)){
            dfs2(v, u, id);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
    }
    dfs();
    for(int i=0; i<n; ++i){
        cout << id_group[i] << "\n";
    }
    int is_seen_group[nxM];
    for(int i=0; i<n; ++i){
        if(is_seen_group[id_group[i]]==0){
            
        }
    }
    

}