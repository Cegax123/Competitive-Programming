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
    int n, c, t; cin >> n >> c >> t;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    auto cmp = [&](int x) {
        int cnt = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if((a[i] + t - 1) / t > x) return false;
        }

        for(int i = 0; i < n; i++) {
            if((sum + a[i] + t - 1) / t > x) {
                sum = a[i];
                cnt++;

                if(cnt > c) return false;
            }
            else {
                sum += a[i];
            }
        }

        return true;
    };

    int l = 1, r = 1e9;

    while(l < r) {
        int m = (l+r) >> 1;
        if(cmp(m)) r = m;
        else l = m+1;
    }

    cout << l << "\n";
	
    return 0;
}


