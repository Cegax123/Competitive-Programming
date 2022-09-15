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

const int E = 26;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = n;

    for(int L = 1; L <= n; L++) {
        if(n % L) continue;
        int needed = 0;

        for(int i = 0; i < L; i++) {
            vi cnt(E, 0);
            for(int j = i; j < n; j += L) {
                cnt[s[j]-'a']++;
            }
            needed += n / L - *max_element(all(cnt));
        }

        if(needed <= k)
            ans = min(ans, L);
    }

    cout << ans << "\n";
   
    return 0;
}


