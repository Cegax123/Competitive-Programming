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
    string s, t; cin >> s >> t;
    int n = s.size(), k = t.size();

    vi poss(n-k+1, true);

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n-k+1; j++) {
            if(t[i] == s[j + i]) poss[j] = false;
        }
    }

    int ans = 0;
    for(int x : poss) ans += x;

    cout << ans << "\n";
	
    return 0;
}


