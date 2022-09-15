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
        set<int> s;
        vi a;

        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;

            if(s.count(x)) continue;

            s.insert(x);
            a.pb(x);
        }
        
        sort(all(a));
        n = a.size();

        if(n == 1) {
            cout << "YES\n";
            continue;
        }

        if(a[0] == 0 and a[1] == 1) {
            cout << "NO\n";
        }
        else if(a[0] != 1) {
            cout << "YES\n";
        }
        else {
            bool cmp = 1; 

            for(int i = 1; i < n; i++)
                if(a[i]-a[i-1] == 1) cmp = 0;

            if(cmp) cout << "YES\n";
            else cout << "NO\n";
        }
    }
	
	return 0;
}

