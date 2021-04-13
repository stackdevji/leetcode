//给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。 
//
// 示例 1: 
//
// 输入: [1,3,4,2,2]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [3,1,3,4,2]
//输出: 3
// 
//
// 说明： 
//
// 
// 不能更改原数组（假设数组是只读的）。 
// 只能使用额外的 O(1) 的空间。 
// 时间复杂度小于 O(n2) 。 
// 数组中只有一个重复的数字，但它可能不止重复出现一次。 
// 
// Related Topics 数组 双指针 二分查找

// 相似题： 给定长度为n数字范围（0-n-1），如果存在重复数，请找出这个重复数
// 1. 需要交换数组 a[i] == i(下标)
// 2. 如果不相等，m = a[i] 比较a[i]和a[m]是否相等，相等则说明重复，不相等让交换 让a[m]回到本来属于他的位置下标m
// 继续比较当前下标i a[i] == i(下标) 重复1，2步骤


// 思想：
// 长度为n+1的数组 数字范围为1-n 如果没有重复的数字，那么数字的个数为n 长度为n+1说明一定有重复的数字出现
// 可以利用二分查找思想，将1-n的数字范围一分为二 [1,m] [m+1,n]
// 如果[1,m]范围中的数字出现的个数为m说明没有重复数字，重复的数字出现在另一半区间
// 二分查找思想在另一半区间中继续查找


//leetcode submit region begin(Prohibit modification and deletion)

/**
 * 计算[start,end]闭区间的数字出现的次数
 * @param nums
 * @param numsSize
 * @param start
 * @param end
 * @return
 */
int getCountRange(int* nums, int numsSize, int start, int end) {
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] >= start && nums[i] <= end) {
            count++;
        }
    }
    return count;
}

/**
 * 寻找重复数
 * @param nums
 * @param numsSize
 * @return
 */
int findDuplicate(int* nums, int numsSize) {
    // 输入校验，防止空数组和无效的numsSize
    if (nums == NULL || numsSize < 0) {
        return -1;
    }
    int start = 1;
    int end = numsSize - 1;
    while (start <= end) {
        // 拆分区间
        int mid = (start + end) / 2;
        // 获取区间数字出现次数 第一次获取[1,m]
        int count = getCountRange(nums, numsSize, start, mid);
        // 区间拆分到一个元素，如果个数 > 1 说明该数就是重复数
        if (start == end) {
            if (count > 1) {
                return start;
            }
            break;
        }

        // 当前区间范围的数字大于当前区间数字个数 说明重复数就在当前区间
        if (count > (mid - start + 1)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}


//leetcode submit region end(Prohibit modification and deletion)
