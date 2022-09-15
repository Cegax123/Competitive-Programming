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
        int a[n+1];
        vi ind;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == i)
                ind.pb(i);
        }

        if(n == 1) {
            cout << -1 << "\n";
            continue;
        }

        vector<bool> used(n+1, 0);
        int b[n+1];
        memset(b, -1, sizeof(b));
    
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(used[j] or j == a[i]) 
                    continue;

                b[i] = j;
                used[j] = 1;
                break;
            }
        }

        if(b[n] == -1) {
            b[n] = b[n-1];
            b[n-1] = n;
        }

        for(int i = 1; i <= n; i++)
            cout << b[i] << " ";

        cout << "\n";
    }

	
	
    return 0;
}


