#include <bits/stdc++.h>
using namespace std;
class ZigZag {
  int n;
  vector<int> s;
  map<pair<int, int>, int> B;
  int best (int k, int dir)
  {
    pair<int, int> arg(k, dir);
    if (B.count(arg)!=0) return B[arg];
    if (k==0) return B[arg]=1;
    int sol=-1;
    for (int l=0; l<k; l++)
    if ((dir==1 && s[k]>s[l]) || (dir==-1 && s[k]<s[l]))
    {
      int tmp=best(l, -dir);
      if (tmp!=-1)
      {
        if (1+tmp>sol) sol=1+tmp;
      }
    }
    return B[arg]=sol;
  }
  public:
  int longestZigZag(vector <int> seq) {
    n=seq.size();
    s=seq;
    if (n==1) return 1;
    int sol=-1;
    for (int i=0; i<n; i++)
    for (int j=-1; j<=1; j+=2)
    {
      int tmp=best(i, j);
      if (tmp>sol) sol=tmp;
    }
    return sol;
  }
};
int main(){
    int input,ans;
  vector<int> V;
  cout << "Enter numbers of sequence" << endl;
  while(cin >> input)//Enter a non integer to end the loop
  V.push_back(input);
  ZigZag z;
  ans=z.longestZigZag(V);
  cout<<ans<<endl;
  return 0;
}
