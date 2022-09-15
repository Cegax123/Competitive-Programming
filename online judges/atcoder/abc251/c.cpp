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
    string s[n+1];
    map<string, int> ori;
    map<string, int> pos;

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        int x; cin >> x;

        if(pos[s[i]] == 0) {
            pos[s[i]] = i;
            ori[s[i]] = x;
        }
    }

    int ans = -1;
    int mx_score = -1;
    for(auto e : ori) {
        if(e.second > mx_score) {
            mx_score = e.second;
            ans = pos[e.first];
        }
        if(e.second == mx_score) {
            ans = min(ans, pos[e.first]);
        }
    }

    cout << ans << "\n";
   
    return 0;
}


