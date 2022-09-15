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

const int maxn = 12;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, X, Y; cin >> n >> X >> Y;
    
    ll ans = 0;
    vector<pair<ll, ll>> red, blue;
    red.pb({n, 1});

    while(true) {
        //for(auto x : red) {
            //cout << x.first << " " << x.second << endl;
        //}
        //cout << endl;
        //for(auto x : blue) {
            //cout << x.first << " " << x.second << endl;
        //}

        //cout << endl << endl;

        ll cnt_red[maxn], cnt_blue[maxn];

        memset(cnt_red, 0, sizeof(cnt_red));
        memset(cnt_blue, 0, sizeof(cnt_blue));

        vii new_red, new_blue;

        for(pair<ll, ll> x : red) {
            if(x.first == 1) continue;
            cnt_red[x.first-1] += x.second;
            cnt_blue[x.first] += (ll) X * x.second;
        }
        
        for(pair<ll, ll> x : blue) {
            if(x.first == 1) {
                ans += x.second;
                continue;
            }

            cnt_red[x.first-1] += x.second;
            cnt_blue[x.first-1] += (ll) Y * x.second;
        }

        red.clear(); blue.clear();

        for(int i = 1; i < maxn; i++) {
            if(cnt_red[i])
                red.pb({i, cnt_red[i]});
            if(cnt_blue[i]) 
                blue.pb({i, cnt_blue[i]});
        }

        if(red.empty() and blue.empty())
            break;
    }

    cout << ans << "\n";
	
    return 0;
}


