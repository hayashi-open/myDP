#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LIMIT 1'000'000'007 //10^9+7

int main(){
  int N,M;cin>>N>>M;
  vector<ll>dp(N+1, -1);
  for(int i=0; i<M; i++){
    int a;cin>>a;
    dp[a] = 0;
  }
  dp[0] = 1;
  for(int i=1; i<=N; i++){
    if(dp[i]==0)continue;
    else if(i>=2){
      dp[i] = dp[i-1] + dp[i-2];
    }if(i==1){
      dp[i] = dp[i-1];
    }
    dp[i]%=LIMIT;
  }

  cout<<dp[N]<<endl;
}