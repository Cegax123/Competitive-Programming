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

const int maxn = 5e5 + 5;

ll dp[maxn][2];
int ma[maxn][2], a[maxn];
const ll INF = (ll) 1e18;

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

const int LOGN = 20;

ll ST[maxn][LOGN][2];

ll f(ll a, ll b) {return min(a,b);}

void STBuild(int n, bool lft) {
    for(int i = 1; i <= n+2; i++) 
        ST[i][0][lft] = dp[i-1][lft]; // Cuidado con los índices. Si 'a' es 0-indexado, entonces: ST[i][0] = a[i-1];

    for(int k = 1; (1 << k) <= n+2; k++) {
        int dis = 1 << (k-1);

        for(int i = 1; i + 2*dis -1 <= n+2; i++)
            ST[i][k][lft] = f(ST[i][k-1][lft], ST[i+dis][k-1][lft]);
    }
}

ll STQuery(int L, int R, bool lft) {
    L++; R++;

    int d = R-L+1;
    int k = 31- __builtin_clz(d);
    int dis = 1 << k;

    return f(ST[L][k][lft], ST[R-dis+1][k][lft]);
}



void solve() {
    int n, k; cin >> n >> k;

    ll a[n+2];
    a[0] = a[n+1] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];


    string s; cin >> s;
    s = "1" + s + "1";

    int ml[n+2], mr[n+2];

    ml[0] = 0;
    mr[n+1] = 0;


    dp[0][0] = 0;
    optQueue<ll> q;

    q.add(0);

    for(int i = 1; i <= n+1; i++) {
        while((int) q.size() > k) q.pop();

        dp[i][0] = q.get() + a[i];
        
        if(s[i] == '1') {
            while(!q.empty()) q.pop();
        }

        if(s[i-1] == '1') ml[i] = i-1;
        else ml[i] = ml[i-1];

        q.add(dp[i][0]);
    }

    dp[n+1][1] = 0;

    while(!q.empty()) q.pop();

    q.add(0);

    for(int i = n; i >= 0; i--) {
        while((int) q.size() > k) q.pop();

        dp[i][1] = q.get() + a[i];
        
        if(s[i] == '1') {
            while(!q.empty())
                q.pop();
        }

        if(s[i+1] == '1') mr[i] = i+1;
        else mr[i] = mr[i+1];

        q.add(dp[i][1]);
    }

    STBuild(n, 0);
    STBuild(n, 1);

    //for(int i = 0; i <= n+1; i++) {
      //cout << dp[i][0] << " ";
    //}
    //cout << endl;
    //for(int i = 0; i <= n+1; i++) {
      //cout << dp[i][1] << " ";
    //}
    //cout << endl;

    int Q; cin >> Q;
    while(Q--) {
        int pos, v; cin >> pos >> v;

        ll ans = INF;

        for(int i = max({0, pos-k, ml[pos]}); i < pos; i++) {
            int r = min({n+1, i+k, mr[i]});

            if(!(pos < r)) continue;


            //cout << i << " " << pos+1 << " " << r << endl;
            ans = min(ans, dp[i][0] + STQuery(pos+1, r, 1));
        }

        int R = min({n+1, pos+k, mr[pos]});
        if(pos < R) ans = min(ans, dp[pos][0] + v-a[pos] + STQuery(pos+1, R, 1));

        int L = max({0, pos-k, ml[pos]});
        if(L < pos) ans = min(ans, dp[pos][1] + v-a[pos] + STQuery(L, pos-1, 0));

        cout << ans << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
      solve();
    }
	
    return 0;
}


