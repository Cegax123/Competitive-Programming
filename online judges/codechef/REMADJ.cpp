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

const int maxn = 3e4+5;

int n, a[maxn], sum;

bool comp(int x) {
	int k = sum / x;
    int target = k;

    for(int i = 0; i < n-1; i++) {
        if(a[i] == target) {
            target += k;

            if(target == sum) break;
        }
    }

    return target == sum;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		cin >> n;
		
		for(int i = 0; i < n; i++)
			cin >> a[i];

		for(int i = 1; i < n; i++)
			a[i] += a[i-1];

        sum = a[n-1];

        if(sum == 0) {
            int cnt = 1;

            for(int i = 0; i < n-1; i++) 
                if(a[i] == 0)
                    cnt++;
            
            cout << n-cnt << "\n";
            continue;
        }

        int ans = 1;
		for(int i = 1; i*i <= abs(sum); i++) {
			if(sum % i == 0) {
                if(comp(i)) ans = max(ans, i);
                if(comp(abs(sum/i))) ans = max(ans, abs(sum/i));
            }
		}

		cout << n-ans << "\n";
	}
	
	return 0;
}

