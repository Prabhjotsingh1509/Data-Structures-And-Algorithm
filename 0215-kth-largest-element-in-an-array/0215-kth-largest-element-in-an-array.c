void merge(int * arr,int low,int mid,int high)
{
    int *temp = (int *)malloc((high - low + 1)* sizeof(int));
    int k = 0;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[k++];
    }
}
void mergesort(int *nums,int low,int high)
{
    if(low<high)
    {
        int mid= (high+low)/2;

        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}



int findKthLargest(int* nums, int numsSize, int k) {
    
    mergesort(nums,0,numsSize-1);

    return nums[numsSize-k];
}