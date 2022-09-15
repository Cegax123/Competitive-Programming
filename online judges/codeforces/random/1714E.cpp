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

int f(int x) {
    return x + x % 10;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];

        bool flag5 = false;

        for(int i = 0; i < n; i++) {
            cin >>  a[i];
            if(a[i] % 5 == 0) {
                flag5 = true;
                a[i] = f(a[i]);
            }
        }

        if(flag5) {
            int max_el = *max_element(a, a + n);
            int min_el = *min_element(a, a + n);
            cout << (max_el == min_el ? "Yes\n" : "No\n");
        }
        else {
            bool flag2 = false, flag12 = false;

            for(int i = 0 ; i < n; i++) {
                int x = a[i];
                while(x % 10 != 2) 
                    x = f(x);

                if(x % 20 == 2)
                    flag2 = 1;
                else 
                    flag12 = 1;
            }

            cout << ((flag2 and flag12) ? "No\n" : "Yes\n");
        }
    }

	
    return 0;
}


