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
    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto f = [](int x, int y) {
        if(x < y) swap(x, y);

        if((x+1)/2 >= y) return (x+1)/2;

        int p = (2 * x - y - 1 + 2) / 3;
        return p + (y-p+1)/2;
    };

    int ans = (int) 1e9;
    for(int i = 0; i < n; i++) {
        if(i+2 < n) {
            int x = max(a[i], a[i+2]), y = min(a[i], a[i+2]);
            ans = min({ans, (x+1)/2 + (y+1)/2, 1 + x/2 + y/2});
        }
        if(i+1 < n) ans = min(ans, f(a[i], a[i+1]));
    }

    sort(all(a));

    ans = min(ans, (a[0]+1)/2 + (a[1]+1)/2);

    cout << ans << "\n";
	
    return 0;
}


