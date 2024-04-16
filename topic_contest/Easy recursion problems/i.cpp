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

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string f11 = "What are you doing while sending \"";
const string f12 = "\"? Are you busy? Will you send \"";
const string f13 = "\"?";

const ll INF = (ll) 2e18;
const int maxn = 1e5 + 5;
ll sz[maxn];

char find(int n, ll k) {
    if(sz[n] <= k) {
        return '.';
    }

    if(n == 0) {
        return f0[k];
    }

    if(k < (ll) f11.size()) {
        return f11[k];
    }

    k -= (ll) f11.size();

    if(k < sz[n-1]) {
        return find(n-1, k);
    }

    k -= sz[n-1];

    if(k < (ll) f12.size()) {
        return f12[k];
    }

    k -= (ll) f12.size();

    if(k < sz[n-1]) {
        return find(n-1, k);
    }

    k -= (ll) sz[n-1];

    return f13[k];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sz[0] = f0.size();
    for(int i = 1; i < maxn; i++) {
        sz[i] = min(INF, sz[i-1] * 2 + (ll) f11.size() + (ll) f12.size() + (ll) f13.size());
    }



    int q; cin >> q;
    while(q--) {
        int n; ll k; cin >> n >> k;
        k--;

        cout << find(n, k);
    }

    cout << "\n";
    
	
    return 0;
}


