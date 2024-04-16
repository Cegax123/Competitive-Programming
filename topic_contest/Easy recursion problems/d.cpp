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

int find(int a, int b) {
    if(a == 1) return b-1;
    return b/a + find(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    
    int ans = n;
    for(int i = 1; i <= n; i++) {
        if(__gcd(i, n) == 1) 
            ans = min(ans, find(i, n));
    }

    cout << ans << "\n";
	
    return 0;
}


