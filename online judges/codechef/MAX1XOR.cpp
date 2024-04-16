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
        string s; cin >> s;

        vi a;
        a.pb(0);

        int cnt[2];
        cnt[0] = cnt[1] = 0;
        cnt[0]++;

        for(int i = 0; i < n-1; i++) {
            if(s[i] == '0') a.pb(a.back());
            else a.pb(1-a.back());
            cnt[a.back()]++;
        }

        cout << max(cnt[0], cnt[1]) << "\n";
    }

	
    return 0;
}


