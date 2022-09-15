#include <bits/stdc++.h>
 
using namespace std;
 
int a[2005];
 
vector<vector<int>> g(32);
bool vis[32];
 
void dfs(int p)
{
    if (vis[p]) return; vis[p]=1;
    for (auto it : g[p]) dfs(it);
}
 
bool connected(int n)
{
    int m=0;
    for (int i=0;i<n;i++) if (a[i]==0) return false;
    for (int i=0;i<n;i++) m|=a[i];
    for (int i=0;i<31;i++) g[i].clear();
    for (int i=0;i<n;i++)
    {
        int last=-1;
        for (int j=0;j<31;j++)
            if (a[i]&(1<<j)){
                if (last!=-1) g[last].push_back(j),g[j].push_back(last);
                last=j;
            }
    }
 
    for (int j=0;j<31;j++) vis[j]=0;
    for (int j=0;j<31;j++) if ((1<<j)&m)
    {
        dfs(j); break;
    }
    for (int j=0;j<31;j++) if (((1<<j)&m) && !vis[j]) return false;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
 
    int t; cin>>t;
    while (t--){
 
 
    int n; cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
 
    int ans=0;
    for (int i=0;i<n;i++) if (a[i]==0) ans++,a[i]++;
 
    int m=0;
    for (int i=0;i<n;i++) m=max(m,(a[i]&(-a[i])));
 
    if (connected(n))
    {
        cout<<ans<<"\n";
        for (int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
        goto kraj;
    }
 
    for (int i=0;i<n;i++)
    {
        a[i]--;
        if (connected(n))
        {
            cout<<ans+1<<"\n";
            for (int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
            goto kraj;
        }
        a[i]++;
    }
    
    for (int i=0;i<n;i++)
    {
        a[i]++;
        if (connected(n))
        {
            cout<<ans+1<<"\n";
            for (int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
            goto kraj;
        }
        a[i]--;
    }
 
    for (int i=0;i<n;i++) if ((a[i]&-a[i])==m)
    {
        a[i]--;
        break;
    }
    for (int i=0;i<n;i++) if ((a[i]&-a[i])==m)
    {
        a[i]++;
        break;
    }
 
    cout<<ans+2<<"\n";
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    
    kraj:;
    }
}
