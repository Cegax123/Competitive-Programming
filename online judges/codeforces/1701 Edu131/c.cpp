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

const int maxn = 2e5+5;

int n, m; 
int c[maxn];

bool comp(ll x) {
    ll curr = 0;

    for(int i = 0; i < n; i++) {
        if(x <= c[i]) {
            curr += c[i]-x;
        }
        else {
            curr -= (x-c[i])/2ll;
        }
    }

    return curr <= 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int a; cin >> a;
            a--;
            c[a]++;
        }

        int l = 0, r = 1e9;
        while(l < r) {
            int m = (l+r) >> 1;
            if(comp(m)) r = m;
            else l = m+1;
        }

        cout << l << "\n";

        for(int i = 0; i < n; i++)
            c[i] = 0;
    }

	
    return 0;
}


