#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=2e5, mxX=1e9;
int x[mxN];
ll b_x[450];
int n,q;
ll ans;

int main(){
    cin >> n >> q;
    int len = (int) sqrt(n + .0) + 1;
    for(int i=0; i<n; ++i){
        cin >> x[i];
    }
    cout << "\n";
    int t,a,b,u;
    while(q--){
        cin >> t >> a, --a;
        if(t==1){
            cin >> b >> u, --b;
            for(int i=a; i<=b; ){
                if(i%len==0 & i+len-1<=b){
                    b_x[i/len] += u;
                    i += len;
                }else{
                    x[i]+=u;
                    ++i;
                }
            }
        }else if(t==2){
            cout << x[a]+b_x[a/len] << "\n";
        }
    }
    return 0;
}

// forest queries
// 0 1 0 0
// 1 2 3 4
// 2 4 0 0
// 0 0 0 0

//preprocessing
//x[i][j] = input[i][j] + x[i-1][j] + x[i][j-1] - x[i-1][j-1]
// ans
// x[y2][x2] - x[y2][x1-1] - x[y1-1][x2]

// hotel queries
// sort the hotels by available rooms
// for each group 
    // do a binary search to find the first hotel able to accomodate // log n
    // decrease the hotel's availability and re-sort // log n

// counting rooms
// For each unvisited '.' cell we have fto make ds(or bfs)
// and keep on coloring the visited nodes.We keep track number
// of dfs by count variable .our answer would be count.


// labyrinth
// We will store the coordinates of a and b ,now we start bfs
// from a and try to reach b. We will keep a vector FRM and
// DIR which will keep track of the cell from which we came here
// and what is the direction of that move .At last if b is visited
// we will go in reverse order by using FRM and try to recreate the path.


// building roads
// The problem is basically connecting the disconnected components.
// do dfs on all unvisited nodes and save one node from each
// connected component as a head node.Then if there are k connected
// components connect their head node via k-1 edges between heads

// message route
// This  noquestion is similar to Labyrinth ,start a bfs from 1 and
// also keep vector FRM to know from where the currentde is reached
// and at last if n is visited go in reverse order using FRM to recreate path

// building teams
// The question is about coloring the bipartite graphs more about it.
// we try to color all vertex greedily if vertex is not visited color
// it white and run dfs . now color all its uncolored neighbors of white vertex
// black and vice versa and run dfs on them.
// at last check that each edge has ends with different colors.

// 1 4 
// 2 3 5

//round trip
// Question is about finding cycle.We will run a dfs an keep vector VIS
// to keep track of the nodes in the recusion stack.If we are at node p
// we will run dfs no all of its childs if any of the child is in recursion
// stack we will add this vertex to an array CYCLE . Now we will also keep
// track of where to end cycle by TILL . If current is equal to TILL return from all dfs's else return TILL