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
    deque<int> q1, q2;
    int k1; cin >> k1;

    for(int i = 0; i < k1; i++) {
        int x; cin >> x;
        q1.pb(x);
    }

    int k2; cin >> k2;

    for(int i = 0; i < k2; i++) {
        int x; cin >> x;
        q2.pb(x);
    }

    int cnt = -1;
    string winner;
    for(int i = 1; i <= 1000; i++) {
        if(q1[0] < q2[0]) {
            q2.pb(q1[0]); q2.pb(q2[0]);
            q1.pop_front();
            q2.pop_front();
            winner = "2";
        }
        else {
            q1.pb(q2[0]); q1.pb(q1[0]);
            q1.pop_front();
            q2.pop_front();
            winner = "1";
        }

        if(q1.empty() or q2.empty()) {
            cnt = i;
            break;
        }
    }



    cout << cnt << " " << (cnt == -1 ? "" : winner) << "\n";
	
    return 0;
}


