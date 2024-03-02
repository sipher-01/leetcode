class Solution {
public:
bool DFS(int i, vector<vector<int>> &edges, int n, vector<int> &visi, int color){
 visi[i] = color;
 for(auto it : edges[i]){
	 if(visi[it]==-1 ){
 			if (color == 0 && !DFS(it, edges, n, visi, 1)) {
                return false;
            } else if (color == 1 && !DFS(it, edges, n, visi, 0)) {
                return false;
            }
	 }
	 else if(visi[it]!=-1 && visi[it]==color){
		 return false;
	 }
 }
 return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
	vector<int>visi(n,-1);

	for(int i=0 ;i<n; i++){
			if(visi[i]==-1){
				if(!DFS(i,graph,n,visi,0))return false;
			}
	}
	return true;
    }
};