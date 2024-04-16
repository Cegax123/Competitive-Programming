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



int parent[maxq];
int sz[maxq];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
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
        
        auto chi = [&](int x)->string{
            string ret = "";
            for(int i=0;i<n;i++){
                ret += char('0'+(x%10));
                x /= 10;
            }
            reverse(ret.begin(),ret.end());
            return ret;
        };
        
        auto ch = [&](string cd)->int{
            int ret = 0;
            for(int i=0;i<n;i++)
                ret += (cd[i]-'0') * pot[n-1-i];
            return ret;
        };

        for(int i = 0; i < pot[n]; i++)
            make_set(i);

        vector<int>vis(maxq,0);////////////////////optimization//////
        vector<int>valid(pot[n],0);
        
        for(int i=1;i<(mod+5);i++){
            vis[ini] = 1;

            string init = chi(ini%pot[n]);
            valid[ini%pot[n]] = 1;

             for(int i=0;i<n;i++){
                string tmp1 = init.substr(0,i) + nxt(init[i]) + init.substr(i+1,(n-1)-i);
                string tmp2 = init.substr(0,i) + pre(init[i]) + init.substr(i+1,(n-1)-i);
                
                int t1 = ch(tmp1);
                int t2 = ch(tmp2);
                
                if(valid[t1] or t1 == target or t1 == 0) union_sets(t1, ini%pot[n]);
                if(valid[t2] or t2 == target or t2 == 0) union_sets(t2, ini%pot[n]);
            }

            ini = f(ini);
            if(vis[ini] or find_set(0) == find_set(target)) break;
        }
        
        valid[target] = 1;
        
        string cd = "";
        for(int i=0;i<n;i++) cd += '0';
        
        
        queue<int>q;
        vector<int>dp(pot[n],0);
        vector<int>visit(pot[n],0);
        vector<int>deep(pot[n]);
        
        //for(int i=0;i<=mod;i++)
            //if(valid[i])
                //cout<<i<<" ";
        
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
            //cout<<e<<" "<<dp[e]<<endl;
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
