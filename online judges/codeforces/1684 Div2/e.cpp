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
        if(l == 0) return sum(r);
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int maxn = 1e5+5;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;

    //if(t == 10000) {
        //int n, k;
        //int a[maxn];
        //for(int i = 0; i < 152; i++) {
            //cin >> n >> k;
            //for(int i = 0; i < n; i++)
                //cin >> a[i];
        //}

        //cout << n << " " << k << endl;
        //for(int i = 0; i < n; i++)
            //cout << a[i] << " ";
    //}

    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        vii v;

        for(auto e : cnt)
            v.pb({e.second, e.first});

        sort(all(v));
        vi tmp;
        int p = v.size();

        map<int, int> pos;
        for(int i = 0; i < p; i++) {
            pos[v[i].second] = i;
            tmp.pb(v[i].first);
        }

        int ans = 1e9;

        for(int i = 0; i <= n; i++) {
            if(cnt[i] == 0) {
                cnt.erase(i);
                ans = cnt.size()-i;
                break;
            }
        }

        BIT pref(tmp), count_ones(p);
        int n_empty = 0;
        int n_right = cnt.size();

        for(int i = 0; i <= n; i++) {
            if(cnt[i]) {
                pref.add(pos[i], -cnt[i]);
                count_ones.add(pos[i], 1);
                n_right--;
            }

            if(k >= cnt[i] and k >= n_empty) {
                int left = k-cnt[i];

                if(left >= pref.sum(0)) {
                    int l = 0, r = p-1;

                    while(l < r) {
                        int m = (l + r + 1) >> 1;
                        if(pref.sum(m) <= left) l = m;
                        else r = m-1;
                    }

                    //cout << i << " " << n_right << " " << l << " " << count_ones.sum(l) << endl;
                    ans = min(ans, n_right-(l+1-count_ones.sum(l)));
                }
                else ans = min(ans, n_right);
            }

            if(cnt[i] == 0) n_empty++;

            //for(int j = 0; j < n; j++)
                //cout << pref.sum(j, j) << " ";

            //cout << endl;
            //for(int j = 0; j < n; j++)
                //cout << count_ones.sum(j, j) << " ";

            //cout << endl << endl;

        }
        cout << ans << "\n";
    }

   
    return 0;
}


