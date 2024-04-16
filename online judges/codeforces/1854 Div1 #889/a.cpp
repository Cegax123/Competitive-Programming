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
        int a[n];
        bool only_neg = true;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > 0) only_neg = false;
        }

        if(only_neg) {
            cout << n-1 << "\n";
            for(int i = n-1; i >= 1; i--)
                cout << i << " " << i+1 << "\n";
            continue;
        }

        int idx = -1;
        for(int i = 0; i < n; i++)
            if(a[i] > 0) idx = i;

        cout << 2 * n + 5 << "\n";
        for(int i = 0; i < 5; i++)
            cout << idx+1 << " " << idx+1 << "\n";

        for(int i = 0; i < n; i++) {
            cout << i+1 << " " << idx+1 << "\n";
        }

        for(int i = 1; i < n; i++) {
            cout << i+1 << " " << i << "\n";
        }
    }

	
    return 0;
}


