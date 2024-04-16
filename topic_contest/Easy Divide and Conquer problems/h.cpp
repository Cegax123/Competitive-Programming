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

const int maxn = 2e5 + 5;

int a[maxn];
ll L[maxn], R[maxn];
int n;
ll t;

ll solve(int l, int r) {
    if(l == r) {
        L[l] = R[l] = a[l];
        return a[l] < t;
    }

    int m = (l+r) >> 1;

    ll ans = 0;
    ans += solve(l, m);
    ans += solve(m+1, r);

    int ind = m;

    for(int i = m+1; i <= r; i++) {
        while(ind >= l and L[i] + R[ind] >= t) ind--;
        ans += (ind-l+1);
    }

    ll sum = accumulate(a+l, a+m+1, 0ll);
    for(int i = m+1; i <= r; i++) L[i] += sum;

    sum = accumulate(a+m+1, a+r+1, 0ll);
    for(int i = m; i >= l; i--) R[i] += sum;

    ll tmp[r-l+1];

    merge(L+l, L+m+1, L+m+1, L+r+1, tmp);
    for(int i = l; i <= r; i++) L[i] = tmp[i-l];

    merge(R+l, R+m+1, R+m+1, R+r+1, tmp);
    for(int i = l; i <= r; i++) R[i] = tmp[i-l];

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> t;

    for(int i = 0; i < n; i++) cin >> a[i];

    cout << solve(0, n-1) << "\n";
	
    return 0;
}


