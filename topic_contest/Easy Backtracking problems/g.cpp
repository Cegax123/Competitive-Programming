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

vi curr;
int k = 4;
vi digs;
int cnt[10];
int len;
vector<string> ans;
vi v;
int total = 0;

int cd(int x) {
    if(x == 0) return 1;
    int ans = 0;
    while(x) {
        ans++;
        x /= 10;
    }
    return ans;
}

void gen(int pos = 0) {
    if(pos == (len+1)/2) {
        for(int x : digs) if(cnt[x] == 0) return;

        for(int i = len/2-1; i >= 0; i--) {
            v.pb(v[i]);
        }

        assert((int) v.size() == len);

        int num[k];

        bool cmp = 1;
        int tmp = 0;
        for(int i = 0; i < k; i++) {
            num[i] = 0;
            for(int j = 0; j < curr[i]; j++) {
                num[i] = num[i] * 10 + v[tmp + j];
            }
            if(cd(num[i]) != curr[i]) {
                cmp = 0;
            }
            if(num[i] > 255) cmp = 0;
            tmp += curr[i];
        }

        if(cmp) {
            string t;
            for(int i = 0; i < k; i++) {
                string snum;
                for(int j = 0; j < curr[i]; j++) {
                    snum += (char) '0' + num[i] % 10;
                    num[i] /= 10;
                }
                reverse(all(snum));
                t += snum;
                if(i != k-1) t += ".";
            }
            ans.pb(t);
        }

        for(int i = 0; i < len/2; i++)
            v.pop_back();
        
        return;
    }

    for(int x : digs) {
        v.pb(x);
        cnt[x]++;

        gen(pos+1);

        v.pop_back();
        cnt[x]--;
    }
}

void solve(int pos = 0) {
    if(pos == k) {

        len = 0;
        for(int x : curr)
            len += x;

        gen();
        return;
    }

    for(int i = 1; i <= 3; i++) {
        curr.pb(i);
        solve(pos+1);
        curr.pop_back();
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        digs.pb(x);
    }

    sort(all(digs));

    solve();

    cout << ans.size() << "\n";
    for(string t : ans) {
        cout << t << "\n";
    }
	
    return 0;
}


