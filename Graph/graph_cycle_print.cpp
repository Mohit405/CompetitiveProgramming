    #include<bits/stdc++.h>
    using namespace std;
    #define endl "\n"
    #define mp make_pair
    #define ll long long
long long gcd(long long a,long long b){
    if(b==0)
        return a;

    long long hcf=gcd(b,a%b);
    return hcf;
}
int n=1e5+10;
map<int,vector<int>> map1;
vector<int>  visited(n,0);
vector<int> parent(n,-1);
void dfs(int node,int par){
  visited[node]=1;
  parent[node]=par;

  for(auto it:map1[node]){
    if(!visited[it])
      dfs(it,node);
    else{
      if(it!=par){
        vector<int> ans;
        ans.push_back(node);
        int cur=node;
        while(parent[cur]!=it){
          cur=parent[cur];
          ans.push_back(cur);
        }
        ans.push_back(it);
        ans.push_back(node);
        cout<<ans.size()<<endl;
        for(auto it:ans)cout<<it<<" ";
          cout<<endl;
        exit(0);
      }
    }
  }
}
void solve(){

  for(auto it:map1){
    if(!visited[it.first])
      dfs(it.first,-1);
  }
  cout<<"IMPOSSIBLE"<<endl;
}
int main(){
      ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      map1[a].push_back(b);
      map1[b].push_back(a);
    }
    solve();
}