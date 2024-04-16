#include <bits/stdc++.h>

using namespace std;

const int pt = 7;
const int maxq = 1e7+1;
const int modd = 1e9 + 9;
int pot[pt];

char nxt(char c){
    if(c<'9') return char(c+1);
    else return '0';
}
char pre(char c){
    if(c>'0') return char(c-1);
    else return '9';
}



int main() {
    pot[0] = 1;
    for(int i=1;i<pt;i++)
        pot[i] = pot[i-1] * 10;
        
    int t;
    cin>>t;
    while(t--){
        
        int n,target,ini,a,b,mod;
        cin>>n>>target>>ini>>a>>b>>mod;
        
        auto f = [&](int pre) -> int{
            return (1ll*a*pre + b) %mod;
        };
        
        vector<int>vis(maxq,0);////////////////////optimization//////
        vector<int>valid(pot[n],0);
        
        for(int i=1;i<(mod+5);i++){
            vis[ini] = 1;
            valid[ini%pot[n]] = 1;
            cout<<ini<<" ";
            ini = f(ini);
            if(vis[ini]) break;
        }
        cout<<endl;
        valid[target] = 1;
        
        string cd = "";
        for(int i=0;i<n;i++) cd += '0';
        
        auto ch = [&](string cd)->int{
            int ret = 0;
            for(int i=0;i<n;i++)
                ret += (cd[i]-'0') * pot[n-1-i];
            return ret;
        };
        auto chi = [&](int x)->string{
            string ret = "";
            for(int i=0;i<n;i++){
                ret += char('0'+(x%10));
                x /= 10;
            }
            reverse(ret.begin(),ret.end());
            return ret;
        };
        
        queue<int>q;
        vector<int>dp(pot[n],0);
        vector<int>visit(pot[n],0);
        vector<int>deep(pot[n]);
        
        for(int i=0;i<=mod;i++)
            if(valid[i])
                cout<<i<<" ";
        
        q.push(0);
        dp[0] = 1;
        deep[0] = 0;
        visit[0] = 1;
        
        int ok =0;
        
        auto trans = [&](int x, int y){
            
            if(valid[y]){
                
                if(visit[y] and deep[y] == deep[x] + 1){
                    dp[y] += dp[x];
                    dp[y] %= modd;
                }
                

                if(!visit[y]){
                    visit[y] = 1;
                    dp[y] += dp[x];
                    dp[y] %= modd;
                    deep[y] = deep[x] + 1;
                    q.push(y);
                }
            }
            if(y == target) {
                ok = 1;
            }
        };
        
        while(!q.empty()){
            auto e = q.front();
            cout<<e<<" "<<dp[e]<<endl;
            q.pop();
            
            string cur = chi(e);
            
            for(int i=0;i<n;i++){
                string tmp1 = cur.substr(0,i) + nxt(cur[i]) + cur.substr(i+1,(n-1)-i);
                string tmp2 = cur.substr(0,i) + pre(cur[i]) + cur.substr(i+1,(n-1)-i);
                
                int t1 = ch(tmp1);
                int t2 = ch(tmp2);
                
                trans(e,t1);
                if(ok) break;
                trans(e,t2);
                if(ok) break;
            }
            if(ok)break;
        }
        if(visit[target]){
            cout<<deep[target]<<" "<<dp[target]<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}
