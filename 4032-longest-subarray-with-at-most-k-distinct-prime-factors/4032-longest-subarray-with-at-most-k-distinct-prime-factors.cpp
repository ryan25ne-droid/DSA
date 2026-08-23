#define ll long long

class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int k){
        int const maxVal= 1e5;

        vector<bool> prime(maxVal +1, true);
        prime[0]= prime[1]= false;

        for(int i=2; (ll) i*i <=maxVal; i++){
            if(prime[i]){
                for(ll j= (ll) i*i; j<= maxVal; j+=i){
                    prime[j]= false;
                }
            }
        }

        vector<vector<int>> primeFactors(maxVal+1);

        for(auto& ele: nums){
            vector<int> res;

            int temp= ele;

            for(int i=2; (ll)i* i<= ele; i++){
                if(prime[i] && temp % i==0){
                    res.push_back(i);
                    while(temp% i==0){
                        temp= temp/i;  // subtract until all factors of i in temp are deleted
                    }
                }
            }
            if(temp> 1 && prime[temp]){
                res.push_back(temp);
            }
            
            primeFactors[ele]= res;
        }
        
        int n= nums.size();
        int count=0;
        int left=0;
        int right= 0;
        int maxLen= INT_MIN;
        unordered_map<int, int> mpp; //stores prime factor, no of elements having that as a factor

        while(right< n){
            vector<int> rightFactors= primeFactors[nums[right]];
            for(auto& p: rightFactors){
                if(mpp[p]==0){
                    count++;
                }
                mpp[p]++;
            }
            while (count>k){
                vector<int> leftFactors= primeFactors[nums[left]];
                for(auto& p: leftFactors){
                    mpp[p]--;
                    if(mpp[p]==0){
                        count--;
                    }
                }
                left++;
            }
            
            maxLen= max(maxLen, right- left+1);                    
            right++;
        }

        return maxLen;        
    }
};

