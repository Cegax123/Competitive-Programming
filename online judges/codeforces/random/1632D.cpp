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
    int a[n+1];

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<bool> marked(n+1, 0);

    vii v;
    if(a[1] == 1) marked[1] = 1;
    else v.pb({1, a[1]});
    
    for(int i = 2; i <= n; i++) {
        v.pb({i, a[i]});

        for(auto& p : v) {
            p.second = __gcd(p.second, a[i]);
        }

        vii nv;
        set<int> s;

        for(auto& p : v) {
            if(s.count(p.second) == 0) nv.pb(p);
            s.insert(p.second);
        }

        v = nv;

        for(int j = 0; j < (int) v.size()-1; j++) {
            if(v[j].second <= i-v[j].first+1 and v[j].second > i-v[j+1].first+1)
                marked[i] = 1;
        }

        int tmp = v.size();
        if(tmp and v[tmp-1].second <= i-v[tmp-1].first+1)
            marked[i] = 1;

        if(marked[i]) v.clear();
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        cnt += marked[i];
        cout << cnt << " ";
    }

    cout << "\n";

	return 0;
}

