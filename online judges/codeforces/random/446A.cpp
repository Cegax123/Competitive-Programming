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
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1) {
        cout << "1\n";
        return 0;
    }

    int L[n], R[n];
    L[0] = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1])
            L[i] = L[i-1] + 1;
        else 
            L[i] = 1;
    }

    R[n-1] = 1;

    for(int i = n-2; i >= 0; i--) {
        if(a[i] < a[i+1])
            R[i] = R[i+1] + 1;
        else 
            R[i] = 1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max({ans, L[i], R[i]});
        if(i) ans = max(ans, L[i-1]+1);
        if(i < n-1) ans = max(ans, R[i+1]+1);
    }

    for(int i = 1; i < n-1; i++) 
        if(a[i-1]+1 < a[i+1]) ans = max(ans, R[i+1] + L[i-1] + 1);

    cout << ans << "\n";
   
    return 0;
}


