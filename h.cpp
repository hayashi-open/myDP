#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
#define INF 1<<29 //使いやすい無限

#define debug(x) cout<<#x<<" = "<<(x)<<endl

int main(){
  int N,L;cin>>N>>L;

  vb isHurdle(L, false);
  for(int i=0; i<N; i++){
    int x;cin>>x;
    isHurdle[x] = true;
  }

  int t1, t2, t3;
  cin>>t1>>t2>>t3;

  vi dp(L, INF); //座標iにくるまでの最短Lの手前まで見ておく
  dp[0] = 0;

  for(int i=1; i<L; i++){
    int a = dp[i-1] + (isHurdle[i]? t1+t3 : t1);
    if(i==1){
      dp[i] = a;
      debug(dp[i]);
      continue;
    }

    int b = dp[i-2] + (isHurdle[i]? t1+t2+t3 : t1+t2);
    if(i<4){
      dp[i] = min(a, b);
      debug(dp[i]);
      continue;
    }

    int c = dp[i-4] + (isHurdle[i]? t1+(t2*3)+t3 : t1+(t2*3));
    dp[i] = min({a,b,c});
    debug(dp[i]);
  }

  int ans = min({
    dp[L-1] + t1, //1つ前から普通にくる
    dp[L-2] + t1+t2, //2つ前から飛んで着地
    dp[L-4] + t1+(t2*3), //4つ前から飛んで着地
    //ジャンプ中通過
    dp[L-1] + t1/2 + t2/2, //1つ前からジャンプ中
    dp[L-2] + t1/2 + t2/2*3, //2つ前からジャンプ中
    dp[L-3] + t1/2 + t2/2*5 //3つ前からジャンプ中
  });

  cout<<ans<<endl;
}