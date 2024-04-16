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
    int b, l; cin >> b >> l;

    int a[l+1];

    int sum = 0;

    for(int i = 1; i <= l; i++) {
        cin >> a[i];
        if(i&1) sum += a[i];
        else sum -= a[i];
    }

    sum %= b+1;
    if(sum < 0) sum += b+1;

    int rsum = (b+1-sum) % (b+1);

    int ans = -1, d = -1;
    if(sum == 0) ans = 0, d = 0;

    for(int i = 1; i <= l; i++) {
        if(ans == 0) break;
        if(i&1) {
            if(sum <= a[i]) {
                ans = i;
                d = a[i]-sum;
                break;
            }
        }
        else {
            if(rsum <= a[i]) {
                ans = i;
                d = a[i]-rsum;
                break;
            }
        }

    }

    cout << ans << " " << d << endl;
	
    return 0;
}


