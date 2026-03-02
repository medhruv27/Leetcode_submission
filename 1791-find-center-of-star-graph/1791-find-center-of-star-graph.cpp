class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int first1= edges[0][0],first2=edges[0][1],second1=edges[1][0],second2=edges[1][1];

    if(first1==second1 || first1==second2)
    return first1;
    else
    return first2;
    }
};