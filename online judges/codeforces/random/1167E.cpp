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
    int n, x; cin >> n >> x;
    vi pos[x+1];

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        pos[a].pb(i);
    }

    int R[x+2], L[x+2];
    R[0] = -1;

    for(int i = 1; i <= x; i++) {
        if(pos[i].empty()) R[i] = R[i-1];
        else {
            if(R[i-1] > pos[i][0]) R[i] = n+5;
            else R[i] = pos[i].back();
        }
    }

    L[x+1] = n+1;

    for(int i = x; i >= 1; i--) {
        if(pos[i].empty()) L[i] = L[i+1];
        else {
            if(L[i+1] < pos[i].back()) L[i] = -5;
            else L[i] = pos[i][0];
        }
    }

    int curr = 0;
    ll ans = 0;

    for(int i = 0; i <= x; i++) {
        curr = max(curr, i + 2);

        while(curr <= x+1 and L[curr] < R[i]) curr++;

        //cout << i << " " << curr << "\n";

        ans += x + 2 - curr;
    }

    cout << ans << "\n";
	
    return 0;
}


