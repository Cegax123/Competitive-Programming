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

struct Node {
	int len;
	string st, end;
	ll cnt = 0;
};

int count_sub(const string& s) {
	int cnt = 0;
	for(int i = 0; i+3 < (int) s.size(); i++) {
		if(s.substr(i, 4) == "haha")
			cnt++;
	}
	return cnt;
}

Node combine(Node a, Node b) {
	Node c;

	c.st = a.st;
	if(a.len <= 3) {
		c.st = a.st + b.st;
		int k = c.st.size();

		if(k >= 4) {
			c.st = c.st.substr(0, 3);
		}
	}

	c.end = b.end;
	if(b.len <= 3) {
		c.end = a.end + b.end;
		int k = c.end.size();

		if(k >= 4) {
			c.end = c.end.substr(k-3, 3);
		}
	}

	// cout << "medium: " << a.end + b.st << endl;
	c.cnt = a.cnt + b.cnt + count_sub(a.end + b.st);
	c.len = min(10, a.len + b.len);

	return c;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
	    map<string, Node> val;

	    int n; cin >> n;
	    ll ans;

	    for(int i = 0; i < n; i++) {
	    	string var; cin >> var;

	    	string op; cin >> op;

	    	if(op == ":=") {
	    		string new_val; cin >> new_val;
	    		int k = new_val.size();

	    		val[var].st = new_val;
				if(k >= 4) {
	    			val[var].st = val[var].st.substr(0, 3);
	    		}

	    		val[var].end = new_val;
	    		if(k >= 4) {
	    			val[var].end = val[var].end.substr(k-3, 3);
	    		}

	    		val[var].cnt = count_sub(new_val);
	    		val[var].len = new_val.size();
	    	}
	    	else {
	    		string var1, var2; cin >> var1 >> var2 >> var2;
	    		val[var] = combine(val[var1], val[var2]);
	    	}

	    	// cout << val[var].st << " " << val[var].end << " " << val[var].cnt << endl;

	    	ans = val[var].cnt;
	    }

	    cout << ans << "\n";
	}
	
    return 0;
}
