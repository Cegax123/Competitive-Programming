#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back
#define s second 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
//#define dbg(x) do {} while (false)
#define raya do {cerr << "===========================" << endl; } while (false)
//#define raya do {} while (false)
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll 
#define max_bit(A) 31-__builtin_clz(A)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> ii; 
map<ll,int>pos;

const int maxn = 52;
ll f[maxn][maxn];

ll find(ll x, int k) {
	if(k == 0) return 1ll;
    int pos = -1;

    for(int i = 0; i < 52; i++) {
        if((x >> i)&1ll) pos = i;
    }


    if(pos == -1) {
        if(k == 0) return 1ll;
        return 0ll;
    }
    if(pos+1 < k) return 0ll;

	//cout << f[pos][k-1] << "\n";
    return f[pos][k] + find((x ^ (1ll << pos)), k-1);
}


vector<int> fm(vector<ll>& v,vector<int> & ret , ll val){
	bool ok = 0;
	int l = (int)v.size();
	for(int i=0;i<l;i++){
		if(v[i]>val){
			ok = 1;
		
			if(i>0){
				ret.pb(pos[v[i-1]]);
			
				val-=v[i-1];
				v.erase(begin(v)+i-1);
			
				return fm(v,ret,val);
				break ;
			}
			else {
				vector<int>tmp(maxn);
				for(int j=0;j<maxn;j++) tmp[j] = 0;
				for( auto e:ret) tmp[e] = 1;
				return tmp;
				break;
			}
		}
	}
	if(!ok){
		if(l>=1){
			ret.pb(pos[v[l-1]]);
			val-=v[l-1];
			v.erase(begin(v)+l-1);
			return fm(v,ret,val);
		}
		else{
			vector<int>tmp(maxn);
			for(int j=0;j<maxn;j++) tmp[j] = 0;
			for( auto e:ret) tmp[e] = 1;
			return tmp;		
		}
	}
}

ll find2(ll x, int k) {
    ll ans = 0;
    for(ll i = 0; i <= x; i++) {
        int cnt = 0;

        for(int j = 0; j < 52; j++) {
            if((i >> j) &1) cnt++;
        }
        if(cnt == k) ans++;
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(f, 0, sizeof(f));
    f[0][0] = 1ll;


    for(int i = 1; i < maxn; i++) {
        f[i][0] = 1ll;
        for(int j = 1; j <= i; j++) {
            for(int y = 0; y < i; y++) {
                f[i][j] += f[y][j-1];
            }
        }
    }

	int n,k;
	cin>>n>>k;
	vector<ll>v(n),a(n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(all(v));

	a = v;

	for(int i=0;i<n;i++)
		pos[v[i]] = i;
	
	vector<int>v1,v2;
	vector<int> msk1,msk2;
	v1.clear() , v2.clear();
	ll l,r;
	cin>>l>>r;
	
	msk1 = fm(v,v1,l-1);
	msk2 = fm(a,v2, r );	

	ll n1 = 0, n2 = 0;

	for(int i = 0; i < maxn; i++) {
		if(msk1[i]) n1 |= (1ll << i);
		if(msk2[i]) n2 |= (1ll << i);
	}

	ll ans = find(n2, k)-find(n1, k);

	//cout << find(31, 2) << "\n";
	//cout << find(n2, k) << " " << find(n1, k) << endl;

	cout << ans << "\n";


	//for(auto e1:msk1)cout<<e1<<" ";
	//cout<<endl;
	//for(auto e2:msk2)cout<<e2<<" ";
	//cout<<endl;


    return 0;
}

