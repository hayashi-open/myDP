/*
編集距離
https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E
*/

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define INSERT_COST 1
#define DELETE_COST 1
#define CHANGE_COST 1

int main(){
  string S,T;
  cin>>S>>T;
  int sl = S.size();
  int tl = T.size();

  vvi dp(sl+1, vi(tl+1));

  for(int i=0; i<=sl; i++)dp[i][0] = i*INSERT_COST;
  for(int j=0; j<=tl; j++)dp[0][j] = j*INSERT_COST;

  for(int i=1; i<=sl; i++){
    for(int j=1; j<=tl; j++){
      int D = dp[i-1][j] + DELETE_COST;
      int I = dp[i][j-1] + INSERT_COST;
      int C = dp[i-1][j-1] + (S[i-1]==T[j-1]? 0: CHANGE_COST);

      dp[i][j] = min({D,I,C});
    }
  }

  /*
  for(vi x: dp){
    for(int y: x){
      cout<<y<<",";
    }
    cout<<endl;
  }//*/

  int ans = dp[sl][tl];

  cout<<ans<<endl;
}
