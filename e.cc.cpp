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

