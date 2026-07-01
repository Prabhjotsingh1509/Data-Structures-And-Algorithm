int findPeakElement(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // If the next element is greater, the peak is on the right side
        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1;
        } 
        // Otherwise, the peak is either at 'mid' or to the left
        else {
            high = mid;
        }
    }
    
    // 'low' and 'high' will converge to the peak element index
    return low;
}