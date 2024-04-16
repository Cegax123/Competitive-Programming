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

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        BIT bit(n);
        BIT men(n);

        int a[n];
        vi pos[n];
        vii b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]].push_back(i);
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].first--;
            b[i].second = i;
        }

        bool cmp = true;

        sort(all(b));
        
        int last = 0;
        int ind = 0;
        while(ind < n) {
            int x = b[ind].first;

            for(int i = last; i <= x; i++) {
                for(int p : pos[i]) {
                    bit.add(p, 1);
                }
            }

            if(pos[x].empty()) {
                cmp = false;
                break;
            }

            last = x+1;

            vi rang;

            int r = ind;
            while(r < n and b[r].first == b[ind].first) {
                rang.push_back(b[r].second);
                r++;
            }

            ind = r;

            vii div;
            
            int rem = 0;
            for(int i = 1; i < (int) rang.size(); i++) {
                if(rang[i] != rang[i-1] + 1) {
                    div.push_back({rang[rem], rang[i-1]});
                    rem = i;
                }
            }
            div.push_back({rang[rem], rang.back()});

            for(auto e : div) {
                bool actual = false;

                int l = 0, r = pos[x].size()-1;
                
                while(l < r) {
                    int m = (l+r) >> 1;
                    if(pos[x][m] >= e.first) r = m;
                    else l = m+1;
                }

                if(pos[x][l] >= e.first and pos[x][l] <= e.second) actual = true;
                else if(pos[x][l] > e.second) {
                    if(bit.sum(e.second+1, pos[x][l]) == pos[x][l]-e.second
                            and men.sum(e.second+1, pos[x][l]) == 0) actual = true;
                }

                l = 0, r = pos[x].size()-1;

                while(l < r) {
                    int m = (l+r+1) >> 1;
                    if(pos[x][m] <= e.second) l = m;
                    else r = m-1;
                }

                if(pos[x][l] >= e.first and pos[x][l] <= e.second) actual = true;
                else if(pos[x][l] < e.first) {
                    if(bit.sum(pos[x][l], e.first-1) == e.first-pos[x][l]
                            and men.sum(pos[x][l], e.first-1) == 0) actual = true;
                }

                if(!actual) cmp = false;
            }

            for(auto p : rang) men.add(p, 1);

        }

        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


