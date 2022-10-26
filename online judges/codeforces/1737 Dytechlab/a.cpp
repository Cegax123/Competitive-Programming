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
    int TT;
    cin >> TT;

    while(TT--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int cnt[26];
        memset(cnt, 0, sizeof(cnt));

        for(char c : s) cnt[c-'a']++;

        int b[k][26];
        int sum[k];
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));

        for(int j = 0; j < 26; j++) {
            for(int i = 0; i < k; i++) {
                if(cnt[j] and sum[i] < n/k) {
                    b[i][j]++;
                    sum[i]++;
                    cnt[j]--;
                }
            }
        }

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < 26; j++) {
                if(b[i][j] == 0) {
                    char c = j+'a';
                    cout << c;
                    break;
                }
            }
        }

        cout << "\n";
    }

	
    return 0;
}


