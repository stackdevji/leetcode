//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 请找出其中最小的元素。 
//
// 注意数组中可能存在重复的元素。 
//
// 示例 1： 
//
// 输入: [1,3,5]
//输出: 1 
//
// 示例 2： 
//
// 输入: [2,2,2,0,1]
//输出: 0 
//
// 说明： 
//
// 
// 这道题是 寻找旋转排序数组中的最小值 的延伸题目。 
// 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
// 答：会影响，当nums[start] = nums[mid] = nums[end] 没有办法区分中间值落在哪个半区 所以需要顺序查找 复杂度从o(logN)到o(N)
// 
// Related Topics 数组 二分查找



//leetcode submit region begin(Prohibit modification and deletion)

// 遍历查最小的数
int ergodicFindMin(int *nums, int numsSize) {
    if (!nums || numsSize <= 0) return -1;

    int min = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int findMin(int* nums, int numsSize){
    if (!nums || numsSize <= 0) return -1;

    int start = 0;
    int end = numsSize - 1;
    int midIndex = start; // 数组本身也是个旋转数组，第一个值就是最小的值，直接返回 所以midIndex初始化0
    while (numsSize > 1 && nums[start] >= nums[end]) { // 前半部分的值一定比后边的大 条件不包含 = 当数组只有一个值 [1]这个值就是最小值
        if (end == start + 1) {
            midIndex = end;
            break;
        }

        midIndex = (start + end) / 2;
        if (nums[start] == nums[midIndex] && nums[end] == nums[midIndex]) { // 无法判断中间数落在哪个区间只能顺序查找
            return ergodicFindMin(nums, numsSize);
        }
        if (nums[midIndex] >= nums[start]) start = midIndex;
        else if (nums[midIndex] <= nums[end]) end = midIndex;
    }
    return nums[midIndex];
}


//leetcode submit region end(Prohibit modification and deletion)
