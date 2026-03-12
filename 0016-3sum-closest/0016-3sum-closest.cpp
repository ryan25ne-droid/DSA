class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        //for closest use absolute function. Written as abs().

        int n=nums.size();
        int diff=INT_MAX;
        int sum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){ //since I need 3 elements, I only go till n-2. Because it's not possible to have 3 elements distinct after that considering the bound of start and end.
            int start=i+1;
            int end=n-1;
       //Problem gurantees unique solution. So I am not bothered to check nums[i]==nums[i-1]. But I still do because in case of repeated elements, it saves me a ton of iterations and is a way to improve optimization.
           if(i>0 &&nums[i]==nums[i-1]){
               continue;
           }   
            
            while(start<end){
                int currsum=nums[i]+nums[start]+nums[end];
                if(currsum==target){
                    return currsum; //there won't be any other solutions
                }
                int curr=abs(target-currsum);
                if(curr<diff){
                    diff=curr;
                    sum=currsum;
                }
                if(target<currsum){
                    end--;
                    while(start<end && nums[end]==nums[end+1]){
                        end--;
                    }
                }
                else if(target>currsum){
                    start++;
                    while(start<end && nums[start]==nums[start-1]){
                        start++;
                    }
                }
                    //I am not bothered with duplicates at start and end because the question says there is a unique solution. But I still check nums[start]=nums[start-1] & nums[end]=nums[end+1] because it optimizes and skips redundant iterations.
            }
        } 
        return sum;
    }
};