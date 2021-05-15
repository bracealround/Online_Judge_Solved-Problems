#include <bits/stdc++.h>

using namespace std;

int n,m;
int in[111];
vector<int> adj[111];

void top()
{
  queue<int> q;
  for(int i = 1; i <= n; ++i){
    if(!in[i]){
      q.push(i);
    }
  }
  while(!q.empty()){
    int u = q.front();
    cout << u << " ";
    q.pop();
    for(int i = 0; i < adj[u].size(); ++i){
      in[adj[u][i]]--;
      if(in[adj[u][i]] == 0) q.push(adj[u][i]);
    }
  }
}

int main()
{
  while(cin >> n >> m){
    if(n == 0 and m == 0) break;
    for(int i = 0; i < m; ++i){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      in[b]++;
    }
    top();
    cout << endl;
    memset(in,0,sizeof in);
    for(int i = 1; i <= n; ++i){
      adj[i].clear();
    }
  }
}
