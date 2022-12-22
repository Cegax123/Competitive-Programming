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
string s;

ll val(int i) {
    return (s[i] == '(' ? 1 : -1);
}


ll solve(int l, int r) {
    if(l == r) 
        return 1;
    
    int m = (l + r) >> 1;

    ll ans = solve(l, m) + solve(m+1, r);
    
    vector<ll> tR(1, 0), mR(1, 0);
    vector<ll> preftR(1, 0), prefmR(1, 0);

    for(int i = m+1; i <= r; i++) {
        tR.pb(tR.back() + val(i)); 
        mR.pb(min(mR.back(), tR.back()));
        
        prefmR.pb(prefmR.back() + mR.back());
    }

    sort(tR.begin()+1, tR.end());

    for(int i = m+1; i <= r; i++) {
        preftR.pb(preftR.back()+tR[i-m]);
    }

    ll tL = 0, mL = 0;

    //if(l == 0 and r == 3) {
        //for(int x : tR) cout << x << " ";
        //cout << endl;
        //for(int x : preftR) cout << x << " ";
        //cout << endl;
    //}

    for(int i = m; i >= l; i--) {
        tL += val(i);
        mL = min({val(i), mL+val(i), 0ll});

        int vL = 1, vR = tR.size()-1;
        while(vL < vR) {
            int vM = (vL+vR) >> 1;
            if(tL + tR[vM] >= 0) vR = vM;
            else vL = vM+1;
        }

        //if(l == 0 and r == 3) {
            //cout << i << " " << vL << endl;
            //cout << preftR.back()-preftR[vL-1] << endl;
            //cout << tL * (tR.size()-vL) << endl;
        //}

        if(tL + tR[vL] >= 0) {
            ans += preftR.back()-preftR[vL-1];
            ans += tL * (tR.size()-vL);
        }

        vL = 1, vR = tR.size()-1;
        while(vL < vR) {
            int vM = (vL+vR) >> 1;
            if(mL >= tL + mR[vM]) vR = vM;
            else vL = vM+1;
        }

        if(mL < tL + mR[vL]) {
            ans += abs(mL) * (tR.size()-1);
            continue;
        }

        ans += abs(mL) * (vL-1);
        
        int tmp = vL;

        vR = tR.size()-1;

        while(vL < vR) {
            int vM = (vL+vR) >> 1;
            if(tL + mR[vM] <= 0) vR = vM;
            else vL = vM+1;
        }

        if(tL + mR[vL] <= 0) {
            ans -= tL * (tR.size()-vL);
            ans -= prefmR.back() - prefmR[vL-1];

            ans += tL * (vL-tmp);
            ans += prefmR[vL-1]-prefmR[tmp-1];
        }
        else {
            ans += tL * (tR.size()-tmp);
            ans += prefmR.back()-prefmR[tmp-1];
        }
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> s;

        cout << solve(0, n-1) << "\n";
    }
    

	
    return 0;
}


