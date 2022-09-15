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
        int n; cin >> n;
        vi cnt(10, 0);

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a%10]++;
        }

        bool found = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    cnt[i]--; cnt[j]--; cnt[k]--;

                    if(cnt[i] >= 0 and cnt[j] >= 0 and cnt[k] >= 0)
                        found = 1;

                    cnt[i]++; cnt[j]++; cnt[k]++;
                }
            }
        }
    }

	
    return 0;
}


