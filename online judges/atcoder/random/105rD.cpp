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
    	map<int, int> cnt;

    	for(int i = 0; i < n; i++) {
    		int a; cin >> a;
    		cnt[a]++;
    	}

    	if(n&1) cout << "Second\n";
    	else {
    		bool cmp = 1;

    		for(auto e : cnt)
    			if(e.second&1) cmp = 0;

    		if(cmp) cout << "Second\n";
    		else cout << "First\n";
    	}
    }
	
	
    return 0;
}
