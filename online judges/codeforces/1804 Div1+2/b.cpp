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
        int n, k, d, w; cin >> n >> k >> d >> w;
        int t[n];

        for(int i = 0; i < n; i++)
            cin >> t[i];

        int ind = 0;
        int ans = 0;

        while(ind < n) {
            ans++;
            int st = t[ind] + w;
            int fin = st + d;
            int num = k;

            while(num and ind < n and !(t[ind] > fin)) {
                num--;
                ind++;
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


