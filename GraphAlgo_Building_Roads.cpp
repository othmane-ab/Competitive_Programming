// Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.

// Your task is to find out the minimum number of roads required, and also determine which roads should be built.

// Input

// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.

// After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.

// A road always connects two different cities, and there is at most one road between any two cities.

// Output

// First print an integer k: the number of required roads.

// Then, print k lines that describe the new roads. You can print any valid solution.

// Constraints
// 1≤n≤105
// 1≤m≤2⋅105
// 1≤a,b≤n
// Example

// Input:
// 4 2
// 1 2
// 3 4

// Output:
// 1
// 2 3

// building roads
// The problem is basically connecting the disconnected components.
// do dfs on all unvisited nodes and save one node from each
// connected component as a head node.Then if there are k connected
// components connect their head node via k-1 edges between heads

#include <bits/stdc++.h> 

#define ll long long
#define ar array 
using namespace std;

const int mxN=1e5;

int n,m;
vector<int> g[mxN];
int a,b;
int is_visited[mxN];
vector<int> heads;

void dfs(int s){
    if(!is_visited[s]){
        is_visited[s] = 1;
        for(int a:g[s]){
            dfs(a);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin >> a >> b, --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0; i<n; ++i){
        if(!is_visited[i]){
            heads.push_back(i);
            dfs(i);
        }
    }

    cout << heads.size() - 1 << "\n";
    int prev = -1;
    for(int a:heads){
        if(prev==-1){
            prev = a;
        }else{
            cout << prev + 1<< " " << a + 1 << "\n";
        }
    }
}