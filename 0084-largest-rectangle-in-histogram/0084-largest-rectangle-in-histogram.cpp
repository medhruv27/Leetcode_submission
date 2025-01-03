class Solution {
public:
    vector<int> nsl(vector<int>&heights,int n){
        vector<int>sl;
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                sl.push_back(-1);
            }else if( !s.empty() && s.top().first<heights[i]){
                sl.push_back(s.top().second);
            }else{
                while(!s.empty() && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    sl.push_back(-1);
                }
                else{
                sl.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        return sl;
    }
    vector<int> nsr(vector<int>&heights,int n){
        vector<int>sr;
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                sr.push_back(n);
            }else if( !s.empty() && s.top().first<heights[i]){
                sr.push_back(s.top().second);
            }else{
                while(!s.empty() && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    sr.push_back(n);
                }
                else{
                sr.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(sr.begin(), sr.end());
        return sr;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>sr = nsr(heights,n);
        vector<int>sl = nsl(heights,n);
        int maxarea = 0;
        for(int i=0;i<n;i++){
            maxarea = max((sr[i]-sl[i]-1)*heights[i],maxarea);
        }
        return maxarea;
    }
};