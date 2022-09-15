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

    if(s.size() > t.size()) {
        cout << "No\n";
        return 0;
    }

    bool cmp = 1;

    for(int i = 0; i < (int) s.size(); i++) 
        if(s[i] != t[i]) cmp = 0;
	
    if(cmp) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}


