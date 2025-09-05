#include <iostream>
#include <vector>
#include <functional>

#define rep(i, x) for(int i=0; i<x; i++)
#define ll long long

const ll MOD = 1E9+7;
using namespace std;

void _main(int tnum) {
    ll n;
    cin >> n;
    vector<vector<ll>> A(2, vector<ll> (2, 1));
    A[0][0] = 0;
    vector<vector<ll>> I(2, vector<ll> (2));
    I[0][0] = I[1][1] = 1;
   
    function<vector<vector<ll>>(ll)> matrixPow = [&](ll x) {
        if (x == 0) {
            return I;
        }
        auto half = matrixPow(x/2);
        vector<vector<ll>> ret(2, vector<ll> (2));
        rep(i, 2) {
            rep(j, 2) {
                rep(k, 2)
                    ret[i][j] += half[i][k]*half[k][j], ret[i][j] %= MOD;
            }
        }
        if (x & 1) {
            rep(i, 2) {
                vector<ll> o = ret[i];
                rep(j, 2) {
                    ret[i][j] = 0;
                    rep(k, 2) {
                        ret[i][j] += o[k]*A[k][j], ret[i][j] %= MOD;
                    }
                }
            }   
        }
        return ret;
    };
    auto ans = matrixPow(n);
 
    cout << ans[0][1] * ans[1][1] % MOD << endl;
}

int main() {
    _main(0);
    return 0;
}

// 2024KB	0ms