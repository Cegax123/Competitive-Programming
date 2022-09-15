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
	
	ll curr = 0;
	priority_queue<int, vi, greater<int> > pq;
	
	for(int i = 0; i <= n; i++) {
		int x; cin >> x;
		pq.push(x);
		
		curr += x;
		
		while(curr < 0) {
			curr -= pq.top();
			pq.pop();
		}
	}
	
	cout << pq.size() << "\n";
	
	return 0;
}
