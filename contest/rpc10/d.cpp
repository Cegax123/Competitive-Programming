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
    int n, m; cin >> n >> m;

    vector<ll> v(n), x(m);

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < m; i++) cin >> x[i];

    sort(all(x));

    ll ans = 0;

    ll sumL = 0;
    ll sumR = 0;
    for(int i = 0; i < n; i++) {
        if(i * 100 < x[0]) sumL += v[i];
        if(i * 100 > x[m-1]) sumR += v[i];
    }

    ans = max(sumL, sumR);

    for(int i = 0; i < m-1; i++) {
        int L = (x[i]+100-1)/100, R = x[i+1]/100;
        if(x[i] == L * 100) L++;
        if(x[i+1] == R * 100) R--;
    
        L = min(L, n-1), R = min(R, n-1);

        bool cmp = 0;

        if(L * 100 > x[i] and L * 100 < x[i+1] and R * 100 > x[i] and R * 100 < x[i+1]) cmp = 1;

        if(!cmp) continue;
        if(L > R) continue;

        vector<int> p, a;

        for(int j = L; j <= R; j++) {
            p.pb(j * 100);
            a.pb(v[j]);
        }

        //cout << "X: " << x[i] << " " << x[i+1] << endl;

        //for(int i = 0; i < (int) a.size(); i++) {
            //cout << a[i] << " " << p[i] << "\n";
        //}

        int k = a.size();

        vector<ll> sum(k);

        sum[0] = a[0];
        for(int i = 1; i < k; i++) {
            sum[i] = sum[i-1] + a[i];
        }

        for(int j = 0; j < k; j++) {
            int l1 = p[j], r1 = p[j]+(p[j]-x[i]);

            int lo = j, hi = k-1;

            while(lo < hi) {
                int mi = (lo+hi+1) >> 1;
                int l2 = p[mi]-(x[i+1]-p[mi]), r2 = p[mi];

                if(l2 < r1) lo = mi;
                else hi = mi-1;
            }

            int currR = lo;

            int L2 = p[lo]-(x[i+1]-p[lo]);
            L2 = max(L2, p[j]);

            lo = 0, hi = j;

            while(lo < hi) {
                int mi = (lo+hi) >> 1;
                if(L2-p[mi] < p[mi]-x[i]) hi = mi;
                else lo = mi+1;
            }

            int currL = lo;

            ans = max(ans, sum[currR]-sum[currL]+a[currL]);
        }

    }
    cout << ans << "\n";
	
    return 0;
}


