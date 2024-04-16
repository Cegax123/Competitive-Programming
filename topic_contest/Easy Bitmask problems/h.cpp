#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int L = 64;
int cnt;
ll l, r, pref;
ll curr;
ll ans;

void update(ll curr) {
    int curr_cnt = __builtin_popcountll(curr);
    if(curr_cnt > cnt) {
        cnt = curr_cnt;
        ans = curr;
    }
    if(curr_cnt == cnt) {
        ans = min(ans, curr);
    }
}

void gen(int pos) {
    if(pos == -1) {
        update(curr);
        return;
    }

    if((r >> pos)&1ll) {
        curr |= (1ll << pos);
        gen(pos-1);
        curr ^= (1ll << pos);

        curr |= (1ll << pos) - 1;
        update(curr);
        curr ^= (1ll << pos) - 1;
    }
    else {
        gen(pos-1);
    }
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    while(n--) {
        cin >> l >> r;

        pref = 0ll;
        int ind = -1;

        for(int i = L-1; i >= 0; i--) {
            if(((l >> i)&1ll) == ((r >> i)&1ll)) {
                if((l >> i)&1ll)
                    pref |= (1ll << i);
            }
            else {
                ind = i;
                break;
            }
        }

        if(ind == -1) {
            cout << l << "\n";
            continue;
        }

        cnt = ans = 0;
        curr = pref;

        gen(ind);

        cout << ans << "\n";
    }

	
    return 0;
}


