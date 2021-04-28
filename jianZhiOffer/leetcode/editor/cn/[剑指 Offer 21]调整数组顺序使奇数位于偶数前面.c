//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。 
//
// 
//
// 示例： 
//
// 
//输入：nums = [1,2,3,4]
//输出：[1,3,2,4] 
//注：[3,1,2,4] 也是正确的答案之一。 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 50000 
// 1 <= nums[i] <= 10000 
// 
// 👍 120 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isODDNumber(int num) {
    return num & 1 == 1 ? true : false;
}

int* exchange(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize <= 0) return NULL;

    int start = 0;
    int end = numsSize - 1;

    int* res = (int*)malloc(sizeof(int) * numsSize);
    while (start < end) {
        while(start < end && isODDNumber(nums[start])){
            start++;
        }
        while(start < end && !isODDNumber(nums[end])) {
            end--;
        }

        if (start < end) {
            int startNum = nums[start];
            nums[start] = nums[end];
            nums[end] = startNum;
        }

    }

    *returnSize = numsSize;
    return nums;
}


//leetcode submit region end(Prohibit modification and deletion)
