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
        vi cnt(n+1, 0), end(n+1, 0);
        int cut = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i and a[i] == a[i-1]) {
                cut++;
                end[a[i]] += 2;
            }
            cnt[a[i]]++;
        }

        end[a[0]]++;
        end[a[n-1]]++;

        int mx = *max_element(all(end));
        int mx_freq = *max_element(all(cnt));

        if(mx_freq > (n+1) / 2) {
            cout << -1 << "\n";
            continue;
        }

        cout << cut + max(0, mx - (cut+2)) << "\n";
    }

	
    return 0;
}


