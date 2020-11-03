#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll n;
vector<ll> set_1;
vector<ll> set_2;
ll last = -1;

int main(){
    cin >> n;
    ll s = n*(n+1)/2;
    if(s%2==1){
        cout << "NO";
    }else{
        cout << "YES" << "\n";
        s = s/2;
        ll s_ = 0;
        for(ll i=n; i>0; --i){
            if(s-s_-i>=0){
                s_ += i;
                set_1.push_back(i);
            }else{
                if(last==-1){
                    if(s - s_!=0){
                        set_1.push_back(s - s_);
                        last = s - s_;
                        s_ += last;
                    }
                }
                if(i!=last){
                    set_2.push_back(i);
                }
            }
        }
        cout << set_1.size() << "\n";
        for(ll i: set_1){
            cout << i << " ";
        }
        cout << "\n" << set_2.size() << "\n";
        for(ll i: set_2){
            cout << i << " ";
        }

    }
}