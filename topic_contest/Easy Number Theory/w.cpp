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

bool isP(int x) {
    if(x <= 1) return false;

    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    const int maxa = 10000 + 1;
    int cnt[maxa];

    for(int i = 0; i < maxa; i++) {
        int x = i * i + i + 41;
        cnt[i] = isP(x);
        if(i) cnt[i] += cnt[i-1];
    }

    int a, b;
    while(cin >> a >> b) {
        int total = b-a+1;
        int div = cnt[b] - (a == 0 ? 0 : cnt[a-1]);

        double ans = div * 1.0 / total;
        ans *= 100.0;

        ans *= 100.0;

        ans = round(ans);
        ans /= 100.0;

        cout << setprecision(2) << fixed;
        cout << ans << "\n";
    }
	
    return 0;
}


