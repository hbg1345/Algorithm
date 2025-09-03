#include <iostream>
#include <cmath>
#include <vector>

#define rep(i, x) for(int i=0; i<x; i++)
using namespace std;

void _main(int tnum) {
    int n, s;
    cin >> n >> s;
    int as = abs(s);
    int sum = n*(n-1)/2;
    if (sum < as) {
        cout << "NIE" << endl;
        return;
    }
    int d = sum - as;
    if (d & 1) {
        cout << "NIE" << endl;
        return;
    }
    d >>= 1;
    vector<int> diff(n-1, 1);
    rep(i, n-1) {
        if (d >= n-i-1)
            d -= n-i-1, diff[i] = -1;
    }
    int ans = 0;
    cout << ans << endl;
    rep(i, n-1)
        ans += diff[i], cout << (s < 0 ? -ans: ans) << endl;
}

int main() {
    _main(0);
    return 0;
}

// 2184KB	0ms