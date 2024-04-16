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

const int maxn = 20;
bool b[maxn][maxn];
bool banned[maxn];
int n;
ll ans = 0;

bool is_valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n;
}

void backtrack(int pos = 0) {
    if(pos == n) {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(banned[i]) continue;
        int r = i, c = pos;

        bool cmp = 1;
        while(is_valid(r, c)) {
            if(b[r][c]) cmp = 0;
            r--; c--;
        }

        if(!cmp) continue;

        r = i, c = pos;

        while(is_valid(r, c)) {
            if(b[r][c]) cmp = 0;
            r++; c--;
        }

        if(!cmp) continue;

        b[i][pos] = 1;
        banned[i] = 1;

        backtrack(pos+1);

        b[i][pos] = 0;
        banned[i] = 0;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    backtrack();

    cout << ans << "\n";
	
    return 0;
}


