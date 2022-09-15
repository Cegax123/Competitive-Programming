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

int f(int x) {
    if(x == 1) return 0;

    int cd = 0;
    while(x) {
        cd++;
        x /= 10;
    }
    return cd;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        multiset<int> a[15], b[15];

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a[f(x)].insert(x);
        }
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            b[f(x)].insert(x);
        }

        int ans = 0;

        for(int i = 14; i >= 1; i--) {
            for(int x : a[i]) {
                if(b[i].count(x)) {
                    b[i].erase(b[i].find(x));
                }
                else {
                    x = f(x);
                    a[f(x)].insert(x);
                    ans++;
                }
            }

            for(int x : b[i]) {
                x = f(x);
                b[f(x)].insert(x);
                ans++;
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


