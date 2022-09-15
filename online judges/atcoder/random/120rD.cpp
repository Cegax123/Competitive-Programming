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
    vii a(2 * n);

    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));

    int c[2 * n];

    for(int i = 0; i < n; i++) 
        c[a[i].second] = 0;

    for(int i = n; i < 2 * n; i++)
        c[a[i].second] = 1;

    vi st;

    for(int i = 0; i < 2 * n; i++) {
        if(st.empty()) {
            cout << "(";
            st.pb(c[i]);
        }
        else {
            if(st.back() != c[i]) {
                cout << ")";
                st.pop_back();
            }
            else {
                cout << "(";
                st.pb(c[i]);
            }
        }
    }
	
    return 0;
}


