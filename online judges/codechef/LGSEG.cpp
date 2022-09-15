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

const int LOGN = 20;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n, k, s; cin >> n >> k >> s;
    	int a[n];

    	for(int i = 0; i < n; i++)
    		cin >> a[i];

    	int go[n][LOGN];
    	int r = 0;
    	int sum = 0;

    	for(int i = 0; i < n; i++) {
    		while(r < n and sum + a[r] <= s) {
    			sum += a[r];
    			r++;
    		}

    		go[i][0] = r;
    		sum -= a[i];
    	}

    	for(int j = 1; j < LOGN; j++) {
    		for(int i = 0; i < n; i++) {
    			if(go[i][j-1] < n) go[i][j] = go[go[i][j-1]][j-1];
    			else go[i][j] = n;
    		}
    	}

    	int ans = 0;

    	for(int i = 0; i < n; i++) {
    		int pos = i;
    		for(int j = 0; j < LOGN; j++) {
    			if(((k >> j)&1) and (pos < n)) pos = go[pos][j];
    		}

    		ans = max(ans, pos - i);
    	}

    	cout << ans << endl;
    }
	
	
    return 0;
}
