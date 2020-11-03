#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int t;
int main(){
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << ((a+b)%3==0&&2*a>=b&&2*b>=a?"YES":"NO") << "\n";
    }
}
