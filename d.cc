#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

const int nxM=100;
int n;
class node{
    public:
    int subordinates;
    node* boss;
};
node* e[nxM];


int main(){
    e[0] = new node();
    e[0]->subordinates = 0;
    e[0]->boss = NULL;
    e[1] = new node();
    e[1]->subordinates = 0;
    e[1]->boss = NULL;

    cin >> n;
    cout << n;
    for(int i=2; i<n+1; ++i){            
        int a;
        e[i] = new node();
        e[i]->subordinates = 0;
        cin >> a;
        e[i]->boss = e[a];
        for(node* p=e[i]->boss; p!=NULL; p=p->boss){
            p->subordinates += 1;
        }
    }
    for(int i=1; i<n+1; ++i){
        cout << e[i]->subordinates << " ";
    }
}