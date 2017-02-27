#include <bits/stdc++.h>
int num;
using namespace std;
int calculate(int value,vector<int>&kar)
{ vector<int>calc;
   int ans=1;
   vector<int>::iterator temp;
   calc.push_back(kar[value]);
 for(int i=value+1;i<value+num;i++)
   { if(kar[i]<calc[0])
      calc[0]=kar[value];
      else if(kar[i]>calc[calc.size()-1])
      { ans++;
        calc.push_back(kar[i]);
      }
       else{ temp=upper_bound(calc.begin(),calc.end(),kar[i]);
              *temp=kar[i];
       }
   }
   return ans;
}
int main()
{ int t;
  cin>>t;

  while(t--)
  {
    cin>>num;
    int aud=0;
    vector<int>kar(2*num);
    vector<pair<int,int> >temp1(num);
    for(int i=0;i<num;i++)
    {
      cin>>kar[i];
      kar[i+num]=kar[i];
      temp1[i].first=kar[i];
      temp1[i].second=i;
    }
    sort(temp1.begin(),temp1.end());
    for(int i=0;i<min(37,num);i++)
        aud=max(aud,calculate(temp1[i].second,kar));
        cout<<aud<<endl;
  }
}
