#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    string s;
    cin >> s;
    auto z_vector = z_function(s);
    int i=1;
    for (auto it = z_vector.rbegin(); it != z_vector.rend(); ++it){
        if(i==*it){
            cout << *it << " ";
        }
        ++i;
    }
}