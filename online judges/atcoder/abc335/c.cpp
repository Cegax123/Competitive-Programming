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
    int n, q; cin >> n >> q;

    deque<pair<int, int>> dq;

    for(int i = 1; i <= n; i++) {
        dq.push_back({i, 0});
    }

    for(int i = 0; i < q; i++) {
        int op; cin >> op;
        if(op == 1) {
            char d; cin >> d;
            pair<int, int> head = dq[0];
            pair<int, int> nhead;
            if(d == 'R') {
                nhead = {head.first+1, head.second};
            }
            else if(d == 'L') {
                nhead = {head.first-1, head.second};
            }
            else if(d == 'U') {
                nhead = {head.first, head.second + 1};
            }
            else {
                nhead = {head.first, head.second - 1};
            }

            dq.push_front(nhead);
            dq.pop_back();
        }
        else {
            int p; cin >> p;
            p--;

            cout << dq[p].first << " " << dq[p].second << "\n";
        }
    }
	
    return 0;
}


