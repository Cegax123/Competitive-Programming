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
    ll n, k; cin >> n >> k;

    ll sum = (k-1) * k / 2ll;
    ll a_1 = (n-sum) / k;

    if(a_1 <= 0) {
        cout << "NO\n";
        return 0;
    }

    ll rem = (n-sum)%k;
	
    vi x(k, 1);

    if(rem) {
        if(a_1 > 1) {
            x[rem]++;
        }
        else {
            if(rem < k-1)
                x[rem]++;
            else {
                if(k == 3 or k == 2) {
                    cout << "NO\n";
                    return 0;
                }
                else {
                    x[1]++;
                    x[rem-1]++;
                }
            }
        }
    }

    int a[k+1];

    a[1] = a_1;

    for(int i = 2; i <= k; i++)
        a[i] = a[i-1] + x[k+1-i];

    cout << "YES\n";
    for(int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
	
	return 0;
}

