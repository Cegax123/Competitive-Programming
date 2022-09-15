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

const int maxn = 3e5+5;
const int INF = 1e6+5;

const int LOGN = 20;

int ST[maxn][LOGN][2];
int n;
int a[maxn];

// t[v][0] : min, t[v][1] = gcd

void build() {
    for(int i = 1; i <= n; i++) {
        ST[i][0][0] = ST[i][0][1] = a[i-1];
    }

    for(int k = 1; (1 << k) <= n; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis - 1 <= n; i++) {
            ST[i][k][0] = min(ST[i][k-1][0], ST[i+dis][k-1][0]);
            ST[i][k][1] = __gcd(ST[i][k-1][1], ST[i+dis][k-1][1]);
        }
    }
}

int get_min(int l, int r) {
    l++; r++;
    int d = r-l+1;
    int k = 31 - __builtin_clz(d);
    int dis = 1 << k;
    return min(ST[l][k][0], ST[r-dis+1][k][0]);
}

int get_gcd(int l, int r) {
    l++; r++;
    int d = r-l+1;
    int k = 31 - __builtin_clz(d);
    int dis = 1 << k;
    return __gcd(ST[l][k][1], ST[r-dis+1][k][1]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    int ans = -1;
    vi ansL;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build();
	
    for(int i = 0; i < n; i++) {
        int l = i, r = n-1;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(get_min(i, m) >= a[i]) l = m;
            else r = m-1;
        }

        r = l; l = i;
        
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(get_gcd(i, m) == a[i]) l = m;
            else r = m-1;
        }

        int R = l;

        l = 0, r = i;
        
        while(l < r) {
            int m = (l+r) >> 1;
            if(get_min(m, i) >= a[i]) r = m;
            else l = m+1;
        }

        r = i;

        while(l < r) {
            int m = (l+r) >> 1;
            if(get_gcd(m, i) == a[i]) r = m;
            else l = m+1;
        }
        
        int L = l;
        if(R - L > ans) {
            ans = R-L;
            ansL.clear();

            ansL.pb(L+1);
        }
        else if(R - L == ans) ansL.pb(L+1);
    }

    set<int> s;

    for(int L : ansL) s.insert(L);

    cout << s.size() << " " << ans << "\n";
    
    for(int L : s)
        cout << L << " ";
    
	
	return 0;
}

