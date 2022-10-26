#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int p,n;
	cin>>p>>n;
	int r,c;
	char separator;
	cin>>r>>separator>>c;
	//cout<<r<<" "<<c<<"\n";
	string type;
	cin>>type;
	vector<string> a(p);
	cin.ignore();
	for(int i=0;i<p;i++){
	    getline(cin, a[i]);
		cout << a[i] << endl;
	}
	cin.ignore();
	string cipher;
	string reading;
	for(int i=0;i<n;i++){
	    string s;
	    getline(cin,s);
		cout << s << endl;
	    reading+=s;
	}
	
    bool ok=true;
    for(int j=0;j<reading.size();j++){
        if(ok){
            if(reading[j]=='<') ok=false;
            else cipher.pb(reading[j]);
        }else{
            if(reading[j]=='>') ok=true;
        }
    }
    if(cipher.size()>r*c) cipher.resize(r*c);
	map<char,vector<int>> mp;
	for(int i=0;i<cipher.size();i++){
	    mp[cipher[i]].pb(i);
	}
	for(int i=0;i<p;i++){
	    string ans;
	    for(int j=0;j<a[i].size();j++){
    	    if(mp.count(a[i][j])){
    	        if(type[0]=='S'){
    	            int x=mp[a[i][j]][0]/c;
    	            int y=mp[a[i][j]][0]%c;
    	            ans+=to_string(x+1)+","+to_string(y+1)+",";
    	        }else if(type[0]=='L'){
    	            int x=mp[a[i][j]].back()/c;
    	            int y=mp[a[i][j]].back()%c;
    	            ans+=to_string(x+1)+","+to_string(y+1)+",";
    	            
    	        }
    	    }else{
    	        ans.clear();
    	        break;
    	    }
	    }
    	if(ans.size()>0) ans.popb();
    	else ans="0";
    	cout<<ans<<"\n";
	}
    return 0;
}
