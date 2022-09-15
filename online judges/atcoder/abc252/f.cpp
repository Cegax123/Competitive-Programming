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
    ll L; cin >> L;

    ll sum = 0;
    multiset<ll> s;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);

        sum += a;
    }

    if(sum < L)
        s.insert(L-sum);

    ll ans = 0;

    while((int) s.size() >= 2) {
        ll x = *s.begin(); s.erase(s.find(x));
        ll y = *s.begin(); s.erase(s.find(y));

        ans += x + y;

        s.insert(x + y);
    }

    cout << ans << "\n";
  
    return 0;
}


