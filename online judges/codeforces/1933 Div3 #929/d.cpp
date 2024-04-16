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
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a, a+n);
        bool cmp = 0;

        if(a[0] < a[1]) cmp = 1;

        for(int i = 0; i < n; i++) {
            if(a[i] % a[0] != 0) cmp = 1;
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


