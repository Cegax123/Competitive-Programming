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
	string s; cin >> s;
    int n = s.size();

    vii st;

    int c[n], d[n];

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            c[i] = d[i] = -1;
            st.pb({0, i});
        }
        else {
            if(st.empty() or st.back().first) {
                c[i] = d[i] = -1;
                st.pb({1, i});
            }
            else {
                c[i] = d[i] = st.back().second;
                st.pop_back();

                if(d[i]-1 >= 0 and c[d[i]-1] != -1) c[i] = c[d[i]-1];
            }
        }
    }

    int ans = 0;
    int cnt = 1;

    for(int i = 0; i < n; i++) {
        if(c[i] == -1) continue;

        if(ans < i-c[i]+1) {
            ans = i-c[i]+1;
            cnt = 1;
        }
        else if(ans == i-c[i]+1) 
            cnt++;
    }

    cout << ans << " " << cnt << "\n";
	
	return 0;
}

