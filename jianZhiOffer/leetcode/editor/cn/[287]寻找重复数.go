//给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。 
//
// 假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,4,2,2]  1 - 2 mid = 1 start = 2 end = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,1,3,4,2]
//输出：3
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1]
//输出：1
// 
//
// 示例 4： 
//
// 
//输入：nums = [1,1,2]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 2 <= n <= 3 * 104 
// nums.length == n + 1 
// 1 <= nums[i] <= n 
// nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次 
// 
//
// 
//
// 进阶： 
//
// 
// 如何证明 nums 中至少存在一个重复的数字? 
// 你可以在不修改数组 nums 的情况下解决这个问题吗？ 
// 你可以只用常量级 O(1) 的额外空间解决这个问题吗？ 
// 你可以设计一个时间复杂度小于 O(n2) 的解决方案吗？ 
// 
// Related Topics 数组 双指针 二分查找 
// 👍 1176 👎 0

// 思路：数字范围在[1,n]闭区间，所以说没有重复数字，数字的个数为n, 但是数组长度为n+1，是必有重复数字的
// 不重复: [1, 2, 3, 4, 5, 6] n = 6 l = 6 不重复一定是 个数n=范围n的
// 重复： [1, 2, 3, 4, 5, 5]  n = 5 l = n + 1 重复，个数n!=范围n
// 所以利用二分查找思想分区间判断个数和n, 如果不相等就是重复，直到找到他


//leetcode submit region begin(Prohibit modification and deletion)
// 统计下标范围内的元素个数
func getRangeCount(nums []int, start, end int) int {
	count := 0
	for i:= 0; i < len(nums); i++ {
		if nums[i] >= start && nums[i] <= end {
			count++
		}
	}
	return count
}

func findDuplicate(nums []int) int {
	l := len(nums)
	if l <= 0 {
		return -1
	}

	start, end := 1, l - 1 // 为什么要l-1, 因为l长度为(n+1), 判断区间用的是 1-n
	for start <= end {
		mid := (start + end) / 2
		count := getRangeCount(nums, start, mid)

		if start == end && count > 1 {
			return start // 对应重复的n
		}

		if count > mid - start + 1 {
			end = mid
		} else {
			start = mid + 1
		}
	}

	return -1
}
//leetcode submit region end(Prohibit modification and deletion)
