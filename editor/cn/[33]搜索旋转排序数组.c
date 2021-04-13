//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 
//
// 你可以假设数组中不存在重复的元素。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 示例 1: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
// 
//
// 示例 2: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1 
// Related Topics 数组 二分查找

// 思想
// 如果数组的长度是1 在判断数组当前值与target
// 如果数组第一个数 不大于数组的最后一个数 说明该旋转数组是数组本身 直接走二分查找
// 如果第一个数 大于 最后一个数 说明数组经过旋转 成为两个有序的区间
// 如果target > 数组的第一个数 说明target 在左侧排序区间 则剔除右侧区间
// 如果target < 数组的最后数，说明tart 在右侧排序区间 则剔除左侧区间

//leetcode submit region begin(Prohibit modification and deletion)

int midFind(int *nums, int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid] ) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    if (!nums || numsSize <= 0) return -1;
    int start = 0;
    int end = numsSize - 1;
    // nums[start] <= nums[end] 直接二分查找
    if (nums[start] <= nums[end]) return midFind(nums, start, end, target);

    // 含有两个子排序区间的旋转数组
    if (target > nums[start]) { // 目标值在左半排序区间 剔除右边区
        while (nums[start] > nums[end]) --end;
        return midFind(nums, start, end, target);
    } else if (target < nums[start]) {
        while (nums[start] > nums[end]) ++start; // 目标值在右半排序区间 剔除左边区
        return midFind(nums, start, end, target);
    } else return start;
}


//leetcode submit region end(Prohibit modification and deletion)

// 还有一种思想就是找到旋转数组最小值的索引  两次二分查找
// 如果索引 = 0 start = 0
// 如果索引 != 0 就要看target 和 nums[start] 值的大小比较关系
