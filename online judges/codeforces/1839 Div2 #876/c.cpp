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
        int s[n];

        for(int i = 0; i < n; i++) cin >> s[i];

        if(s[n-1] == 1) {
            cout << "NO\n";
            continue;
        }

        vi c;

        int ind = 0;
        while(ind < n) {
            int curr = s[ind];
            int cnt = 0;
            while(ind < n and s[ind] == curr) {
                ind++;
                cnt++;
            }
            c.pb(cnt);
        }

        vi ans;
        int sum = n - c.back();
        c.pop_back();

        while(!c.empty()) {
            ans.pb(sum);
            sum -= c.back();
            c.pop_back();
        }

        while((int) ans.size() < n) ans.pb(0);

        reverse(all(ans));

        cout << "YES\n";
        for(int i = 0; i < n; i++) 
            cout << ans[i] << " ";
        cout << "\n";
    }

	
    return 0;
}


