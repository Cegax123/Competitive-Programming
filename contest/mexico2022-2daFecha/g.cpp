#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 1e6+5;
const ll INF = (ll) 1e18;

int n;
ll a[maxn], x[maxn];
ll p1[2 * maxn], p2[2 * maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> x[i];

    p1[0] = 0;
    p1[1] = x[0];
    p1[2 * n] = INF;

    for(int i = 1; i < n; i++) {
        p1[2 * i] = p1[2 * i - 1] + a[i-1];
        p1[2 * i + 1] = p1[2 * i] + x[i];
    }

    p2[2 * n] = 0;
    p2[2 * n - 1] = x[n-1];

    for(int i = n-1; i > 0; i--) {
        p2[2 * i] = p2[2 * i + 1] + a[i-1];
        p2[2 * i - 1] = p2[2 * i] + x[i-1];
    }

    p2[0] = INF;

    auto get1 = [&](ll d) {
        int l = 0, r = 2 * n;

        while(l < r) {
            int m = (l+r)>>1;
            if(p1[m] >= d) r = m;
            else l = m+1;
        }

        return l;
    };

    auto get2 = [&](ll d) {
        int l = 0, r = 2 * n;

        while(l < r) {
            int m = (l+r+1)>>1;
            if(p2[m] >= d) l = m;
            else r = m-1;
        }

        return l;
    };

    //for(int i = 0; i <= 15; i++) {
        //cout << i << " " << get2(i) << endl;
    //}

    ll l = 0, r = (ll) 1e15;

    while(l < r) {
        ll m = (l+r)>>1;

        if(get1(m)-get2(m) >= 0) r = m;
        else l = m+1;
    }


    ll L = l;

    l = 0, r = (ll) 1e15;

    while(l < r) {
        ll m = (l+r+1) >> 1;


        if(get1(m)-get2(m) <= 0) l = m;
        else r = m-1;
    }

    ll R = l;

    if(get1(L) == get2(R) and (get1(L)&1)) cout << R-L+1 << "\n";
    else cout << 0 << "\n";
	
    return 0;
}


