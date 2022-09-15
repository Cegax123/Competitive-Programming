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
    int p[n+1], pos[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    auto swap_per = [&] (int i, int j) {
        int x = p[i], y = p[j];
        swap(p[i], p[j]);
        swap(pos[x], pos[y]);
    };

    auto is_marked = [&] (int i) {
        return abs(p[i]-i)&1;
    };

    vector<pair<char, int> > op;

    for(int i = 1; i <= n; i++) {
        if(!is_marked(i)) continue;

        int idx = i+1;
        for(int j = i + 1; j <= n; j += 2) {
            if(is_marked(j)) {
                idx = j;
                break;
            }
        }
    
        //cout << idx << endl;

        while(idx > i + 1) {
            op.pb({'B', idx-2});
            swap_per(idx, idx-2);
            idx -= 2;
        }

        op.pb({'A', i});
        swap_per(i, i+1);
    }


    for(int i = 1; i <= n; i++) {
        if(pos[i] == i) continue;

        while(pos[i] - i >= 2) {
            op.pb({'B', pos[i]-2});
            swap_per(pos[i], pos[i]-2);
        }
    }

    cout << op.size() << "\n";
    for(auto x : op)
        cout << x.first << " " << x.second << "\n";
	
    return 0;
}


