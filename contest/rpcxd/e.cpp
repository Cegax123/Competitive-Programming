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

    const int maxn = 1005;
    string s[maxn];
    
    int w[maxn][maxn];

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int ans = 0;
            for(int t = 0; t < k; t++)
                ans += abs(s[i][t]-s[j][t]);
            w[i][j] = ans;
        }
    }

    auto cmp = [&](int x) {
        vector<bool> used(n, 0);
        queue<int> q;
        q.push(0);
        used[0] = 1;

        while(!q.empty()) {
            int v = q.front(); q.pop();
            
            for(int i = 0; i < n; i++) {
                if(used[i] == 0 and w[v][i] <= x) {
                    q.push(i);
                    used[i] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++)
            if(!used[i]) return false;

        return true;
    };

    int l = 0, r = 1000;

    while(l < r) {
        int m = (l+r) >> 1;
        if(cmp(m)) r = m;
        else l = m+1;
    }
	
    cout << l << "\n";
    return 0;
}


