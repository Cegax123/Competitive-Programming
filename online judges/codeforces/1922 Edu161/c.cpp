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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int tl[n], tr[n];

        tr[0] = 1;
        for(int i = 1; i+1 < n; i++) {
            if(a[i+1]-a[i] < a[i]-a[i-1]) tr[i] = 1;
            else tr[i] = a[i+1]-a[i];
        }

        tl[n-1] = 1;

        for(int i = n-2; i-1 >= 0; i--) {
            if(a[i]-a[i-1] < a[i+1]-a[i]) tl[i] = 1;
            else tl[i] = a[i]-a[i-1];
        }

        for(int i = 1; i+1 < n; i++)
            tr[i] += tr[i-1];

        for(int i = n-2; i >= 1; i--)
            tl[i] += tl[i+1];

        int q; cin >> q;
        while(q--) {
            int a, b; cin >> a >> b;
            a--; b--;
            if(a < b) {
                cout << tr[b-1]-(a == 0 ? 0 : tr[a-1]) << "\n";
            }
            else {
                cout << tl[b+1]-(a == n-1 ? 0 : tl[a+1]) << "\n";
            }
        }
    }

	
    return 0;
}


