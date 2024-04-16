#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
const int p = 1e9 + 7;
const int h = 2;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

int mask[h];
int b[h];
int pb[h][maxn];

void gen() {
	for(int i = 0; i < h; i++) {
		b[i] = random(2, p-1);

		pb[i][0] = b[i];

		for(int j = 1; j < maxn; j++) {
			pb[i][j] = pb[i][j-1] * 1ll * b[i] % p;
		}
	}
}

int nonzero;
int cnt[maxn];

int main() {
	gen();

	int n, k; cin >> n >> k;

	auto add = [&](int j) {
		if(cnt[j] == 0) nonzero++;
		cnt[j]++;
		for(int i = 0; i < h; i++) {
			mask[i] = (mask[i] + pb[i][j]) % p;
		}
	};

	auto del = [&](int j) {
		cnt[j]--;
		if(cnt[j] == 0) nonzero--;
		for(int i = 0; i < h; i++) {
			mask[i] = (mask[i] - pb[i][j]) % p;
			if(mask[i] < 0) mask[i] += p;
		}
	};

	map<pair<int, int>, int> mp;
	mp[{0, 0}] = 1;

	int ans = 0;

	for(int i = 0; i < n; i++) {
		int c; cin >> c; c--;


		add(c);
		if(nonzero == k) {
			for(int j = 0; j < k; j++)
				del(j);
		}

		int pos = i+2;
		int lastpos = mp[{mask[0], mask[1]}];

		if(mp[{mask[0], mask[1]}]) {
			ans = max(ans, (pos-lastpos));
		}
		else mp[{mask[0], mask[1]}] = pos;
	}
	
	cout << ans << "\n";

	return 0;
}
