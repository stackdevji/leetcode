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
// 👍 302 👎 0

// 回溯法：一条路径有多个节点组成，一个节点有多个方式（最多4个 上下左右）到达下一个节点
// 判断每个节点是否符合路径查询字符，符合则往下找，不符合则回到上一个节点，如果一个节点的所有
// 路径都没有匹配的字符，则查询失败


//leetcode submit region begin(Prohibit modification and deletion)
bool isHasPath(char** board, int rows, int cols, int row, int col, char* word, int* pathLength, int* isVisit) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }

    // 目标单词遍历完成，返回
    if (word[*pathLength] == '\0') {
        return true;
    }

    bool hasPath = false;
    if (board[row][col] == word[*pathLength] && isVisit[row * cols + col] == 0) {
        // 匹配字符索引前进
        (*pathLength)++;
        // 访问标记
        isVisit[row * cols + col] = 1;

        // 当前节点的相邻位置判断下一个字符是否匹配
        hasPath = isHasPath(board, rows, cols, row, col - 1, word, pathLength, isVisit) || // 左侧节点
                  isHasPath(board, rows, cols, row + 1, col, word, pathLength, isVisit) || // 下侧节点
                  isHasPath(board, rows, cols, row, col + 1, word, pathLength, isVisit) || // 右侧节点
                  isHasPath(board, rows, cols, row - 1, col, word, pathLength, isVisit);   // 上侧节点

        if (!hasPath) {
            // 匹配字符索引返回上一个位置继续匹配
            (*pathLength)--;
            // 当前节点还可以继续访问 利于遍历其他路径
            isVisit[row * cols + col] = 0;
        }
    }
    return hasPath;
}

int strLen(char* word) {
    int i = 0;
    while(word[i] != '\0') i++;
    return i;
}



bool exist(char** board, int boardSize, int* boardColSize, char* word){
    if (board == NULL || *board == NULL || boardSize <= 0 || *boardColSize <= 0 || word == NULL) {
        return false;
    }


    // 定义是否访问矩阵，用来标识一个节点是否已经被访问
    int rows = boardSize;
    int cols = *boardColSize;
    int len = rows * cols;

    // 要注意的边界条件
    if (rows == 1 && cols == 1) return len == strLen(word) && word[0] == board[0][0]  ? true : false;

    int *isVisit = malloc(sizeof(int) * len);
    memset(isVisit, 0,  len * sizeof(int));

    int pathLength = 0;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < (*boardColSize); ++j) {
            if (isHasPath(board, rows, cols, i, j, word, &pathLength, isVisit)) {
                return true;
            }
        }
    }

    return false;
}
//leetcode submit region end(Prohibit modification and deletion)
