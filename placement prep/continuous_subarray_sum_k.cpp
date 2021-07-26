class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            m[sum]++;
        }
        int count=0;
        int val=0;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                m[val+nums[i]]--;
            }
            if(nums[i]==k)
            {
                count++;
            }
            count+=m[k+val];
            val+=nums[i];
        }
        return count;
    }
};