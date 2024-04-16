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
    auto is_pal = [](const string& s) {
        for(int i = 0; i < (int) s.size(); i++)
            if(s[i] != s[(int) s.size() - 1 - i]) return false;
        return true;
    };

    int ans = 0;
    string s; cin >> s;

    for(int len = 1; len <= (int) s.size(); len++) {
        for(int j = 0; j + len - 1 < (int) s.size(); j++) {
            string y = s.substr(j, len);
            if(!is_pal(y)) ans = len;
        }
    }

    cout << ans << "\n";
	
    return 0;
}


