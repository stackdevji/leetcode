//找出数组中重复的数字。 
//
// 
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请
//找出数组中任意一个重复的数字。 
//
// 示例 1： 
//
// 输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3 
// 
//
// 
//
// 限制： 
//
// 2 <= n <= 100000 
// Related Topics 数组 哈希表
// 👍 382 👎 0

// 思路：寻找重复数-首先看数字范围，该题目数字范围是[0-n-1], 长度是n
// 说明数组元素值的范围和数组下标值是一样的，如果数组没有重复数字，排序之后如下示例
// 数组：[0, 1, 2, 3, 4]
// 下标：[0, 1, 2, 3, 5] 也就是a[i] = i
// 如果有重复
// 数组：[0, 1, 2, 2, 4]
// 下标：[0, 1, 2, 3, 5] 一定会存在a[i] != i, 假设a[i] = m, 则一定会存在 a[i] = m = a[m]
// 所以如果 a[i] != i = m 那就让a[i] 回到 a[m] m下标对应的位置 a[i] = i, i++


//leetcode submit region begin(Prohibit modification and deletion)
func findRepeatNumber(nums []int) int {
	n := len(nums)
	if n <= 0 {
		return -1
	}

	i := 0
	for i < n {
		if nums[i] == i {
			i++
			continue
		}

		// 发生重复
		m := nums[i]
		if m == nums[m] {
			return m
		}

		// 交换
		tmp := nums[m]
		nums[m] = nums[i]
		nums[i] = tmp
	}

	return -1
}
//leetcode submit region end(Prohibit modification and deletion)
