int removeDuplicates(int* nums, int numsSize) {
    int i=0,j=i+1;

    while(j<numsSize)
    {
        if(nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            nums[i+1]=nums[j];
            i++;
            j++;
        }
    }
    return i+1;
}