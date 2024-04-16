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
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int r[n+1];
        r[n] = 0;
        int tot = 0;

        for(int i = n-1; i >= 0; i--) {
            tot += s[i] == 'B';
            r[i] = s[i] == 'B';
            r[i] += r[i+1];
        }

        if(tot == k) {
            cout << 0 << "\n";
            continue;
        }

        if(k == 0) {
            cout << 1 << "\n";
            cout << n << " A\n";
            continue;
        }

        bool found = false;

        for(int i = 0; i <= n; i++) {
            if(r[i] == k) {
                cout << 1 << "\n";
                cout << i << " A\n";
                found = true;
                break;
            }

            if(r[i] + i == k) {
                cout << 1 << "\n";
                cout << i << " B\n";
                found = true;
                break;
            }
        }

        if(found) continue;
        cout << 2 << "\n";
        cout << n << " A\n";
        cout << k << " B\n";

    }

	
    return 0;
}


