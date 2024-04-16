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
        int n; cin >> n;
        string s, t; cin >> s >> t;

        map<ii, int> cnt;

        for(int i = 0; i < n; i++) {
            int x = max(s[i]-'a', t[n-1-i]-'a');
            int y = min(s[i]-'a', t[n-1-i]-'a');
            cnt[{y, x}]++;
        }

        int cnt_odd = 0;
        bool cmp = 1;

        for(auto e : cnt) {
            if(e.first.first == e.first.second) {
                if(e.second&1) cnt_odd++;
            }
            else {
                if(e.second&1) cmp = 0;
            }
        }

        if(n&1) {
            if(cnt_odd != 1) cmp = 0;
        }
        else {
            if(cnt_odd != 0) cmp = 0;
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


