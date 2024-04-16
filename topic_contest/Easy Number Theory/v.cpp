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
    cin.ignore();

    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        vector<ll> a;
        ll num = -1;

        for(int i = 0; i < (int) s.size(); i++) {
            if(s[i] == ' ') {
                if(num != -1) a.pb(num);
                num = -1;
            }
            else {
                if(num == -1) num = s[i]-'0';
                else num = num * 10 + (s[i] - '0');
            }
        }

        a.pb(num);

        ll ans = 0;
        for(int i = 0; i < (int) a.size(); i++) {
            for(int j = i + 1; j < (int) a.size(); j++) {
                ans = max(ans, __gcd(a[i], a[j]));
            }
        }

        cout << ans << "\n";
    }
	
    return 0;
}


