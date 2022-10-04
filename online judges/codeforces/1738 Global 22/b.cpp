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
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        ll s[k];
        for(int i = 0; i < k; i++) 
            cin >> s[i];

        if(k == 1) {
            cout << "Yes\n";
            continue;
        }

        vector<ll> a;

        for(int i = 0; i < k-1; i++)
            a.pb(s[i+1]-s[i]);

        bool flag = 1;

        for(int i = 1; i < (int) a.size(); i++) {
            if(a[i] < a[i-1]) flag = 0;
        }

        if(!flag) {
            cout << "No\n";
            continue;
        }
        
        ll lft = n-k+1;

        bool found = 0;
        
        ll x = s[0] / lft;
        ll y = s[0] - (lft-1) * x;
        if(max(x, y) <= a[0]) found = 1;

        x = (abs(s[0]) + lft - 1) / lft;
        if(s[0] < 0) x = -x;
        y = s[0] - (lft-1) * x;

        if(max(x, y) <= a[0]) found = 1;

        
        if(found) cout << "Yes\n";
        else cout << "No\n";
    }

	
    return 0;
}


