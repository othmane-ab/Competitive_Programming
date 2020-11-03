#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;//ancestor p 
    char pch;//character pch of the edge from p to v for each vertex v
    int link = -1;//at each vertex we will store the suffix link link (or −1 if it hasn't been calculated yet)
    int go[K];//array go[k] the transitions in the machine for each symbol (again −1 if it hasn't been calculated yet).

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int main(){
    string s,p;
    cin >> s >> p;
    add_string(p);
    auto u = t[0];
    int e = 0;
    int ans=0;
    for(char c : s){
        if(u.next[c - 'a']==-1){
            u = t[0];
        }else{
            u = t[u.next[c-'a']];
            e++;
        }
        if(e==p.size()){
            ans++;
            // u = t[0];
            e=0;
        }
    }
    cout << ans;
    return 0;
}