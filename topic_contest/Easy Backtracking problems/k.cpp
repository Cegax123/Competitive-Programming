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

int n;
vector<ll> a, curr;
vector<vector<ll>> poss;

void solve(int pos, int len, const vector<ll>& v) {
    if(pos == n) {
        //sort(all(curr));
        poss.pb(curr);
        return;
    }

    ll num = v[(1 << len)-1] - v[(1 << len)-2];

    //if(pos == 1) {
        //cout << "\n====\n";
        //cout << last_neg << " " << first_pos << "\n";
        //cout << "====\n";
    //}

    vector<ll> nxt;

    auto comp = [&](ll x) {
        nxt.clear();
        //cout << x << endl;
       
        multiset<ll> s;

        for(ll u : v) s.insert(u); 

        bool cmp = 1;
        for(int i = 0; i < (1 << (len-1)); i++) {
            ll y = *s.begin(); s.erase(s.begin());
            //cout << y << " " << x << endl;
            if(x >= 0) {
                if(s.find(y + x) == s.end()) {
                    cmp = 0;
                    break;
                }
                else {
                    s.erase(s.find(y+x));
                    nxt.pb(y);
                }
            }
            else {
                if(s.find(y - x) == s.end()) {
                    cmp = 0;
                    break;
                }
                else {
                    s.erase(s.find(y-x));
                    nxt.pb(y-x);
                }
            }
        }


        //for(int e : nxt) {
            //cout << e << " ";
        //}
        //cout << endl;

        if(!cmp) nxt.clear();

        bool cmp0 = 0;
        for(int e : nxt) {
            if(e == 0) cmp0 = 1;
        }

        if(!cmp0) nxt.clear();

        sort(all(nxt));
    };

    //cout << num << endl;

    comp(num);
    if(!nxt.empty()) {
        //cout << pos << " " << num << ": ";
        //for(int x : nxt) {
            //cout << x << " ";
        //}
        //cout << endl;

        curr.pb(num);
        solve(pos+1, len-1, nxt);
        curr.pop_back();
    }

    if(num > 0) {
        comp(-num);
        
        if(!nxt.empty()) {
            //cout << pos << " " << -num << ": ";
            //for(int x : nxt) {
                //cout << x << " ";
            //}
            //cout << endl;

            curr.pb(-num);
            solve(pos+1, len-1, nxt);
            curr.pop_back();
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    a.resize(1 << n);

    //for(int i = 0; i < n; i++) {
        //int x; cin >> x;
    //}

    for(int i = 0; i < (1 << n); i++)
        cin >> a[i];

    sort(all(a));

    solve(0, n, a);

    for(auto& v : poss) {
        sort(all(v));
    }

    sort(all(poss));

    poss.erase(unique(all(poss)), poss.end());

    for(auto v : poss) {
        for(ll x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


