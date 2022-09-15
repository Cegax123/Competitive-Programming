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
    map<string, int> cnt;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int x = cnt[s];
        if(x == 0) {
            cout << s << "\n";
            cnt[s] = x + 1;
        }
        else {
            cout << s << "(" << x << ")\n";
            cnt[s] = x + 1;
        }
    }

	
    return 0;
}


