#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
int a[maxn];
ll p[maxn], s[maxn];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i];
    }

    for(int i = n; i >= 1; i--) {
        s[i] = s[i+1] + a[i];
    }

    ll ans = (ll) 1e18;

    for(int i = 2; i <= n-2; i++) {
        vector<pair<ll, ll>> L;

        int l = 1, r = i-1;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(p[m] < p[i]-p[m]) l = m;
            else r = m-1;
        }

        if(p[l] < p[i] - p[l]) L.push_back({p[l], p[i]-p[l]});
        
        l = 1, r = i-1;
        while(l < r) {
            int m = (l+r) >> 1;
            if(p[m] >= p[i]-p[m]) r = m;
            else l = m+1;
        }

        if(p[l] >= p[i] - p[l]) L.push_back({p[l], p[i]-p[l]});

        vector<pair<ll, ll>> R;
        l = i+2, r = n;
        while(l < r) {
            int m = (l+r) >> 1;
            if(s[m] < s[i+1]-s[m]) r = m;
            else l = m+1;
        }

        if(s[l] < s[i+1]-s[l]) R.push_back({s[l], s[i+1]-s[l]});

        l = i+2, r = n;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(s[m] >= s[i+1]-s[m]) l = m;
            else r = m-1;
        }

        if(s[l] >= s[i+1]-s[l]) R.push_back({s[l], s[i+1]-s[l]});


        for(auto& e : L) {
            for(auto& f : R) {
                vector<ll> c;
                c.push_back(e.first);
                c.push_back(e.second);
                c.push_back(f.first);
                c.push_back(f.second);

                sort(c.begin(), c.end());

                ans = min(ans, c[3] - c[0]);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
