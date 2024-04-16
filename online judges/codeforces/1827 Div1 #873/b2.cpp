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
const int LOGN = 20;

ii ST[maxn][LOGN];

ii f(const ii& a, const ii& b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

void STBuild(const vi& v) {
    for(int i = 1; i <= (int) v.size(); i++) 
        ST[i][0] = {v[i-1], v[i-1]}; // Cuidado con los índices. Si 'a' es 0-indexado, entonces: ST[i][0] = a[i-1];

    for(int k = 1; (1 << k) <= (int) v.size(); k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= (int) v.size(); i++)
            ST[i][k] = f(ST[i][k-1], ST[i+dis][k-1]);
    }
}

ii STQuery(int L, int R) {
    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(ST[L][k], ST[R-dis+1][k]);
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        STBuild(a);

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            ans += i * 1ll * (n-i);
        }

        for(int i = 0; i < n; i++) {
            int l = 0, r = i;

            while(l < r) {
                int m = (l+r) >> 1;
                if(STQuery(m, i).second == a[i]) r = m;
                else l = m+1;
            }

            int k = l-1;

            if(k < 0) continue;

            l = 0, r = k;

            while(l < r) {
                int m = (l+r) >> 1;
                if(STQuery(m, k).first < a[i]) r = m;
                else l = m+1;
            }

            int x = l-1;

            l = i, r = n-1;

            while(l < r) {
                int m = (l+r+1) >> 1;
                if(STQuery(i, m).second == a[i]) l = m;
                else r = m-1;
            }

            int y = l+1;

            ans -= (k-x) * 1ll * (y-i);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


