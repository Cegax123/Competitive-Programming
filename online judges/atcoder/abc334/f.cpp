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

const int maxn = 2e5+5;
int x[maxn], y[maxn];

long double dis(int i, int j) {
    ll dx = (x[i]-x[j]) * 1ll * (x[i]-x[j]);
    ll dy = (y[i]-y[j]) * 1ll * (y[i]-y[j]);

    return sqrt(dx + dy);
}

long double replace(int i) {
    return dis(i, 0) + dis(i+1, 0) - dis(i, i+1);
}

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

// optQueue<int, greater<int> > q;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;
    
    for(int i = 0; i <= n; i++) cin >> x[i] >> y[i];

    long double ans = 0;

    ans += dis(0, 1) + dis(0, n);
    for(int i = 2; i <= n; i++) ans += dis(i, i-1);

    if(n == 1) {
        cout << ans << "\n";
        return 0;
    }

    long double dp[n+5];
    dp[0] = 0;
    dp[1] = replace(1);

    optQueue<long double> q;
    q.add(0);
    q.add(dp[1]);

    for(int i = 2; i < n; i++) {
        while((int) q.size() > k) q.pop();
        dp[i] = replace(i) + q.get();
        q.add(dp[i]);
    }

    long double get_min = 1e18;

    for(int i = max(1, n-k); i <= n-1; i++) {
        get_min = min(get_min, dp[i]);
    }


    cout << setprecision(10) << fixed;
    cout << ans + get_min << "\n";
	
    return 0;
}


