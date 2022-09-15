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

int cc(ll x) {
    int ans = 0;
    while(x) {
        x /= 10ll;
        ans++;
    }
    return ans;
}

int md(ll x) {
    int ans = 0;
    while(x) {
        ans = max(ans, x % 10ll);
        x /= 10ll;
    }

    return ans;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; ll x; cin >> n >> x;
    int st = cc(x);
	
    while(st < n) {
        
    }
	
    return 0;
}


