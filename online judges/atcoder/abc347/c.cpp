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
    int n, a, b; cin >> n >> a >> b;

    vector<int> days;
    for(int i = 0; i < n; i++) {
        int d; cin >> d;
        d %= (a+b);

        if(d >= 1 and d <= a) {
            days.push_back(d);
        }

        else {
            if(d == 0) d = a + b;
            days.push_back(d);
        }
    }

    sort(all(days));

    for(int i = 0; i < n; i++) days.push_back(days[i] + a + b);

    for(int i = 0; i < n; i++) {
        int j = i + n - 1;
        if(days[j] - days[i] + 1 <= a) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
	
    return 0;
}


