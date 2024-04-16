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
        int a, b, c, d; cin >> a >> b >> c >> d;
        string s; cin >> s;

        int cnta = 0, cntb = 0;

        for(char c : s) {
            cnta += c == 'A';
            cntb += c == 'B';
        }

        if(cnta != (a + c + d) or cntb != (b + c + d)) {
            cout << "NO\n";
            continue;
        }

        int sum = 0;
        vi suma, sumb;

        int pos = 0;

        while(pos + 1 < (int) s.size()) {
            if(s[pos] == s[pos+1]) {
                pos++;
                continue;
            }

            int tmp = pos;
            int cnt = 1;

            while(pos + 1 < (int) s.size() and s[pos] != s[pos+1]) {
                pos++;
                cnt++;
            }

            if(cnt&1) sum += (cnt-1) / 2;
            else {
                if(s[tmp] == 'A') suma.pb(cnt/2);
                else sumb.pb(cnt/2);
            }
        }

        sort(all(suma));
        sort(all(sumb));
        
        for(int x : suma) {
            if(x <= c) c -= x;
            else sum += x-1;
        }

        for(int x : sumb) {
            if(x <= d) d -= x;
            else sum += x-1;
        }

        if(sum >= c + d) cout << "YES\n";
        else cout << "NO\n";

    }

	
    return 0;
}


