// There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.

// Input

// The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,…,n.

// Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.

// Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.

// Output

// Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.

// If there are no solutions, print "IMPOSSIBLE".

// Constraints
// 1≤n≤105
// 1≤m≤2⋅105
// 1≤a,b≤n
// Example

// Input:
// 5 3
// 1 2
// 1 3
// 4 5

// Output:
// 1 2 2 1 2

// building teams
// The question is about coloring the bipartite graphs more about it.
// we try to color all vertex greedily if vertex is not visited color
// it white and run dfs . now color all its uncolored neighbors of white vertex
// black and vice versa and run dfs on them.
// at last check that each edge has ends with different colors.

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;

const int mxN=1e5;

vector<int> g[mxN];
int n,m,a,b;
int is_visited[mxN];
int team[mxN];
int is_impossible;

void dfs(int p){
    for(int u:g[p]){
        if(!is_visited[u]){
            is_visited[u] = 1;
            team[u] = (team[p]==1)?2:1;
            dfs(u);
        }else{
            if(team[u]==team[p]){
                is_impossible = 1;
                return;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin >> a >> b, --b, --a;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;++i){
        if((!is_visited[i])&&(!is_impossible)){
            team[i] = 1;
            dfs(i);
        }
    }
    if(is_impossible){
        cout << "IMPOSSIBLE";
    }else{
        for(int i=0; i<n; ++i){
            cout << team[i] << " ";
        }
    }

}
