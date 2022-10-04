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

        int b[n+5];
        vi pos[n+5];
        set<int> s;

        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            s.insert(b[i]);
            pos[b[i]].pb(i);
        }

        int l = 0, r = n+1;
        int mxL = 0;
        vi a;

        while(true) {
            if(s.count(l)) {
                int y = -1;
                for(int x : pos[l]) {
                    if(s.count(x))
                        y = x;
                }

                s.erase(l);

                r = y;

                for(int x : pos[l])
                    if(x != y)
                        a.pb(x);

                if(y != -1) a.pb(y);
            }
            else if(s.count(r)) {
                int y = -1;
                for(int x : pos[r]) {
                    if(s.count(x)) 
                        y = x;
                    mxL = max(mxL, x);
                }

                s.erase(r);

                l = y;

                for(int x : pos[r])
                    if(x != y)
                        a.pb(x);

                if(y != -1) a.pb(y);
            }
            else break;
        }

        cout << mxL << "\n";
        for(int x : a)
            cout << x << " ";

        cout << "\n";
        
    }

	
    return 0;
}


