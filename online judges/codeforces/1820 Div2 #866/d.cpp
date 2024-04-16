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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll a[n], b[n];
        ll T = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            T += a[i] * b[i];
        }

        ll mxa = 0, mxb = 0;

        for(int i = 0; i < n; i++) {
            mxa = max(mxa, a[i]);
            mxb = max(mxb, b[i]);
        }

        auto cmp = [&](ll h, ll w) {
            multiset<pair<ll, ll>> sh, sw;

            for(int i = 0; i < n; i++) {
                sh.insert({a[i], b[i]});
                sw.insert({b[i], a[i]});
            }

            while(!sh.empty()) {
                auto vh = *(sh.rbegin());

                if(vh.first == h) {
                    w -= vh.second;
                    sh.erase(sh.find(vh));
                    sw.erase(sw.find({vh.second, vh.first}));
                    continue;
                }

                auto vw = *(sw.rbegin());

                if(vw.first == w) {
                    h -= vw.second;
                    sw.erase(sw.find(vw));
                    sh.erase(sh.find({vw.second, vw.first}));
                    continue;
                }

                return false;
            }

            return true;
        };
        
        vector<pair<ll, ll>> poss;

        if(T % mxa == 0) {
            if(cmp(mxa, T/mxa)) poss.pb({mxa, T/mxa});
        }
        if(T % mxb == 0 and mxa * mxb != T) {
            if(cmp(T/mxb, mxb)) poss.pb({T/mxb, mxb});
        }

        cout << poss.size() << "\n";

        for(int i = 0; i < (int) poss.size(); i++)
            cout << poss[i].first << " " << poss[i].second << "\n";
        

    }

	
    return 0;
}


