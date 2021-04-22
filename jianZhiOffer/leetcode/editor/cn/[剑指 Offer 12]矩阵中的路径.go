//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
// Related Topics 深度优先搜索 
// 👍 304 👎 0
package huisu

//leetcode submit region begin(Prohibit modification and deletion)
func isHasPath(board [][]byte, rows, cols, row, col, strLen int, matchIndex *int, isVisit [][]int, word string) bool {
	if *matchIndex > strLen {
		return true
	}

	hasPath := false
	str := uint8(board[row][col])
	if row >= 0 && row < rows && col >= 0 && col < cols && str == word[*matchIndex] && isVisit[row][col] == 0 {
		*matchIndex++
		isVisit[row][col] = 1

		hasPath = isHasPath(board, rows, cols, row, col - 1, strLen, matchIndex, isVisit, word) || // 左侧
			isHasPath(board, rows, cols, row + 1, col, strLen, matchIndex, isVisit, word) || // 下侧
			isHasPath(board, rows, cols, row, col + 1, strLen, matchIndex, isVisit, word) || // 右侧
			isHasPath(board, rows, cols, row - 1, col, strLen, matchIndex, isVisit, word) // 上侧

		if !hasPath {
			*matchIndex--
			isVisit[row][col] = 0
		}
	}

	return hasPath
}

func exist(board [][]byte, word string) bool {
	if board == nil || len(word) <= 0 {
		return false;
	}

	rows := len(board)
	cols := len(board[0])
	strLen := len(word)
	matchIndex := 0
	isVisits := make([][]int, rows * cols)
	for i := 0; i < rows; i++ {
		for j := 0; i < cols; j++ {
			isVisits[i][j] = 0
		}
	}

	for i := 0; i < rows; i++ {
		for j := 0; i < cols; j++ {
			if isHasPath(board, rows, cols, i, j, strLen, &matchIndex, isVisits, word) {
				return true
			}
		}
	}

	return false
}
//leetcode submit region end(Prohibit modification and deletion)
