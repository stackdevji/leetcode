//请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 
//9，则该函数输出 2。 
//
// 
//
// 示例 1： 
//
// 
//输入：00000000000000000000000000001011
//输出：3
//解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
// 
//
// 示例 2： 
//
// 
//输入：00000000000000000000000010000000
//输出：1
//解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
// 
//
// 示例 3： 
//
// 
//输入：11111111111111111111111111111101
//输出：31
//解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。 
//
// 
//
// 提示： 
//
// 
// 输入必须是长度为 32 的 二进制串 。 
// 
//
// 
//
// 注意：本题与主站 191 题相同：https://leetcode-cn.com/problems/number-of-1-bits/ 
// Related Topics 位运算 
// 👍 104 👎 0

// 位运算：
// & (与)：都为1才为1 否则为0
// | (或)：都为0才为0 否则为1
// ^ (异或)：不同为1 相同为0
// m << n：m左移n位
// m >> n：m右移n位

package cn

//leetcode submit region begin(Prohibit modification and deletion)
// 这种写法如果参数是负数的话，最高位是1，右移会死循环
//func hammingWeight(num uint32) int {
//	count := 0
//	for num > 0 {
//		if num & 1 == 1 {
//			count++
//		}
//		num = num >> 1
//	}
//    return count
//}

// n - 1 的操作是 把最右边位=1的变成0，后面如果有0变成1
// n - 1 & n = 0 该操作相当于把最右边的1变成0，相当于统计了一次1
// n不为0就还有1
func hammingWeight(num uint32) int {
	count := 0
	for num > 0 {
		num = (num - 1) & num
		count++
	}
	return count
}

//leetcode submit region end(Prohibit modification and deletion)
