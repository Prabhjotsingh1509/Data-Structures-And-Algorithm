/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int low=0;
    int high=numsSize-1;
    int *res= (int *)malloc(2*sizeof(int));
    *returnSize=2;
    res[0]=-1;
    res[1]=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target )
        {
            res[0]=mid;
            res[1]=mid;
            if(mid+1<numsSize && nums[mid+1]==target)
            {
                int j= mid+1;
                while(j<numsSize && nums[j]==target)
                {
                    res[1]=j;
                    j++;
                }
            }
            if(mid-1>= 0 && nums[mid-1] ==target )
            {
                int j= mid-1;
                while(j>=0 && nums[j]==target)
                {
                    res[0]=j;
                    j--;
                }
            }
            return res;
        }
        else if(nums[mid]>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return res;
}