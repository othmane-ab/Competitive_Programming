#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=1000;
int n,q;
int mp[mxN][mxN];
vector <ar<int, 2>> e;
int is_visited[mxN][mxN];
int start_i,start_j,finish_i,finish_j;
ar<int,2> path[mxN][mxN];
int is_found;

void dfs(int a, int b){
    is_visited[a][b] = 1;
    // if(a==1&&b==6){
    //     int x=0;
    // }
    if(a==finish_i&&b==finish_j){
        // path[finish_i][finish_j] = {a,b};
        is_found=1;
    }else if(!is_found){
        if(a!=0&&mp[a-1][b]&&!is_visited[a-1][b]){
            dfs(a-1, b);
            path[a-1][b] = {a,b};
        }
        if(b!=0&&mp[a][b-1]&&!is_visited[a][b-1]){
            dfs(a, b-1);
            path[a][b-1] = {a,b};
        }
        if(mp[a+1][b]&&!is_visited[a+1][b]){
            dfs(a+1, b);
            path[a+1][b] = {a,b};
        }
        if(mp[a][b+1]&&!is_visited[a][b+1]){
            dfs(a, b+1);
            path[a][b+1] = {a,b};
        }   
    }
}

int main(){
    int n,m;
    char c;
    cin >> n >> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> c;
            if(c=='#'){
                mp[i][j] = 0;
            }else if(c=='.'){
                mp[i][j] = 1;
                e.push_back({i,j});
            }else if(c=='A'){
                mp[i][j] = 1;
                start_i = i;
                start_j = j;
            }else if(c=='B'){
                mp[i][j] = 1;
                finish_i = i;
                finish_j = j;
            }
        }
    }
    dfs(start_i, start_j);
    if(is_found){
        cout << "YES" << "\n";
        int k=finish_i,r=finish_j;
        vector<char> good_path;
        while(k!=start_i||r!=start_j){
            if(path[k][r][0]-k<0){
                good_path.push_back('D');
            }
            if(path[k][r][0]-k>0){
                good_path.push_back('U');
            }
            if(path[k][r][1]-r<0){
                good_path.push_back('L');
            }
            if(path[k][r][1]-r>0){
                good_path.push_back('R');
            }
            k = path[k][r][0];
            r = path[k][r][1];
        }
        int y=0;
        // reverse(good_path);
    }else{
        cout << "NO" << "\n";
    }
    

    int x=0;
    
}