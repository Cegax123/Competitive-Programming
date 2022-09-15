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
	int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        int cnts[26], cntt[26];

        memset(cnts, 0, sizeof(cnts));
        memset(cntt, 0, sizeof(cntt));

        for(int i = 0; i < n; i++) {
            cnts[s[i]-'a']++;
            cntt[t[i]-'a']++;
        }

        bool cmp = 1;

        for(int i = 0; i < 26; i++)
            if(cnts[i] != cntt[i]) cmp = 0;

        if(!cmp) {
            cout << "NO\n";
            continue;
        }

        cmp = 0;

        for(int i = 0; i < 26; i++)
            if(cnts[i] > 1) cmp = 1;

        if(cmp) {
            cout << "YES\n";
            continue;
        }
        
        int nis = 0, nit = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(s[i] > s[j]) nis++;
                if(t[i] > t[j]) nit++;
            }
        }

        if((nis&1) == (nit&1)) cout << "YES\n";
        else cout << "NO\n";
    }
	
	return 0;
}