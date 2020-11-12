// Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

// Input

// The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,…,n. Uolevi's computer is 1 and Maija's computer is n.

// Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.

// Every connection is between two different computers, and there is at most one connection between any two computers.

// Output

// If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.

// If there are no routes, print "IMPOSSIBLE".

// Constraints
// 2≤n≤105
// 1≤m≤2⋅105
// 1≤a,b≤n
// Example

// Input:
// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4

// Output:
// 3
// 1 4 5

// Idea
// 1 use djiskstra ---> too much time
// 2 start a bfs from 1 and
// also keep vector FRM to know from where the currentde is reached
// and at last if n is visited go in reverse order using FRM to recreate path

#include <bits/stdc++.h> 

#define ll long long
#define ar array 
using namespace std;

const int mxN=1e5;
int n,m;
int frm[mxN];
vector<int> g[mxN];
int is_visited[mxN];
int a,b;

void bfs(int root){
    list<int> qu;
    qu.push_back(root);
    is_visited[root] = 1;

    while(!qu.empty()){
        int c = qu.front();
        qu.pop_front();
        for(auto i: g[c]){
            if(!is_visited[i]){
                is_visited[i] = 1;
                frm[i] = c;
                qu.push_back(i);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> a >> b, --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    int c = n-1;
    if( (frm[c]==0) && (find(g[0].begin(), g[0].end(), c)==g[0].end()) ){
        cout << "IMPOSSIBLE";
    }else{
        vector<int> ans;
        while(c!=0){
            ans.push_back(c);
            c = frm[c];
        }
        ans.push_back(0);
        cout << ans.size() << "\n";
        for(auto it=ans.crbegin(); it!=ans.crend(); ++it){
            cout << *it+1 << " ";
        }
    }
}