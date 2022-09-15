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

    const int maxn = 2e5 + 5;
    ll cnt[maxn], sum[maxn];
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));

    vi order;
    vector<string> s(n);

    for(int i = 0; i < n; i++) {
        cin >> s[i];

        for(char c : s[i]) {
            if(c == 'X') cnt[i]++;
            else sum[i] += c-'0';
        }

        if(sum[i] and cnt[i]) order.pb(i);
    }

    auto cmp = [&](int i, int j) {
        return cnt[i] * sum[j] > cnt[j] * sum[i];
    };

    sort(all(order), cmp);

    string t = "";

    for(int i = 0; i < n; i++)
        if(sum[i] == 0) t += s[i];

    for(int i = 0; i < (int) order.size(); i++)
        t += s[order[i]];

    for(int i = 0; i < n; i++)
        if(cnt[i] == 0) t += s[i];

    reverse(all(t));

    ll curr_sum = 0;
    ll ans = 0;

    for(char c : t) {
        if(c == 'X') ans += curr_sum;
        else curr_sum += c-'0';
    }

    cout << ans << "\n";
	
    return 0;
}


