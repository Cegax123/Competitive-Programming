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
    int n; cin >> n;
    int p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i];

    ll total_diff = 0, accum = 0;

    int diff[n];
    memset(diff, 0, sizeof(diff));

    vi pos[n], neut[n], neg[n];

    auto f = [&](int i, int j) {
        int k = abs(i-j);
        return min(k, n-k);
    };

    for(int i = 0; i < n; i++) {
        accum += f(p[i], i);
        diff[p[i]] = f((i + 1)%n, p[i]) - f(p[i], i);
        total_diff += diff[p[i]];

        int st = p[i]-i;
        if(st < 0) st += n;

        pos[st].pb(p[i]);
        
        if(n&1) {
            int l1 = (p[i] + n + p[i]) / 2;
            l1 %= n;
            l1 -= i;

            if(l1 < 0) l1 += n;

            neut[l1].pb(p[i]);


            int l2 = (p[i] + n + p[i]) / 2 + 1;
            l2 %= n;
            l2 -= i;

            if(l2 < 0) l2 += n;

            neg[l2].pb(p[i]);
        }
        else {
            int l = (p[i] + n + p[i]) / 2;
            l %= n;

            l -= i;
            if(l < 0) l += n;

            neg[l].pb(p[i]);
        }
    }

    //cout << "pos: ";
    //for(int x : pos[1]) cout << x << " ";
    //cout << endl;

    //cout << "neg: ";
    //for(int x : neg[1]) cout << x << " ";
    //cout << endl;


    ll ans = accum;

    //for(int j = 0; j < n; j++)
        //cout << diff[j] << " ";
    //cout << endl;

    for(int i = 1; i < n; i++) {
        accum += total_diff;
        ans = min(ans, accum);
        
        for(int x : pos[i]) {
            total_diff -= diff[x];
            total_diff++;
            diff[x] = 1;
        }

        for(int x : neut[i]) {
            total_diff -= diff[x];
            diff[x] = 0;
        }

        for(int x : neg[i]) {
            total_diff -= diff[x];
            total_diff--;
            diff[x] = -1;
        }

        //for(int j = 0; j < n; j++)
            //cout << diff[j] << " ";
        //cout << endl;
    }

    cout << ans << "\n";

    return 0;
}


