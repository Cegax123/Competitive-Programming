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
        vii a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(all(a));

        reverse(all(a));

        ll sum[n];
        sum[n-1] = a[n-1].first;

        for(int i = n-2; i >= 0; i--)
            sum[i] = sum[i+1] + a[i].first;

        int ind = 0;

        int ans[n];

        while(ind < n) {
            int r = ind;
            while(r < n and a[r].first == a[ind].first) {
                r++;
            }
            r--;
            
            if(ind == 0) {
                for(int j = ind; j <= r; j++) {
                    ans[a[j].second] = n-1;
                }
            }
            else {
                int nans;
                if(sum[ind] >= a[ind-1].first) nans = ans[a[ind-1].second]+1;
                else nans = n-ind;

                for(int j = ind; j <= r; j++)
                    ans[a[j].second] = nans-1;
            }
            ind = r+1;
        }

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }

	
    return 0;
}


