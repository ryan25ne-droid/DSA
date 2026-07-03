class Solution {
public:
    string addBinary(string a, string b){
        string ans="";
        int i= a.size()-1, j=b.size()-1, carry=0;

        while(i>=0 || j>=0 || carry==1){
            int sum=carry;
            if(i>=0){
                sum+= (a[i--] -'0');
            }
            if(j>=0){
                sum+= (b[j--] -'0');
            }
            ans+= ((sum & 1)+'0');   //sum%2
            carry = sum >>1;    //sum/2
        }

        reverse(ans.begin(), ans.end());
        return ans;        
    }
};