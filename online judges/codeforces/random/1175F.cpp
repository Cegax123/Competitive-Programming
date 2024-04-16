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

const int maxn = 3e5 + 10;

int n;
int a[maxn];
int r[maxn];
int pr[maxn];
int pa[maxn];

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}

const int LOGN = 20;

ii ST[maxn][LOGN];

ii f(ii a, ii b) {
    return max(a, b);
}

void STBuild() {
    for(int i = 1; i <= n; i++) {
        ST[i][0] = {a[i], i};
    }

    for(int k = 1; (1 << k) <= n; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= n; i++)
            ST[i][k] = f(ST[i][k-1], ST[i+dis][k-1]);
    }
}

ii STQuery(int L, int R) {
    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(ST[L][k], ST[R-dis+1][k]);
}

ll solve(int l, int r) {
    if(l > r) return 0;
    if(l == r) {
        return a[l] == 1;
    }

    int mid = STQuery(l, r).second;
    int x = a[mid];
    ll curr = 0;

    if(mid-l <= r-mid) {
        for(int i = l; i <= mid; i++) {
            int R = i + x - 1;

            //if(x == 4) {
                //cout << i << " " << R << endl;
                //cout << (pa[R] ^ pa[i-1]) << "\n";
                //cout << pr[x] << endl;
            //}

            if(R >= mid and R <= r) {
                curr += (pa[R]^pa[i-1]) == pr[x];
            }
        }
    }
    else {
        for(int i = mid; i <= r; i++) {
            int L = i-x+1;

            if(L <= mid and L >= l) {
                curr += (pa[L-1] ^ pa[i]) == pr[x];
            }
        }
    }

    //cout << l << " " << r << " " << mid << " " << curr << "\n";

    return curr + solve(l, mid-1) + solve(mid+1, r);
    
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        r[i] = random(0, 1e9);
        pr[i] = r[i] ^ pr[i-1];
    }

    for(int i = 1; i <= n; i++) {
        pa[i] = r[a[i]] ^ pa[i-1];
    }

    STBuild();

    cout << solve(1, n) << "\n";
	
    return 0;
}


