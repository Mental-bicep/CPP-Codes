#define umap unordered_map
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    
    if(find(edges[1].begin(),edges[1].end(),edges[0][0])!=edges[1].end()) 
        return edges[0][0];
        return edges[0][1];
    }
};
