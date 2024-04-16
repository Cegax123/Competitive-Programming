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
        vi a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vi b = a;
        sort(all(b));

        if(b[n-1] == b[n-2]) {
            int cnt = 0;
            for(int x : b)
                cnt += x == b[n-1];

            if(cnt <= (n+1) / 2) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            int cnt = 0;
            for(int x : b)
                cnt += (x == b[n-1]) or (x == b[n-2]);
            if(cnt < n) cout << "YES\n";
            else cout << "NO\n";
        }
    }

	
    return 0;
}


