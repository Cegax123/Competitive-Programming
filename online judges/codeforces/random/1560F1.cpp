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

bool cmp(string n, int k) {
    set<char> s;
    for(int i = 0; i < (int) n.size(); i++)
        s.insert(n[i]);
    return (int) s.size() <= k;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        string n; int k; cin >> n >> k;

        if(cmp(n, k)) {
            cout << n << "\n";
            continue;
        }

        int c = n.size();
        string ans = "";

        for(char d = '1'; d <= '9'; d++) {
            string tmp = "";
            for(int i = 0; i < c; i++) {
                tmp += d;
            } 
            if(tmp >= n) {
                ans = tmp;
                break;
            }
        }

        if(k == 2) {
            for(char d1 = '0'; d1 <= '9'; d1++) {
                for(char d2 = d1+1; d2 <= '9'; d2++) {
                    for(int i = 0; i < c; i++) {
                        if(n[i] < d2) {
                            string tmp = n;
                            if(n[i] < d1) tmp[i] = d1;
                            else tmp[i] = d2;

                            for(int j = i+1; j < c; j++)
                                tmp[j] = d1;

                            if(tmp < ans) ans = tmp;
                        }
                        if(n[i] != d1 and n[i] != d2)
                            break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
	
	
	return 0;
}