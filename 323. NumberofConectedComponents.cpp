//union-find, merge-find, disjoint-set

class Solution {
    vector<int> id; //x.parent
    void makeSet(int n)
    {
        for (int i = 0; i<n; i++)
            id.push_back(i);
    }
    
    int find(int x)
    {
        if (x == id[x]) return x;
        else return find(id[x]);
    }
    
    void unions(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        id[xRoot] = yRoot;
    }
    
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ret = n;
        makeSet(n);
        for (auto edge : edges)
        {
            int x = find(edge.first);
            int y = find(edge.second);
            if(x != y) 
            {
                unions(x,y);
                ret--;
            }
        }
        return ret;
    }
};
