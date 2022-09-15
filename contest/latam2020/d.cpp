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

const int maxn = 2e5;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    int cnt[maxn];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
	
    for(int i = 0; i < maxn-1; i++) {
        cnt[i+1] += cnt[i] / 2;
        cnt[i] &= 1;
    }

    int cc = 0;

    for(int i = 0; i < maxn; i++)
        if(cnt[i]) cc++;

    if(cc == 2 || (cc == 1 and n > 1)) {
        cout << "Y\n";
    }
    else {
        cout << "N\n";
    }
	
	return 0;
}

