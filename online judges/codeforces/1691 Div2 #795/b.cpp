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

        for(int i = 0; i < n; i++)
            cin >> a[i];

        bool cmp = 1;

        vi ans;
        int ind = 0;
        while(ind < n) {
            int l = ind;
            while(ind < n and a[ind] == a[l]) {
                ind++;
            }
            int r = ind-1;

            if(r == l) {
                cmp = 0;
            }

            for(int i = l+1; i <= r; i++)
                ans.pb(i+1);
            ans.pb(l+1);
        }

        if(cmp == 0)
            cout << -1 << "\n";
        else {
            for(int x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }

	
	
    return 0;
}


