#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back
#define f first
#define s second 
//#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define dbg(x) do {} while (false)
//#define raya do {cerr << "===========================" << endl; } while (false)
#define raya do {} while (false)
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll 
#define max_bit(A) 31-__builtin_clz(A)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> ii; 

const int max_col = 50;
const int alph = 26;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n; cin >> n;
	vector<string>vec(n);
	for(int i=0;i<n;i++)cin>>vec[i];

	for(int col = 0;col<max_col;col++){
		if(col) cout << "\n";
		vector<int> cnt(alph, 0);

		for(int i=0;i<n;i++){
			if(col >= (int)vec[i].size()) continue;

			cnt[vec[i][col]-'a']++;
		}
		int maxi = 0;
		for(int i=0;i<alph;i++)
			maxi = max(maxi, cnt[i]);
		if(maxi == 0) break;

		vector<int>cur;
		for(int i=0;i<alph;i++)
			if(cnt[i] == maxi) cur.pb(i);

		cout<<col+1<<": ";
		for(auto e:cur){
			char ele = e+'a';
			cout << ele;
			if(e != cur.back()) cout << " ";
		}
	}
	return 0;
}






