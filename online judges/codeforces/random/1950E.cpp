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

const int E = 26;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        auto cmp = [&](int len) {
            int cnt = 0;
            for(int i = 0; i < len; i++) {
                char c1 = '#', c2 = '#';
                int cnt1 = 0, cnt2 = 0;
                for(int j = i; j < n; j += len) {
                    char c = s[j];
                    if(c1 == '#') {
                        c1 = c;
                        cnt1++;
                    }
                    else if(c == c1) {
                        cnt1++;
                    }
                    else if(c2 == '#') {
                        c2 = c;
                        cnt2++;
                    }
                    else if(c == c2) {
                        cnt2++;
                    }
                    else return false;
                }

                if(cnt1 > 1 and cnt2 > 1) return false;
                if(cnt2 >= 1) cnt++;
            }

            return cnt <= 1;
        };

        int len = n;
        for(int i = n; i >= 1; i--) {
            if(n % i == 0) if(cmp(i)) len = i;
        }

        cout << len << "\n";
    }

	
    return 0;
}


