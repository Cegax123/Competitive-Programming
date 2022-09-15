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
        vii l[n+1];
        
        for(int i = 1; i <= n; i++) {
            int b; cin >> b;
            
            int lo = 1, hi = n;

            while(lo < hi) {
                int m = (lo + hi + 1) >> 1;
                if(i/m < b) hi = m-1;
                else lo = m;
            }

            int L = lo;

            lo = 1, hi = n;
            
            while(lo < hi) {
                int m = (lo + hi) >> 1;
                if(i/m > b) lo = m+1;
                else hi = m;
            }

            l[lo].pb({L, i});
        }

        set<ii> s;
        int a[n+1];

        for(int i = 1; i <= n; i++) {
            for(ii x : l[i])
                s.insert(x);

            ii tmp = *s.begin();
            a[tmp.second] = i;

            s.erase(tmp);
        }

        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

	
    return 0;
}


