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

        vi cnts(3, 0), cntt(3, 0);

        for(int i = 0; i < n; i++) {
            cnts[s[i]-'a']++;
            cntt[t[i]-'a']++;
        }

        bool cmp = 1;

        for(int i = 0; i < 3; i++)
            if(cnts[i] != cntt[i])
                cmp = 0;

        if(!cmp) {
            cout << "NO\n";
            continue;
        }

        vi pos;

        for(int i = 0; i < n; i++) 
            if(s[i] != 'b') pos.pb(i);

        int ind = 0;
        for(int i = 0; i < n; i++) {
            if(t[i] != 'b') {
                if(s[pos[ind]] != t[i]) 
                    cmp = 0;

                if(t[i] == 'a') {
                    if(pos[ind] > i)
                        cmp = 0;
                }

                else {
                    if(pos[ind] < i)
                        cmp = 0;
                }

                if(cmp) ind++;
                else break;
            }
        }

        if(cmp) cout << "YES\n";
        else cout << "NO\n";
    }
	
    return 0;
}


