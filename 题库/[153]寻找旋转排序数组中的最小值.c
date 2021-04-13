//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 请找出其中最小的元素。 
//
// 你可以假设数组中不存在重复元素。 
//
// 示例 1: 
//
// 输入: [3,4,5,1,2]
//输出: 1 
//
// 示例 2: 
//
// 输入: [4,5,6,7,0,1,2]
//输出: 0 
// Related Topics 数组 二分查找

// 思想：
// 严格升序排序的旋转数组被最小值分为两个有序的子数组 前半部分的有序数组和后半部分的有序数组
// 并且数组的第一个元素 > 数组的最后一个元素
// 双指针方式 第一个指针指向第一个元素 第二个指针指向第二个元素
// 采用二分查找思想 判断中间数落在前半部分区间还是后半部分
// 如果中间数 > nums[start] 说明中间数在前半个区间 那么最小值在中间数的后半部分 start = mid 缩小查找范围
// 如果中间数 < nums[end] 说明中间数在后半个区间 最小值在中间值左侧，end = mid 缩小查找范围
// 知道start=前半部分最后一个值 end=后半部分第一个值 也就是 end = start + 1的时候 end指针指向的元素就是最小值


//leetcode submit region begin(Prohibit modification and deletion)


int findMin(int* nums, int numsSize){
    if (!nums || numsSize <= 0) return -1;

    int start = 0;
    int end = numsSize - 1;
    int midIndex = start; // 数组本身也是个旋转数组，第一个值就是最小的值，直接返回 所以midIndex初始化0
    while (nums[start] > nums[end]) { // 前半部分的值一定比后边的大 条件不包含 = 当数组只有一个值 [1]这个值就是最小值
        if (end == start + 1) {
            midIndex = end;
            break;
        }

        midIndex = (start + end) / 2;
        if (nums[midIndex] >= nums[start]) start = midIndex;
        else if (nums[midIndex] <= nums[end]) end = midIndex;
    }
    return nums[midIndex];
}


//leetcode submit region end(Prohibit modification and deletion)
