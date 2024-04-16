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

ll l, r;
vi vl, vr;
ll p[19];

vi curr;
vi ans;

bool cmp(int mind, int maxd, int pos=0, int L=0, int R=0, bool st=1) {
    if(pos == 19) {
        ans = curr;
        return true;
    }

    //if(pos == 14 and curr.back() == 7) {
        //cout << "HOLA ";
        //cout << L << " " << R << " " << st << endl;
    //}

    if(L == 1 and R == 1) {
        for(int i = pos; i < 19; i++) {
            curr.pb(maxd);
        }
        ans = curr;

        for(int i = pos; i < 19; i++)
            curr.pop_back();

        return true;
    }

    int lmtL, lmtR;
    if(L == 0 and R == 0) {
        lmtL = vl[pos], lmtR = vr[pos];
    }
    else if(R == 1) {
        lmtL = vl[pos], lmtR = 9;
    }
    else if(L == 1) { 
        lmtL = 0, lmtR = vr[pos];
    }

    for(int d = lmtL; d <= lmtR; d++) {
        bool in_inter = d >= mind and d <= maxd;
        bool pass = in_inter;
        if(d == 0 and st) pass = true;
        if(!pass) continue;
        
        //cout << pos << " " << d << endl;
        
        curr.pb(d);
        int nxtst = st;
        if(st and d) nxtst = false;

        int nxtL = L;
        if(L == 0 and d > vl[pos]) nxtL = 1;

        int nxtR = R;
        if(R == 0 and d < vr[pos]) nxtR = 1;

        bool can = cmp(mind, maxd, pos+1, nxtL, nxtR, nxtst);

        curr.pop_back();

        if(can) return true;
    }

    return false;
}

ll find(ll x) {
    ll mind = 10, maxd = 0;
    while(x) {
        mind = min(mind, x % 10);
        maxd = max(maxd, x % 10);
        x /= 10;
    }
    return maxd - mind;
}

ll get_ans(ll l, ll r) {
    int maxD = 1000;
    ll ans = 0;
    for(ll i = l; i <= r; i++) {
        if(find(i) < maxD) {
            maxD = find(i);
            ans = i;
        }
    }

    cout << ans << "\n";

    return maxD;
}


mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    p[0] = 1;
    for(int i = 1; i <= 18; i++)
        p[i] = p[i-1] * 10;

    int t; cin >> t;
    //int t; t = 1;
    while(t--) {
        cin >> l >> r;


        vl.clear(); vr.clear();

        ll tmp = l;

        for(int i = 0; i < 19; i++) {
            vl.pb(tmp%10);
            tmp /= 10;
        }

        tmp = r;
        for(int i = 0; i < 19; i++) {
            vr.pb(tmp%10);
            tmp /= 10;
        }

        curr.clear(); ans.clear();

        reverse(all(vl));
        reverse(all(vr));

        //cout << cmp(0, 8) << endl;

        int minD = 1000;
        ll num_ans = 0;

        for(int i = 0; i < 10; i++) {
            for(int j=i; j < 10; j++) {
                if(i == 0 and j == 0) continue;
                if(cmp(i, j)) {
                    if(j-i < minD) {
                        minD = j-i;
                        num_ans = 0;

                        for(int x : ans) {
                            num_ans = num_ans * 10 + x;
                        }
                    }
                }
            }
        }

        cout << num_ans << "\n";
    }

	
    return 0;
}


