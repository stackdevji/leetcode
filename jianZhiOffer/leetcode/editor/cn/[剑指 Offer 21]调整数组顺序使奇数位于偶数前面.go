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

package cn

//leetcode submit region begin(Prohibit modification and deletion)
func isODDNumber(number int) bool {
	if number & 1 == 1 {
		return true
	} else {
		return false
	}
}

func exchange(nums []int) []int {
	if len(nums) <= 0 {
		return nil;
	}

	start, end := 0, len(nums) - 1

	for start < end {
		for start < end && isODDNumber(nums[start]) {
			start++;
		}

		for start < end && !isODDNumber(nums[end]) {
			end--;
		}

		if start < end {
			nums[start] = nums[start] + nums[end]
			nums[end] = nums[start] - nums[end]
			nums[start] = nums[start] - nums[end]
		}
	}

	return nums
}
//leetcode submit region end(Prohibit modification and deletion)
