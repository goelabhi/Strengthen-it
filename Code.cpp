vector<vector<int>> g;
vector<bool> vis;
vector<int> comp;
void dfs(int v){
    vis[v] = true;
    comp.push_back(v);
    for(auto i : g[v]){
        if(!vis[i]) dfs(i);
    }
}
int Solution::solve(int A, vector<vector<int> > &B, int C) {
     g = vector<vector<int>>(A);
    vis = vector<bool> (A,false);
    vector<int> comps;
    for(int i=0;i<B.size();i++){
        g[B[i][0]-1].push_back(B[i][1]-1);
        g[B[i][1]-1].push_back(B[i][0]-1);
    }    
    for(int i=0;i<A;i++){
     if(!vis[i]){
         comp = vector<int>();
         dfs(i);
         int cnt = 0;
         for(int j=0;j<comp.size();j++){
             cnt += g[comp[j]].size();
         }
         assert(cnt%2 == 0);
         comps.push_back(cnt/2);
     }   
    }
    sort(comps.rbegin(),comps.rend());
    if(comps.size()-1 <= C) return B.size() + C;
    
    int ans = 0;
    for(int i=0; i<C+1; i++)    ans += comps[i];
    
    ans += C;
    
    return ans;
}
