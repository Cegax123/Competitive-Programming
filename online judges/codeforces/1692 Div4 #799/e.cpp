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
    int t; cin >> t;
    while(t--) {
        int n, s; cin >> n >> s;

        int curr = 0;
        int most_left[n+1];
        memset(most_left, -1, sizeof(most_left));
        int ans = -1;
        

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            curr += a;

            if(most_left[curr] == -1) most_left[curr] = i;

            if(curr < s) continue;
            
            int local;

            if(curr == s) 
                local = n-(i+1);
            else if(most_left[curr-s] != -1) 
                local = n-(i-most_left[curr-s]);

            if(ans == -1) ans = local;
            ans = min(ans, local);
        }
        
        cout << ans << "\n";
    }

	
    return 0;
}


