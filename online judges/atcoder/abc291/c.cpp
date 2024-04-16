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
    string s; cin >> s;

    int x, y;
    x = y = 0;

    set<ii> p;

    p.insert({x, y});
    bool cmp = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') x++;
        if(s[i] == 'L') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;

        if(p.count({x, y})) cmp = 1;
        p.insert({x, y});
    }

    cout << (cmp ? "Yes\n" : "No\n");
	
    return 0;
}


