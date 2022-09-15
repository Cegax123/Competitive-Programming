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

vector<int> z_function(const string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

const int maxn = 1000000;
const int mod = 998244353;

int lazy[4 * maxn];

void push(int v) {
    lazy[v * 2] = (lazy[v * 2] + lazy[v]) % mod;
    lazy[v * 2 + 1] = (lazy[v * 2 + 1] + lazy[v]) % mod;
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(r < tl or tr < l) return;
    if(tl == l and r == tr) {
        lazy[v] = (lazy[v] + x) % mod;
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), x);
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r, x);
    }
}

int query(int v, int tl, int tr, int pos) {
    if(tl == tr)
        return lazy[v];
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        if(pos <= tm) return query(v * 2, tl, tm, pos);
        else return query(v * 2 + 1, tm + 1, tr, pos);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s, l, r; cin >> s >> l >> r;
    int n = s.size();
    int szl = l.size();
    int szr = r.size();

    vi L = z_function(l + "#" + s);
    vi R = z_function(r + "#" + s);

    int tl[n], tr[n];

    memset(tl, 0, sizeof(tl));
    memset(tr, 0, sizeof(tr));

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if(l == "0") tl[i] = tr[i] = 1;
            else tl[i] = tr[i] = 0;
            continue;
        }

        if(n-i < (int) l.size()) continue;
        int lenL = L[szl + i + 1];

        if(lenL == szl) tl[i] = szl;
        else {
            if(s[i + lenL] > l[lenL]) tl[i] = szl;
            else tl[i] = szl+1;
        }

        if(n-i < (int) r.size()) tr[i] = n-i;
        else {
            int lenR = R[szr + i + 1];

            if(lenR == szr) tr[i] = szr;
            else {
                if(s[i + lenR] < r[lenR]) tr[i] = szr;
                else tr[i] = szr-1;
            }
        }


        if(tl[i] > tr[i]) tl[i] = tr[i] = 0;
    }

    //for(int i = 0; i < n; i++)
        //cout << tl[i] << " " << tr[i] << "\n";
    
    if(tl[0]) update(1, 0, n-1, tl[0]-1, tr[0]-1, 1);
    
    for(int i = 1; i < n; i++) {
        int x = query(1, 0, n-1, i-1);
        if(tl[i]) update(1, 0, n-1, i+tl[i]-1, i+tr[i]-1, x);
    }

    cout << query(1, 0, n-1, n-1) << "\n";

	return 0;
}


