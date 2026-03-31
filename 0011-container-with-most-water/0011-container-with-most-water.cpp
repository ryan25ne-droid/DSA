auto fast_io=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        int start=0;
        int end=height.size()-1;
        while(start<end){
            int area= min(height[start],height[end])*(end-start);
            maxArea=max(maxArea,area);
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxArea;        
    }
};