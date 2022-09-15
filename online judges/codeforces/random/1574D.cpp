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
    
    vector<vi> a;
    vi best;

    for(int i = 0; i < n; i++) {
    	int c; cin >> c;
    	vi tmp(c);

    	for(int j = 0; j < c; j++)
    		cin >> tmp[j];

    	a.pb(tmp);
    	best.pb(c);
    }

    int m; cin >> m;
    vector<vi> b;

    for(int i = 0; i < m; i++) {
    	vi tmp(n);

    	for(int j = 0; j < n; j++)
    		cin >> tmp[j];

    	b.pb(tmp);
    }

    sort(all(b));

    if(!binary_search(all(b), best)) {
    	for(int i = 0; i < n; i++)
    		cout << best[i] << " ";
    	cout << "\n";
    }
	else {
		int ans = 0;
		vi bans;

		for(int i = 0; i < m; i++) {
			vi tmp = b[i];
			int curr = 0;

			for(int j = 0; j < n; j++)
				curr += a[j][tmp[j]-1];

			for(int j = 0; j < n; j++) {
				if(tmp[j] == 1) continue;

				curr -= a[j][tmp[j]-1];
				curr += a[j][tmp[j]-1-1];

				tmp[j]--;

				if(curr > ans and !binary_search(all(b), tmp)) {
					ans = curr;
					bans = tmp;
				}

				tmp[j]++;

				curr += a[j][tmp[j]-1];
				curr -= a[j][tmp[j]-1-1];
			}
		}

		for(int x : bans)
			cout << x << " ";

		cout << "\n";
	}
	
    return 0;
}
