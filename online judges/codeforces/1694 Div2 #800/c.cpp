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
        ll a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if(a[0] < 0) {
            cout << "No\n";
            continue;
        }

        ll sum = 0;
        bool last_pos = 1;
        bool cmp = 1;

        for(int i = n-1; i >= 0; i--) {
            if(a[i] <= 0) {
                sum -= a[i];
                continue;
            }
            if(i == 0) {
                sum -= a[i];
            }
            else if(last_pos) {
                ll to_give = a[i] + 1;
                if(sum < to_give) {
                    cmp = 0;
                }
                else {
                    sum -= to_give;
                }
                last_pos = 0;
                a[0]--;
            }
            else {
                if(sum < a[i]) cmp = 0;
                else sum -= a[i];
            }
        }

        if(sum == 0 and cmp) cout << "Yes\n";
        else cout << "No\n";
    }

	
    return 0;
}


