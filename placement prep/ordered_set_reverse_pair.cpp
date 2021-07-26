#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
  
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set s;
        int n=nums.size();
        s.insert(nums[n-1]);
        int ans=0;
        for(int i=n-2;i>=0;i--)
        {
            int temp=ceil((float)nums[i]/2);
            ans+=s.order_of_key(temp);
            s.insert(nums[i]);
        }
        return ans;
    }
};