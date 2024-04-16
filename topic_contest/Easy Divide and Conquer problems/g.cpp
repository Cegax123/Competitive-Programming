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

const int maxn = 1e5 + 5;

int n, k;
ll a, b;
int c[maxn];

int get_cnt(int l, int r) {
    int L = 0, R = k-1;

    while(L < R) {
        int m = (L+R) >> 1;
        if(c[m] >= l) R = m;
        else L = m+1;
    }

    if(c[L] < l) return 0;

    int tL = L;

    L = 0, R = k-1;

    while(L < R) {
        int m = (L+R+1) >> 1;
        if(c[m] <= r) L = m;
        else R = m-1;
    }

    if(c[L] > r) return 0;

    return L-tL+1;
}

ll solve(int l, int r) {
    int cnt = get_cnt(l, r);
    //cout << l << " " << r << " " << cnt << endl;

    if(cnt == 0) return a;

    if(l == r) {
        return b * cnt;
    }

    int m = (l+r) >> 1;

    return min(b * cnt * (r-l+1), solve(l, m) + solve(m+1, r));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> a >> b;

    for(int i = 0; i < k; i++)
        cin >> c[i];

    sort(c, c+k);

    cout << solve(1, (1 << n)) << "\n";
	
    return 0;
}


