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
        int n; ll k; cin >> n >> k;
        string a[n], b[n];
        vi cnta(10, 0), cntb(10, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(char c : a[i])
                cnta[c-'0']++;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            for(char c : b[i])
                cntb[c-'0']++;
        }

        bool cmp = 1;
        for(int i = 0; i < n; i++) {
            if(a[i].size() != b[i].size()) cmp = 0;
        }

        if(!cmp) {
            cout << "NO\n";
            continue;
        }

        ll ans = 0;

        for(int i = 0; i < 10; i++)
            ans += max(0, cnta[i]-cntb[i]);

        if(ans <= k) cout << "YES\n";
        else cout << "NO\n";
    }

	
    return 0;
}


