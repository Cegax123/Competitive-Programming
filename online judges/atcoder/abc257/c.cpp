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
    string s; cin >> s;

    vii w(n);
    int cnt_child = 0;

    for(int i = 0; i < n; i++) {
        cin >> w[i].first;
        w[i].second = s[i]-'0';

        if(w[i].second == 0) cnt_child++;
    }

    int cnt_adult = n-cnt_child;
    int ans = max(cnt_child, cnt_adult);

    sort(all(w));
    int curr_child = 0;
    int curr_adult = 0;
    int ind = 0;

    while(ind < n) {
        int x = w[ind].first;
        while(ind < n and x == w[ind].first) {
            if(w[ind].second == 0) curr_child++;
            else curr_adult++;
            ind++;
        }

        ans = max(ans, curr_child + cnt_adult-curr_adult);
    }

    cout << ans << "\n";
	
    return 0;
}


