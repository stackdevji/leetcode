//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。 
//
// 示例 1: 
//
// 输入: [1,2,3,4,5,6,7] 和 k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]
// 
//
// 示例 2: 
//
// 输入: [-1,-100,3,99] 和 k = 2
//输出: [3,99,-1,-100]
//解释: 
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100] 
//
// 说明: 
//
// 
// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。 
// 要求使用空间复杂度为 O(1) 的 原地 算法。
//
// Related Topics 数组



//leetcode submit region begin(Prohibit modification and deletion)

// 1. 暴力解法 时间复杂度o(n^2)
//void rotate(int* nums, int numsSize, int k){
//    if (!nums || numsSize <= 0 || k <= 0) return;
//    for (int i = 1; i <= k; ++i) {
//        int j = numsSize - 1;
//        int tmp = nums[j];
//        for( ; j > 0; j--) nums[j] = nums[j-1];
//        nums[j] = tmp;
//    }
//}

// 通过反转数组来实现
void reverseArr(int *nums , int start, int end) {
    if (!nums || start < 0 || end < 0) return;
    while (start < end) { // start == end 或者 start > end 循环结束
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        ++start;
        --end;
    }
}

// 需要注意数组的长度和k的值
// 如果k < numSize 反转3次
// 如果k >= numSize 反转0次或者1次
// 例如：[1, 2, 3]
// k = 0   [1, 2, 3]
// k = 1   [3, 1, 2]
// k = 2   [2, 3, 1]
// k = 3   [1, 2, 3] 个数相同时数组旋转为原数组从头再来
// k = 4   [3, 1, 2] 和k = 1 一样，如此下去
// 结论 非0 k = k % numSize
void rotate(int* nums, int numsSize, int k){
    if (!nums || numsSize <= 0 || k <= 0) return;
    k = k % numsSize;
    if (k == 0) return;

    // 反转整个数组
    int start = 0;
    int end = numsSize - 1;
    reverseArr(nums, start, end);

    // 如果k >= numSize 直接反转数组就好
    // 如果k < numSize 反转数组之后需要分别反转前k个数 和后 n-k个数
    if (k < numsSize) {
        // 反转前k个数
        int frontPartEnd = start + k - 1;
        reverseArr(nums, start, frontPartEnd);

        // 反转后n-k个数
        int tailPartStart = start + k;
        reverseArr(nums, tailPartStart, end);
    }
}


//leetcode submit region end(Prohibit modification and deletion)
