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
    int n, m, k; cin >> n >> m >> k;
    const int B = 500;

    int a[n], c[n];
    int p[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = i;
    }

    sort(c, c + n, [&](int x, int y) {
            return a[x] < a[y];
            });

    int val[n];
    for(int i = 0; i < n; i++) {
        p[c[i]] = i;
        val[i] = a[c[i]];
    }

    ll cnt[B], sum[B], cnt2[n];

    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    memset(cnt2, 0, sizeof(cnt2));

    auto insert = [&](int x, int v) {
        cnt[x / B]++;
        sum[x / B] += v;
        cnt2[x]++;
    };

    auto remove = [&](int x, int v) {
        cnt[x / B]--;
        sum[x / B] -= v;
        cnt2[x]--;
    };

    for(int i = 0; i < m-1; i++)
        insert(p[i], a[i]);

    for(int i = m-1; i < n; i++) {
        insert(p[i], a[i]);

        //cout << i << ": \n";

        int currcnt = 0;
        ll currsum = 0;
        int idx = 0;
        for(int j = 0; j < B; j++) {
            idx = j;
            if(currcnt + cnt[j] < k) {
                currcnt += cnt[j];
                currsum += sum[j];
            }
            else break;
        }

        //if(i == 4) cout << cnt2[3] << endl;

        for(int j = idx * B; j < idx * B + B; j++) {
            if(cnt2[j] == 0) continue;

            //cout << j << " " << val[j] << " " << currcnt << endl;

            currcnt++;
            currsum += val[j];
            if(currcnt == k) break;
        }

        cout << currsum << " ";
        //cout << endl << endl;

        remove(p[i-m+1], a[i-m+1]);
    }
	
    return 0;
}


