#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int M=1e6+10;
const int hp=51673;
const int mo=1e9+7;
const int inf=1e9;
ll pw[M];string str;
struct zms{
	int tot=1,p[26][M],f[M],h[M],id[M],ps[N];
	ll hs[M];unordered_set<ll>s;vector<ll>gt[N];
	void init(int ID,const string&str,bool ty){
		int x=1;
		for(auto&i:str){int y=i-'a';
			if(!p[y][x]){
				p[y][x]=++tot;
				h[tot]=h[x]+1;f[tot]=x;
				if(ty)hs[tot]=hs[x]+i*pw[h[x]];
				else hs[tot]=hs[x]*hp+i;
			}
			x=p[y][x];
		}
		id[x]=ID;ps[ID]=x;
	}
	void mrk(int ID,bool ty){
		for(int x=f[ps[ID]];x;x=f[x])if(id[x]){ll res;
			if(ty)res=(hs[ps[ID]]-hs[x])*pw[M-1-h[ps[ID]]];
			else res=hs[ps[ID]]*pw[M-1-h[ps[ID]]+h[x]]-hs[x]*pw[M-1];
			gt[ID].push_back(res);
			gt[id[x]].push_back(res);
			s.insert(res);
		}
	}
}a,b;
int main(){pw[0]=1;
	rep(i,1,M-1)pw[i]=pw[i-1]*hp;
	int n,m;cin.tie(0);cin>>n>>m;
	rep(i,1,n){
		cin>>str;a.init(i,str,0);
	}
	rep(i,1,m){
		cin>>str;reverse(str.begin(),str.end());b.init(i,str,1);
	}
	rep(i,1,n)a.mrk(i,0);
	rep(i,1,m)b.mrk(i,1);
	int ans=0;
	rep(i,1,n){bool fl=1;
		for(auto&j:a.gt[i])if(b.s.count(j)){
			fl=0;break;
		}
		ans+=fl;
	}
	printf("%d ",ans);
	ans=0;
	rep(i,1,m){bool fl=1;
		for(auto&j:b.gt[i])if(a.s.count(j)){
			fl=0;break;
		}
		ans+=fl;
	}
	printf("%d\n",ans);
}

