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

const int E = 10;
bool banned[E];
ll cnt[E];
bool used[E];

ll ans = (ll) 1e18;

void backtrack(int val=0, ll curr=0) {
    if(val == E) {
        ans = min(ans, curr);
        return;
    }

    for(int i = 0; i < E; i++) {
        if(used[i]) continue;
        if(val == 0 and banned[i]) continue;

        used[i] = 1;
        backtrack(val+1, curr + cnt[i] * val);
        used[i] = 0;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    

    for(int i = 0; i < n; i++) {
        string s; cin >> s;

        banned[s[0]-'a'] = 1;

        reverse(all(s));
        ll p10 = 1;

        for(char c : s) {
            cnt[c-'a'] += p10;
            p10 *= 10;
        }
    }

    backtrack();

    cout << ans << "\n";
	
    return 0;
}


