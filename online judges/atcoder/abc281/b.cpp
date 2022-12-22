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

    if(n != 8) {
        cout << "No\n";
        return 0;
    }

    string ans = "No\n";

    bool cmp = true;
    if(!(s[0] >= 'A' and s[0] <= 'Z')) cmp = false;
    for(int j = 1; j <= 6; j++) {
        if(j == 1 and s[j] == '0') cmp = false;
        if(!(s[j] >= '0' and s[j] <= '9')) cmp = false;
    }
    if(!(s[7] >= 'A' and s[7] <= 'Z')) cmp = false;
    if(cmp) ans = "Yes\n";

    cout << ans;
	
    return 0;
}


