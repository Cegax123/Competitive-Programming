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
    ll s, k; cin >> s >> k;

    vector<ll> a;

    a.pb(0);
    a.pb(1);

    map<int, ll> f;

    auto get_ith = [&] (int i) {
        if(i < k) return 0ll;
        if(i == k) return 1ll;
        return f[i];
    };

    ll curr = 1;
    int ind = k+1;

    f[ind] = curr;

    while(curr <= s) {
        curr -= get_ith(ind-k);
        curr += get_ith(ind);
        ind++;
        f[ind] = curr;
        if(a.back() != curr) a.pb(curr);
    }

    vector<int> ans;

    while(!a.empty()) {
        if(a.back() <= s) {
            ans.pb(a.back());
            s -= a.back();
        }
        a.pop_back();
    }

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
	
    return 0;
}


