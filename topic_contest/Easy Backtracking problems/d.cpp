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

string u;
string curr;
string ans;
int used[10];

bool backtrack(int pos = 0, int f = 0) {
    if(pos == (int) u.size()) {
        ans = curr;
        return true;
    }
    
    int maxd = u[pos]-'0';
    if(f == 1) {
        maxd = 9;
    }

    for(int i = maxd; i >= 0; i--) {
        if(used[i] == 2) continue;
        int c = (i == 0 ? (pos == 0 ? 0 : 1) : 1);
        used[i] += c;

        int nxtf = f;
        if(i < maxd) nxtf = 1;

        curr += (char) '0' + i;

        bool res = backtrack(pos+1, nxtf);

        used[i] -= c;
        curr.pop_back();

        if(res) return true;
    }

    return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> u) {
        backtrack();
        if(ans[0] == '0') ans.erase(ans.begin());
        cout << ans << "\n";
    }

	
    return 0;
}


