//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个
//整数，判断数组中是否含有该整数。 
//
// 
//
// 示例: 
//
// 现有矩阵 matrix 如下： 
//
// 
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// 给定 target = 5，返回 true。 
//
// 给定 target = 20，返回 false。 
//
// 
//
// 限制： 
//
// 0 <= n <= 1000 
//
// 0 <= m <= 1000 
//
// 
//
// 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/ 
// Related Topics 数组 双指针 
// 👍 302 👎 0

// 思路： 从左到右有序，从上到下有序，用右上角的值做判断
// target > 右上角，第一行都比目标值小
// target < 右上角，最后一列都比目标值大
//


//leetcode submit region begin(Prohibit modification and deletion)
func findNumberIn2DArray(matrix [][]int, target int) bool {
	rowLen := len(matrix)
	if rowLen <= 0 || len(matrix[0]) <= 0 {
		return false
	}
	colLen := len(matrix[0])

	i, j := 0, colLen - 1
	for i < rowLen && j >= 0 {
		if target == matrix[i][j] {
			return true
		} else if target > matrix[i][j] {
			i++
		} else {
			j--
		}
	}
	return false
}
//leetcode submit region end(Prohibit modification and deletion)
