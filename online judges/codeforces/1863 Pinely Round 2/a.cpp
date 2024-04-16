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
        int n, a, q; cin >> n >> a >> q;
        string s; cin >> s;

        int l = n-a;
        int cnt = 0;

        for(char c : s) if(c == '+') cnt++;

        bool cmp = true;
        if(cnt < l) cmp = false;

        if(!cmp) {
            cout << "NO\n";
            continue;
        }

        int na = 0;

        for(char c : s) {
            if(c == '+') {
                if(na) {
                    a++;
                    na--;
                }
                else {
                    a++;
                    l--;
                }
            }
            else {
                na++;
            }
        }

        if(l == 0) cout << "YES\n";
        else cout << "MAYBE\n";
    }

	
    return 0;
}


