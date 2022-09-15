#include <bits/stdc++.h>
using namespace std;

void dfs(int cur,vector<string> &S,vector<string> &T,int remain,string ans){
	
	if(remain<0)return;
	
	if(cur == S.size()){
		if(ans.size()>=3&&!binary_search(T.begin(),T.end(),ans)){
			cout<<ans<<endl;
			exit(0);
		}
		return;
	}
	
	if(ans.size()>0 && ans.back()!='_'){
		dfs(cur,S,T,remain,ans + "_");
	}
	else{
		dfs(cur+1,S,T,remain,ans + S[cur]);
		if(ans.size()>0)dfs(cur,S,T,remain-1,ans + "_");
	}
	
}

int main() {
    
	int N,M;
	cin>>N>>M;
	
	vector<string> S(N);
	for(int i=0;i<N;i++)cin>>S[i];
	sort(S.begin(),S.end());
	
	vector<string> T(M);
	for(int i=0;i<M;i++)cin>>T[i];
	sort(T.begin(),T.end());
	
	int remain = 16;
	for(int i=0;i<N;i++)remain -= S[i].size();
	remain -= N-1;	
	
	do{
		dfs(0,S,T,remain,"");
	}
	while(next_permutation(S.begin(),S.end()));
	
	cout<<-1<<endl;
	
	return 0;
}


