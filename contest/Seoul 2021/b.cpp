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
    int n = 6;
    int a[n];
    int b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            sum += a[i] > b[j];

    int total = 36;
    int d = __gcd(sum, total);

    cout << sum / d << "/" << total / d << "\n";
	
    return 0;
}


