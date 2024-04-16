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

const int maxn = 1e6 + 5;

int cnt[maxn], L[maxn], R[maxn];

ll solve(int l, int r) {
    if(l == r) return 0ll;
    
    int m = (l+r) >> 1;

    ll ans = 0;
    ans += solve(l, m);
    ans += solve(m+1, r);

    int ind = m+1;

    for(int i = l; i <= m; i++) {
        while(ind <= r and R[ind] < L[i]) ind++;
        ans += ind-(m+1);
    }

    vi tmpL(r-l+1), tmpR(r-l+1);

    merge(L+l, L+m+1, L+m+1, L+r+1, tmpL.begin());
    merge(R+l, R+m+1, R+m+1, R+r+1, tmpR.begin());

    for(int i = l; i <= r; i++) {
        L[i] = tmpL[i-l];
        R[i] = tmpR[i-l];
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vi d = a;

    sort(all(d));
    d.resize(unique(all(d)) - d.begin());

    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(all(d), a[i]) - d.begin();
    }

    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        L[i] = cnt[a[i]];
    }

    for(int i = 0; i < n; i++)
        cnt[i] = 0;

    for(int i = n-1; i >= 0; i--) {
        cnt[a[i]]++;
        R[i] = cnt[a[i]];
    }
    
    cout << solve(0, n-1) << "\n";
    
	
    return 0;
}


