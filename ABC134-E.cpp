/* https://atcoder.jp/contests/abc134/tasks/abc134_e */

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define debugv(v) do{for(auto x:(v)) cout<<x<<","; cout<<endl;}while(0)

int main(){
  int N;
  cin>>N;

  vi dp; //i番目の色で塗っている数字の最大値

  int x;
  for(int i=0; i<N; i++){
    cin>>x;
    auto itr = upper_bound(all(dp), x, [](int a, int b){
      return a > b;
    });
    if(itr!=dp.end()){
      *itr = x;
    }else{
      dp.pb(x);
    }
    //debug(dp.size());
    //debugv(dp);
  }

  cout<<dp.size()<<endl;
}
