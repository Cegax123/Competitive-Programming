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
    vi cntf(370, 0), cntm(370, 0);

    for(int i = 0; i < n; i++) {
        char s; cin >> s;
        int a, b; cin >> a >> b;
        if(s == 'M') cntm[a]++, cntm[b+1]--;
        if(s == 'F') cntf[a]++, cntf[b+1]--;
    }

    for(int i = 1; i < 370; i++) {
        cntm[i] += cntm[i-1];
        cntf[i] += cntf[i-1];
    }

    int ans = 0;
    for(int i = 0; i < 370; i++) {
        ans = max(ans, 2 * min(cntm[i], cntf[i]));
    }

    cout << ans << "\n";
	
    return 0;
}


