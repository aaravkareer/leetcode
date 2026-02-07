double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {


    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int low = 0;
    int high = nums1Size;

    while (low <= high)
    {
        int i = (low + high) / 2;
        int j = (nums1Size + nums2Size + 1) / 2 - i;

        int left1  = (i == 0) ? -1000001 : nums1[i-1];
        int right1 = (i == nums1Size) ? 1000001 : nums1[i];

        int left2  = (j == 0) ? -1000001 : nums2[j-1];
        int right2 = (j == nums2Size) ? 1000001 : nums2[j];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((nums1Size + nums2Size) % 2 == 0)
            {
                int leftMax  = left1 > left2 ? left1 : left2;
                int rightMin = right1 < right2 ? right1 : right2;
                return (leftMax + rightMin) / 2.0;
            }
            else
            {
                return (left1 > left2 ? left1 : left2);
            }
        }
        else if (left1 > right2)
            high = i - 1;
        else
            low = i + 1;
    }

    return 0.0;


}