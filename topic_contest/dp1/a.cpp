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
	string s; cin >> s;
    int n = s.size();

    vi cnta(n+2, 0), cntb(n+2, 0);

    for(int i = 1; i <= n; i++) {
        if(s[i-1] == 'a') cnta[i]++;
        else cntb[i]++;

    }
	
    for(int i = 1; i <= n+1; i++) {
        cnta[i] += cnta[i-1];
        cntb[i] += cntb[i-1];
    }

    int ans = cntb[n];
    for(int i = 0; i <= n+1; i++) {
        for(int j = i+1; j <= n+1; j++) {
            ans = min(ans, cntb[i] + cntb[n+1]-cntb[j-1] + cnta[j-1] - cnta[i]);
        }
    }

    cout << n-ans << "\n";
	
	return 0;
}

