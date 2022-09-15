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
        int n, m; cin >> n >> m;
        vector<string> s(n);
        vector<string> b(n-1);

        for(int i = 0; i < n; i++)
            cin >> s[i];

        for(int i = 0; i < n-1; i++)
            cin >> b[i];

        string ans = "";
        for(int i = 0; i < m; i++) {
            vi cnt(26, 0);

            for(int j = 0; j < n; j++) {
                cnt[s[j][i]-'a']++;
                if(j < n-1) cnt[b[j][i]-'a']--;
            }

            for(int j = 0; j < 26; j++)
                if(cnt[j]) ans += 'a'+j;
        }

        cout << ans << endl;
    }
	
	
	return 0;
}

