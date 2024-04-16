#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_palindromic(ll x) {
    vector<int> dig;

    while(x) {
        dig.push_back(x%10);
        x /= 10;
    }

    int k = dig.size();
    for(int i = 0; i < k; i++) {
        if(dig[i] != dig[k-1-i]) return false;
    }

    return true;
}

int main() {
    ll n; cin >> n;

    ll ans = 1;

    for(ll i = 1; i * i * i <= n; i++) {
        if(is_palindromic(i*i*i)) ans = i*i*i;
    }

    cout << ans << "\n";

    return 0;
}
