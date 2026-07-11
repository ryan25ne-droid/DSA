class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        int n=nums.size();
        vector<int>ans;
        vector<int> B1;
        vector<int> B2;
        long long xOR=0;
        for(int i=0;i<n;i++){
            xOR =xOR^nums[i];            
        } 
        //xOR contains ^ or the distinct no
        xOR= xOR & ~(xOR-1LL); 
        //this extracts the smallest bit which is different in both the no

        for(int i=0;i<n;i++){
            if((nums[i] & xOR)==0){
                B1.push_back(nums[i]);
            }
            else{
                B2.push_back(nums[i]);
            }
        }
        int a=0, b=0;
        for(int i=0;i<B1.size();i++){
            a= a^B1[i];
        }
        for(int i=0;i<B2.size();i++){
            b= b^B2[i];
        }
        ans.push_back(a);
        ans.push_back(b);

        return ans;               
    }
};