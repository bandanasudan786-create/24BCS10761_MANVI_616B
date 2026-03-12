class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int v:nums)
        {
            sum+=v;
        }

        int want=sum-x;
        if(want<0)
        {
            return -1;
        }
        if(want==0)
        {
            return n;
        }

        int l=0;
        int sum1=0;
        int len=-1;

       for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
            while(sum1>want)
            {
                sum1 -=nums[l];
                l++;
            }

            if(sum1==want)
            {
                len=max(len,i-l+1);
            }
        }
        if(len==-1)
        {
            return -1;
        }
        return n-len;

    }
};