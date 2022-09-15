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

const int maxn = 105;

vector<vi> adj;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<ii, int>> a(n);

        for(int i = 0; i < n; i++) 
            cin >> a[i].first.first;

        for(int i = 0; i < n; i++)
            cin >> a[i].first.second;

        for(int i = 0; i < n; i++)
            a[i].second = i;

        sort(all(a));
        bool cmp = 1;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(a[i].first.first < a[j].first.first and a[i].first.second > a[j].first.second) {
                    cmp = 0;
                }
            }
        }

        if(cmp == 0) {
            cout << "-1\n";
            continue;
        }

        vi d(n);

        for(int i = 0; i < n; i++) 
            d[a[i].second] = i;

        vii moves;
        for(int i = 0; i < n; i++) {
            int pos = i;
            for(int j = i; j < n; j++) {
                if(d[j] == i) 
                    pos = j;
            }

            if(pos != i) {
                moves.pb({i+1, pos+1});
                swap(d[i], d[pos]);
            }
        }

        cout << moves.size() << "\n";

        for(auto e : moves)
            cout << e.first << " " << e.second << "\n";
    }

	
	
    return 0;
}


