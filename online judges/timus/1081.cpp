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

const int maxn = 44;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<ll> f(maxn, 0);
    f[0] = 1;
    f[1] = 1;
    
    for(int i = 2; i < maxn; i++) {
        for(int j = 0; j <= i-2; j++)
            f[i] += f[j];
    }
    
    ll sum[maxn];
    sum[0] = f[0];

    for(int i = 1; i < maxn; i++)
        sum[i] = sum[i-1] + f[i];

    ll n, k; cin >> n >> k;

    if(k > sum[n]) {
        cout << "-1\n";
        return 0;
    }

    string ans = string(n, '0');

    while(k != 1) {
        if(k == 2) {
            ans[0] = '1';
            k--;

            continue;
        }

        for(int i = 0; i < maxn; i++) {
            if(sum[i] >= k) {
                ans[i-1] = '1';
                k -= f[i];
                k -= f[i-1];
                break;
            }
        }
    }

    reverse(all(ans));

    cout << ans << "\n";
	
    return 0;
}


