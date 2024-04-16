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
    const int E = 26;
    vi cnt(E, 0);

    for(char c : s) cnt[c-'a']++;

    int ans = min({(cnt['n'-'a']-1)/2, cnt['e'-'a']/3, cnt['i'-'a'], cnt['t'-'a']});
    cout << ans << "\n";
	
    return 0;
}


