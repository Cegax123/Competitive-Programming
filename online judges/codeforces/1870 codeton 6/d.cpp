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
        map<int, vi> pos;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            
        }
        int k; cin >> k;

        stack<ii> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() and a[st.top().first] > a[i]) {
                k += a[st.top().first] * st.top().second;
                st.pop();
            }

            if(!st.empty()) {
                int cnt = k / a[st.top().first];
                k %= a[st.top().first];
                st.top().second += cnt;
            }

            if(st.empty()) {
                st.push({i, k/a[i]});
                k %= a[i];
                continue;
            }
            else if(a[st.top().first] == a[i]) {
                int cnt = st.top().second;
                st.pop();
                st.push({i, cnt});
            }
            else {
                int lpos = st.top().first;
                int cnt = min(st.top().second, k / (a[i]-a[lpos]));
                
                k += cnt * a[lpos];
                st.top().second -= cnt;

                k -= cnt * a[i];
                st.push({i, cnt});
            }
        }

        int ans[n];
        memset(ans, 0, sizeof(ans));

        while(!st.empty()) {
            ans[st.top().first] += st.top().second;
            st.pop();
        }

        for(int i = n-2; i >= 0; i--)
            ans[i] += ans[i+1];

        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

	
    return 0;
}


