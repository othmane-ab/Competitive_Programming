// Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

// Input

// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.

// Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.

// Every road is between two different cities, and there is at most one road between any two cities.

// Output

// First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.

// If there are no solutions, print "IMPOSSIBLE".

// Constraints
// 1≤n≤105
// 1≤m≤2⋅105
// 1≤a,b≤n
// Example

// Input:
// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5

// Output:
// 4
// 3 5 1 3


//round trip
// Question is about finding cycle.We will run a dfs an keep vector VIS
// to keep track of the nodes in the recusion stack.If we are at node p
// we will run dfs no all of its childs if any of the child is in recursion
// stack we will add this vertex to an array CYCLE . Now we will also keep
// track of where to end cycle by TILL . If current is equal to TILL return from all dfs's else return TILL

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
 
int n, m;
int start, finish;
vector<vector<int>> g;
vector<int> is_visited;
vector<int> parent;
 
 
bool dfs(int u, int p)
{
	is_visited[u] = true;
	parent[u] = p;
	for(auto v: g[u])
	{
		if(v == p) continue;
		if(is_visited[v]) 
		{
			start = v; 
			finish = u; 
			return true;
		} 
		if(!is_visited[v]) 
			if(dfs(v,u)) 
				return true;
	}
	return false;
}
 
 
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!is_visited[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	is_visited.resize(n+1);
	parent.resize(n+1);
	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	if(!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	int tv = finish;
	vector<int> ans;
	ans.push_back(finish);
	while(tv != start)
	{
		ans.push_back(parent[tv]);
		tv = parent[tv];
	}
	ans.push_back(finish);
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		cout << c << " ";
	}
 
}


// #include <bits/stdc++.h> 
 
// #define ll long long
// #define ar array 
// using namespace std;
// const int mxN=1e5;
// vector<int> g[mxN];

// int m,n,a,b;
// int is_visited[mxN];
// int parent[mxN];
// vector<int> cycle;
// int start,finish;

// int dfs(int u, int p){
//     parent[u] = p;
//     for(int c:g[u]){
//         if(c==p) continue;
//         if(!is_visited[c]){
//             is_visited[c] = 1;
//             if(dfs(c, u)){
//                 return 1;
//             }
//         }else{
//             start = c;
//             finish = u;
//             return 1;
//         }
//     }
//     return 0;
// }

// int main(){
//     cin >> n >> m;
//     for(int i=0;i<m;++i){
//         cin >> a >> b, --a, --b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     is_visited[0] = 1;
//     dfs(0, 0);
//     cycle.push_back(finish);
//     int c = finish;
//     while(c!=start){
//         cycle.push_back(parent[c]);
//         c = parent[c];
//     }
//     cout << cycle.size() << "\n";
//     for(int i:cycle){
//         cout << i+1 << " ";
//     }
// }