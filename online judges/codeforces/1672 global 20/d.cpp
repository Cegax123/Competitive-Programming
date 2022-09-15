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
        vi a(n), b(n);

        vi cnt(n+1, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for(int i = 0; i < n; i++)
            cin >> b[i];

        reverse(all(a));
        reverse(all(b));

        vi used(n+1, 0);
        int inda = 0, indb = 0;
        bool cmp = true;

        while(indb < n) {
            if(inda >= n) {
                cmp = false;
                break;
            }

            while(inda < n and used[a[inda]] and a[inda] != b[indb]) {
                used[a[inda]]--;
                inda++;
            }

            if(inda >= n or a[inda] != b[indb]) {
                cmp = false;
                break;
            }

            int curr = b[indb];
            int need = 0;

            while(indb < n and b[indb] == curr) {
                need++;
                indb++;
            }

            int r = inda;
            int have = 0;

            while(r < n and a[r] == a[inda]) {
                have++;
                r++;
            }

            if(cnt[a[inda]] >= need and have-used[a[inda]] <= need) {
                cnt[a[inda]] -= need;
                
                if(have >= need) {
                    used[a[inda]] -= have-need;
                }
                else {
                    used[a[inda]] += need-have;
                }

                inda = r;
            }
            else {
                cmp = 0;
                break;
            }
        }
        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


