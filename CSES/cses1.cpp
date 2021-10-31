#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ll long long
 
int main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);

   int n;
   cin>>n;
   vector<pair<pair<int,int>,int>> v;
   vector<pair<pair<int,int>,int>> v1;
   for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v.push_back(mp(mp(a,b),i));
    v1.push_back(mp(mp(b,a),i));
   }
   
   sort(v.begin(),v.end());
   sort(v1.begin(),v1.end());
   map<pair<int,int>,queue<int>> map1;
   map1[v[0].first].push(1);
 
   vector<int> ans(n);
   ans[v[0].second]=1;
   int count=1;
   
   for(int i=1,j=0;i<v.size();i++){
        if(v[i].first.first>v1[j].first.first){
            int k=map1[mp(v1[j].first.second,v1[j].first.first)].front();
            map1[mp(v1[j].first.second,v1[j].first.first)].pop();
            
            map1[v[i].first].push(k);
            ans[v[i].second]=k;
            j++;
        }
        else
        {   count++;
            map1[v[i].first].push(count);
            ans[v[i].second]=count;
        }
   }
   
cout<<count<<endl;
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
 
cout<<endl;
 
   
}