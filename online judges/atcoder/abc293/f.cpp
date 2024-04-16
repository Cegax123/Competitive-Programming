#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> get(ll n, ll b) {
    vector<ll> ans;
    while(n) {
        ans.push_back(n%b);
        n /= b;
    }
    return ans;
}

bool comp(vector<ll> x) {
    for(ll y : x)
        if(y >= 2) return 0;
    return 1;
}

ll f(ll n) {
    ll ans = 0;
    for(ll b = 2; b <= n; b++) {
        if(comp(get(n, b))) {
            ans++;
            cout << b << endl;
        }
    }
    return ans;
}

int main() {
    cout << f(145) << endl;


    return 0;
}

