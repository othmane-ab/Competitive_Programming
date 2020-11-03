#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=1000;
int n,q;
int x[mxN ][mxN];

int main(){
    char c;
    int in;
    cin >> n >> q;
    for(int  i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> c;
            in = (int)(c=='*');
            if(i==0&&j==0){
                x[0][0] = in;
            }else if(i==0){
                x[0][j] = in + x[0][j-1];
            }else if(j==0){
                x[i][0] = in + x[i-1][0];
            }else{
                x[i][j] = in + x[i-1][j] + x[i][j-1] - x[i-1][j-1];
            }
        }
    }
    int y1,x1,y2,x2;
    while(q--){
        cin >> y1 >> x1 >> y2 >> x2, --y1, --x1, --y2, --x2;
        cout << x[y2][x2] - x[y2][x1-1] - x[y1-1][x2] + x[y1-1][x1-1] << "\n";
    }
    
    
}
// 4 3
// .*..
// *.**
// **..
// ****
// 2 2 3 4
// 3 1 3 1
// 1 1 2 2

// forest queries
// 0 1 0 0
// 1 2 3 4
// 2 4 0 0
// 0 0 0 0

//preprocessing
//x[i][j] = input[i][j] + x[i-1][j] + x[i][j-1] - x[i-1][j-1]
// ans
// x[y2][x2] - x[y2][x1-1] - x[y1-1][x2]