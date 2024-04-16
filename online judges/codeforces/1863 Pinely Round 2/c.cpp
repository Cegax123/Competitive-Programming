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
        vector<bool> marked(n+1, 0);
        int a[n+1];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            marked[a[i]] = 1;
        }

        for(int i = 0; i <= n; i++) if(!marked[i]) a[n] = i;

        k %= (n+1);
        if(k == 0) k = n+1;

        int st = n+1 - k;

        for(int i = 0; i < n; i++) {
            cout << a[(st + i) % (n+1)] << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


