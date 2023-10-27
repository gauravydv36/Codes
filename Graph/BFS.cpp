#include<bits/stdc++.h>
using namespace std;
void bfs(int node,vector<int> &ans,map<int,bool> &vis,map<int,set<int>> &mp){
    queue<int> q;
    vis[node]=true;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:mp[front]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}
void bfsTraversal(int n, vector<vector<int>> &adj){
 map<int,bool> vis;
 map<int,set<int>> mp;
 vector<int> ans;
 for(int i=0;i<adj.size();i++){
     mp[adj[i][0]].insert(adj[i][1]);
     mp[adj[i][1]].insert(adj[i][0]);
 }
 for(int i=0;i<n;i++){
     if(!vis[i]){
         bfs(i,ans,vis,mp);
     }
 }
 for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<' ';
    }
//  return ans;
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>> adj(m,vector<int>(2));
for(int i=0;i<m;i++){
  cin>>adj[i][0]>>adj[i][1];
}
bfsTraversal(n,adj);
}
