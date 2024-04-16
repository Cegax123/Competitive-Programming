#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc builtin_popcountll//numero de bits para long long
#define bclz builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

int f(string s){
    int ans=0,cover=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1' && i>=cover) cover=i+3,ans++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=1;i+j<=n;j++){
                ans+=f(s.substr(i,j));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
    // you should actually read the stuff at the bottom
}
