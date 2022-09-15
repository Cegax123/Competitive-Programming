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
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        int child[n];
        memset(child, 0, sizeof(child));

        for(int i = 1; i < n; i++) {
            int p; cin >> p;
            p--;

            child[p]++;
        }

        vi a(1, 1);

        for(int i = 0; i < n; i++) 
            if(child[i]) a.pb(child[i]);

        sort(all(a));

        int ans = 0;
        multiset<int> b;

        while((not a.empty()) or (not b.empty())) {
            ans++;

            multiset<int> tmp;
            for(const int& x : b) {
                if(x > 1)
                    tmp.insert(x-1);
            }

            b = tmp;

            if(not a.empty()) {
                if(a.back() > 1) 
                    b.insert(a.back()-1);

                a.pop_back();
            }
            else {
                if(not b.empty()) {
                    int st = *(b.rbegin());
                    b.erase(b.find(st));
                    if(st > 1) {
                        b.insert(st-1);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
	
	return 0;
}

