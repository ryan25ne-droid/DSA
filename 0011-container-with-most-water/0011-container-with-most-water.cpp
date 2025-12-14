class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        
        int water=INT_MIN;

        int i=0;
        int j=n-1;
        

        while(i<j){
            int left=height[i];
            int right=height[j];
            int width=j-i;
            int tall=min(left,right);
            int amount=tall*width;
            water=max(water,amount);

            if (left<=right){
                i++;
            }
            else if(left>right){
                j--;
            }
        }
        return water;
    }    
};