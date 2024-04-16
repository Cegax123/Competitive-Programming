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
    int n, k; cin >> n >> k;
    vector<bool> marked(n, 0);

    for(int i = 0; i < k; i++) {
        int a; cin >> a; a--;
        marked[a] = 1;
    }

    vector<int> b;

    for(int i = 0; i < n; i++) if(marked[i]) b.push_back(i);

    int x = b.size();


    if(x % 2 == 0) {
        int ans = 0;
        for(int i = 0; i < (int) b.size(); i += 2) {
            ans += abs(b[i]-b[i+1]);
        }
        cout << ans << "\n";
    }
    else {
        int pL[x], pR[x];

        for(int i = 1; i < x; i += 2) {
            pL[i] = b[i]-b[i-1];
            if(i >= 2) pL[i] += pL[i-2];
        }

        for(int i = x-2; i >= 0; i -= 2) {
            pR[i] = b[i+1]-b[i];
            if(i+2 < x) pR[i] += pR[i+2];
        }

        int ans = 1e9;
        for(int i = 0; i < x; i++) {
            if(i%2 == 0) {
                ans = min(ans, (i == 0 ? 0 : pL[i-1]) + (i+1 < x ? pR[i+1] : 0));
            }
            else {
                ans = min(ans, b[i+1]-b[i-1] + (i >= 2 ? pL[i-2] : 0) + (i+2 < x ? pR[i+2] : 0));
            }
        }
        cout << ans << "\n";
    }

	
    return 0;
}


