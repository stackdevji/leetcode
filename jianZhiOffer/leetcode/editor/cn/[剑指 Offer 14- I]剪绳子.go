//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
//请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
//。 
//
// 示例 1： 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36 
//
// 提示： 
//
// 
// 2 <= n <= 58 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划 
// 👍 217 👎 0

package cn

//leetcode submit region begin(Prohibit modification and deletion)
func cuttingRope(n int) int {
	if n <= 1 {
		return 0
	}
	if n == 2 {
		return 1
	}
	if n == 3 {
		return 2
	}

	// 定义 0 <= i <= n对应的乘积数组
	maxArr := make([]int, n + 1)

	// 初始化0-3的最大乘积，因为n<=3的最大乘积都小于本身，会影响 n >= 4 乘积的计算，所以最大乘积等于本身
	maxArr[0] = 0
	maxArr[1] = 1
	maxArr[2] = 2
	maxArr[3] = 3

	max := 0
	for i := 4; i <= n; i++ {
		// 过滤重复序列 比如 n = 4 可以切割的序列为 （1, 3） (2, 2) (3, 1) 所以只比对一半就行
		for j := 1; j <= i / 2; j++ {
			product := maxArr[j] * maxArr[i - j]
			if max < product {
				max = product
			}
		}
		maxArr[i] = max
	}

	return maxArr[n]
}
//leetcode submit region end(Prohibit modification and deletion)
