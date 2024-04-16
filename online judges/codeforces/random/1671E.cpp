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

int cmp(const string& a, const string& b) {
    for(int i = 0; i < (int) a.size(); i++) {
        if(a[i] > b[i]) return -1;
        else if(a[i] < b[i]) return 1;
    }
    return  0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;

    int f[1 << n];
    memset(f, 0, sizeof(f));

    string t[1 << n];

    const ll mod = 998244353;

    for(int i = (1 << n); i >= 1; i--) {
        int p = i-1, l = (i << 1)-1, r = (i << 1);


        if(l >= (1 << n)-1) {
            f[p] = 1;
            t[p] += s[p];
            continue;
        }
        //cout << p << " " << l << " " << r << endl;
        
        int gc = cmp(t[l], t[r]);

        if(gc == 0) {
            f[p] = f[l] * 1ll * f[r] % mod;
            t[p] = s[p] + t[l] + t[l];
        }
        else {
            f[p] = f[l] * 2ll % mod * f[r] % mod;

            if(gc == 1) t[p] = s[p] + t[l] + t[r];
            else t[p] = s[p] + t[r] + t[l];
        }
    }

    cout << f[0] << "\n";
	
    return 0;
}


