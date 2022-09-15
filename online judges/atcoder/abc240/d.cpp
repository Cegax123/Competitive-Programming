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

    int a[n+2], cnt[n+2];
    int prev[n+2], nxt[n+2];

    for(int i = 1; i <= n+1; i++)
        prev[i] = i-1;

    for(int i = 0; i <= n; i++)
        nxt[i] = i+1;

    a[0] = 0;
    cnt[0] = 0;

    int total = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        total++;

        if(a[i] == a[prev[i]]) {
            cnt[i] = cnt[prev[i]]+1;
            
            if(cnt[i] >= a[i]) {
                int curr = i;
                total -= cnt[i];
                
                for(int j = 0; j < a[i]; j++) {
                    prev[nxt[curr]] = prev[curr];
                    nxt[prev[curr]] = nxt[curr];

                    curr = prev[curr];
                }
            }
        }
        else {
            cnt[i] = 1;
        }

        cout << total << "\n";
    }
	
    
	
	return 0;
}

