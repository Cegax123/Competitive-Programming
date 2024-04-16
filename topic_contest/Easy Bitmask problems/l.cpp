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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    int a[n];

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    int pos[1 << n];
    for(int i = 0; i < n; i++)
        pos[1 << i] = i;

    ll x[1 << n];
    x[0] = 0;

    for(int i = 1; i < (1 << n); i++) {
        x[i] = x[i&(i-1)] ^ a[pos[i&(-i)]];
    }

    for(int i = 0; i < n; i++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            if(mask & (1 << i))
                x[mask] += x[mask ^ (1 << i)];
        }
    }

    while(q--) {
        string s; cin >> s;

        int mask = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') mask ^= (1 << i);
        }

        cout << x[mask] << "\n";
    }
	
    return 0;
}


