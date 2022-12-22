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

const int maxn = 1e6;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    vi pos_boxes(n+1);
    iota(all(pos_boxes), 0);

    vector<pair<int, vi> > boxes(n+1);

    for(int i = 1; i <= n; i++) {
        boxes[i].first = i;
        boxes[i].second.pb(i);
    }

    int what_box[maxn];

    for(int i = 1; i <= n; i++)
        what_box[i] = i;

    auto move_from_to = [&](int from, int to) {
        for(int x : boxes[from].second) {
            what_box[x] = to;
            boxes[to].second.pb(x);
        }
        boxes[from].second.clear();
    };

    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int x, y; cin >> x >> y;
            int px = pos_boxes[x], py = pos_boxes[y];

            if(boxes[px].second.size() < boxes[py].second.size()) {
                move_from_to(px, py);
                pos_boxes[x] = py;
                pos_boxes[y] = px;

                swap(boxes[px].first, boxes[py].first);
            }
            else 
                move_from_to(py, px);
        }
        else if(op == 2) {
            int x; cin >> x;
            int px = pos_boxes[x];

            n++;

            boxes[px].second.pb(n);
            what_box[n] = px;
        }
        else {
            int x; cin >> x;
            cout << boxes[what_box[x]].first << "\n";
        }
    }
	
    return 0;
}


