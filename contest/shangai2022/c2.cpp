#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back
#define f first
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
ll s,c;
 const ll itermax = 1500;
ll nt(ll x){
  return ((x+1)*x)/2;
}
ll f(ll a){
  ll normali = nt(s) - nt(a) ;
  ll lo;
  lo = (a+c)/(c+1);
  ll coffe = (a*lo - ((c+1)*((lo-1)*lo)/2))*c;
  return normali+coffe;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    s = 10;
    c = 4;

    for(int i = 1; i <= 10; i++)
      cout << f(i) << " ";

    cout << endl;

    int t;
    cin>>t;
    while(t--){
      cin>>s>>c;
      if(c==1){
          cout<<nt(s)<<endl;
          continue;
      }
      ll ans = s*c;
      for(ll i=1;i<=itermax;i++)
            ans = max(ans,f(i));
    cout<<ans<<endl;
    }
    return 0;
}

