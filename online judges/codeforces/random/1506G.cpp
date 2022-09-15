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

const int E = 26;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();

        vector<vi> nxt(n+1, vi(E, INF));
        vector<vi> cnt(n, vi(E, 0));

        for(int i = n-1; i >= 0; i--) {
            cnt[i][s[i]-'a']++;

            for(int j = 0; j < E; j++)
                nxt[i][j] = nxt[i+1][j];

            nxt[i][s[i]-'a'] = i;
        }

        for(int i = 1; i < n; i++)
            for(int j = 0; j < E; j++)
                cnt[i][j] += cnt[i-1][j];

        vector<bool> deleted(E, 0);

        for(int i = 0; i < E; i++)
            if(cnt[n-1][i] == 0) deleted[i] = 1;

        string ans = "";

        int i = 0;
        
        while(i < n) {
            bool found = 0;

            for(int j = E-1; j >= 0; j--) {
                if(nxt[i][j] == INF or deleted[j]) continue;

                int p = nxt[i][j];

                bool cmp = 1;

                for(int k = 0; k < E; k++) {
                    if(deleted[k]) continue;

                    int L = (p ? cnt[p-1][k] : 0) - (i ? cnt[i-1][k] : 0);
                    if(L) {
                        int R = cnt[n-1][k] - (p ? cnt[p-1][k] : 0);

                        if(R == 0) cmp = 0;
                    }
                }

                if(cmp) {
                    ans += 'a'+j;

                    deleted[j] = 1;

                    i = p+1;
                    found = 1;

                    break;
                }
            }

            if(!found) break;
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}

