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

const int maxn = 10;
int n, m;
string s[maxn];
bool used[maxn];
vector<string> curr;
bool ans;

int diff(const string& a, const string& b) {
    int cnt = 0;

    for(int i = 0; i < m; i++)
        cnt += a[i] != b[i];
    return cnt;
}

void solve(int pos=0) {
    if(pos == n) {
        ans = true;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        if(curr.empty()) {
            curr.pb(s[i]);
            used[i] = 1;
            solve(pos+1);
            used[i] = 0;
            curr.pop_back();
        }
        else {
            if(diff(s[i], curr.back()) == 1) {
                curr.pb(s[i]);
                used[i] = 1;
                solve(pos+1);
                used[i] = 0;
                curr.pop_back();
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    solve();

    cout << (ans ? "Yes\n" : "No\n");
	
    return 0;
}


