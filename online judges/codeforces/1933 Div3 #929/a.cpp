#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define pb push_back 
typedef long long ll;
typedef pair<int, int> ii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            sum += abs(a);
        }

        cout << sum << "\n";
    }

	
    return 0;
}

