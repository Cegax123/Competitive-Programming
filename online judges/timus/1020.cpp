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

double dist(double a, double b, double c, double d) {
    double dx = c-a, dy = b-d;
    return sqrt(dx*dx + dy*dy);
}

double len(double a, double b) {
    return sqrt(a*a+b*b);
}

const double PI = 3.141592653589793;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; double r; cin >> n >> r;
    double x[n], y[n];
	
    for(int i = 0; i < n; i++) 
        cin >> x[i] >> y[i];

    double ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dist(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    }

    ans += 2.0 * PI * r;
    cout << setprecision(2) << fixed << ans << "\n";
	
	return 0;
}

