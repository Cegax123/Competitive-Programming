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

struct Oper {
    int l, r, d;
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, k; cin >> n >> m >> k;

    vector<ll> a(n+1, 0);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<Oper> oper(m);

    for(int i = 0; i < m; i++) {
        cin >> oper[i].l >> oper[i].r >> oper[i].d;
        oper[i].l--; oper[i].r--;
    }

    vi cnt(m+1, 0);
	
    for(int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        cnt[l]++;
        cnt[r+1]--;
    }


    for(int i = 1; i <= m; i++)
        cnt[i] += cnt[i-1];

    vector<ll> add(n+1, 0);

    for(int i = 0; i < m; i++) {
        add[oper[i].l] += (ll) cnt[i] * oper[i].d;
        add[oper[i].r+1] -= (ll) cnt[i] * oper[i].d;
    }

    for(int i = 1; i <= n; i++)
        add[i] += add[i-1];

    for(int i = 0; i < n; i++) {
        add[i] += a[i];
        cout << add[i] << " ";
    }
	
	return 0;
}

