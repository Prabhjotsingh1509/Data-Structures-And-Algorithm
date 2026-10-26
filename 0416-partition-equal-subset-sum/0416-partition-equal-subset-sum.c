bool canPartition(int* nums, int numsSize) {
    int totalSum=0;
    for(int i=0;i<numsSize;i++)
    {
        totalSum+=nums[i];
    }
    if(totalSum%2!=0)
    {
        return false;
    }
    int targetSum= totalSum/2;
    int dp[targetSum+1];
    for(int i=0;i<=targetSum;i++)
    {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<numsSize;i++)
    {
        int num = nums[i];
        for(int j= targetSum;j>=num;j--)
        {
            if(dp[j-num]==1)
            {
                dp[j]=1;
            }
        }
    }
    if(dp[targetSum]==1)
    {
        return true;
    }
    else{
        return false;
    }
}