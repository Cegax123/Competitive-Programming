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

template <class T, class compare=less<T>>
struct optQueue {
    stack<T> l, r;
    T best;
    optQueue() {}
    T f(T x, T y) {
      return compare()(x, y) ? x : y;
    }
    void add(T c) {
      best = r.empty() ? c : f(best, c);
      r.push(c);
    }
    bool empty() {
      return l.empty() && r.empty();
    }
    size_t size() {
      return l.size() + r.size();
    }
    void pop() {
      assert(!empty());
      if (l.empty()) {
        while (!r.empty()) {
          if (l.empty()) l.push(r.top());
          else l.push(f(l.top(), r.top()));
          r.pop();
        }
      }
      l.pop();
    }
    T get() {
      assert(!empty());
      if (l.empty()) return best;
      if (r.empty()) return l.top();
      return f(l.top(), best);
    }
};

const ll INF = (ll) 1e18;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
	int n, x; cin >> n >> x;
	int a[n];

	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	ll global = INF;

	for(int k = 0; k < n; k++) {
		ll local = (ll) k*x;
		optQueue<int> q;
		
		for(int j = 0; j <= k; j++) 
			q.add(a[j]);

		local += q.get();

		for(int i = 1; i < n; i++) {
			q.pop();
			q.add(a[(i+k)%n]);

			local += q.get();
		}

		global = min(global, local);
	}

	cout << global << "\n";
	
    return 0;
}
