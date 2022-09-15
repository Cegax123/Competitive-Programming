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
 
const int maxn = 4e4;
int sieve[maxn+5];
vi primes;
 
void fill_sieve() {
	sieve[1] = 1;
	for(int i = 2; i <= maxn; i++) {
		if(sieve[i]) continue;
 
		sieve[i] = i;
		primes.pb(i);
 
		for(int j = 2; i*j <= maxn; j++) {
			if(sieve[i*j]) continue;
			sieve[i*j] = i;
		}
	}
}

int find_index(int x, const vi& f) {
	for(int i = 0; i < (int) f.size(); i++)
		if(x == f[i]) return i;
	return f.size()+10;
}
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
	fill_sieve();
 
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		vi f, exp;
		int tmp = n;

		for(int p : primes) {
			if(tmp % p == 0) {
				f.pb(p);

				int cnt = 0;
				while(tmp % p == 0) {
					tmp /= p;
					cnt++;
				}
				exp.pb(cnt);
			}
		}

		if(tmp != 1) {
			f.pb(tmp);
			exp.pb(1);
		}

		if((int) f.size() == 1) {
			int fk = f[0];
			for(int i = 0; i < exp[0]; i++) {
				cout << fk << " ";
				fk *= f[0];
			}
			cout << "\n0\n";
			continue;
		}

		if((int) f.size() == 2 and exp[0] == 1 and exp[1] == 1) {
			cout << f[0] << " " << f[0] * f[1] << " " << f[1] << "\n";
			cout << "1\n";
			continue;
		}

		if((int) f.size() == 2) {
			vi v1, v2;

			for(int i = 2; i*i <= n; i++) {
				if(n%i == 0) {
					int d1 = i, d2 = n/i;

					if(d1 != f[0] and d1 != f[1] and d1 != f[0] * f[1]) {
						if(d1 % f[0] == 0) v1.pb(d1);
						else v2.pb(d2);
					}
					
					if(d1 == d2) continue;

					if(d2 != f[0] and d2 != f[1] and d2 != f[0] * f[1]) {
						if(d2 % f[0] == 0) v1.pb(d2);
						else v2.pb(d2);
					}
				}
			}

			cout << f[0] << " ";

			for(int c : v1)
				cout << c << " ";

			cout << f[0] * f[1] << " ";

			cout << f[1] << " ";

			for(int c : v2)
				cout << c << " ";

			cout << n << "\n0\n";
			continue;
		}

		vector<vi> comp(f.size());

		for(int i = 2; i*i <= n; i++) {
			if(n%i) continue;

			int d1 = i, d2 = n/i;
			
			for(int j = 0; j < (int) f.size(); j++) {
				if(d1 == f[j]) break;
				
				if(d1 % f[j] == 0) {
					int x = d1 / f[j];

					if(x == f[(j+1)%f.size()]) break;
					if(x == f[(j+f.size()-1)%f.size()]) break;

					comp[j].pb(d1);

					break;
				}
			}

			if(d1 == d2) continue;

			for(int j = 0; j < (int) f.size(); j++) {
				if(d2 == f[j]) break;
				
				if(d2 % f[j] == 0) {
					int x = d2 / f[j];

					if(x == f[(j+1)%f.size()]) break;
					if(x == f[(j+f.size()-1)%f.size()]) break;

					comp[j].pb(d2);
					break;
				}
			}
		}

		int cnt = 0;
		comp[0].pb(n);

		for(int i = 0; i < (int) f.size(); i++) {
			cout << f[i] << " ";
			for(int c : comp[i]) {
				cout << c << " ";
			}
			cout << f[i] * f[(i+1)%f.size()] << " ";
		}
		cout << "\n0\n";
	}
	
	return 0;
}
