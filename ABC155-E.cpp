/*
https://atcoder.jp/contests/abc155/tasks/abc155_e
桁DP
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
  string N;
  cin>>N;
  int keta = N.size();
  
  int dp[keta+1][2];
  dp[0][0] = 0;
  dp[0][1] = 1;

  for(int i=1; i<=keta; i++){
    N[i-1] -= '0';
    //charからintに変換

    dp[i][0] = min(
      dp[i-1][0] + N[i-1],
      dp[i-1][1] + (10 - N[i-1])
    );

    dp[i][1] = min(
      dp[i-1][0] + (N[i-1]+1),
      dp[i-1][1] + (10 - (N[i-1]+1))
    );
  }

  cout<<dp[keta][0]<<endl;
  
}
