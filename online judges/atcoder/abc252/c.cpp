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
    string s[n];

    for(int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 1e9;

    for(int d = 0; d < 10; d++) {
        vi cnt(10, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                if(s[i][j] == '0' + d)
                    cnt[j]++;
            }
        }
        
        int x = 0, t = 0;
        for(int i = 0; i < 10; i++) {
            if(cnt[i] >= x) { 
                x = cnt[i];
                t = i;
            }
        }

        ans = min(ans, (x-1) * 10 + t);
    }

    cout << ans << "\n";
   
    return 0;
}


