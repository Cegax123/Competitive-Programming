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
    int n, k; cin >> n >> k;
    int p[n+1];

    for(int i = 1; i <= n; i++)
        cin >> p[i];

    int ans[n+1];

    memset(ans, -1, sizeof(ans));

    vector<vi> stacks;
    set<int> top;
    int pos[n+1];

    for(int i = 1; i <= n; i++) {
        if(top.empty() or top.upper_bound(p[i]) == top.end()) {
            top.insert(p[i]);
            pos[p[i]] = stacks.size();
            stacks.pb(vi(1, p[i]));

            if(k == 1) {
                top.erase(p[i]);
                ans[p[i]] = i;
            }
        }
        else {
            int x = *top.upper_bound(p[i]);
            stacks[pos[x]].pb(p[i]);
            pos[p[i]] = pos[x];
            top.insert(p[i]);

            top.erase(x);
            top.insert(p[i]);

            if((int)stacks[pos[x]].size() == k) {
                top.erase(stacks[pos[x]].back());
                for(int x : stacks[pos[x]]) {
                    ans[x] = i;
                }
            }
        }

        //for(vi A : stacks) {
            //for(int x : A)
                //cout << x << " ";

            //cout << endl;
        //}
        //cout << endl;
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
	
    return 0;
}


