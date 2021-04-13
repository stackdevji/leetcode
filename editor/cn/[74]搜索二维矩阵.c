//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性： 
//
// 
// 每行中的整数从左到右按升序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 示例 1: 
//
// 输入:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 13
//输出: false 
// Related Topics 数组 二分查找

// 思想：
// 也是二分查找思想，用矩阵右上角的数字做判断
// 如果目标值 < 右上角的值 （则剔除右上角值对应的列）
// 如果目标值 > 右上角的值 （则剔除右上角值对应的行）
// 以此类推
// 注意数组下标越界问题

//leetcode submit region begin(Prohibit modification and deletion)


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrix == NULL || matrixColSize == NULL || matrixSize <= 0 || *matrixColSize <= 0) {
        return false;
    }
    int col = (*matrixColSize) - 1;
    int row = 0;
    while (row < matrixSize && col >= 0) {
        if (target > matrix[row][col] ) ++row;          // 目标值大于右上角的值 剔除行
        else if (target < matrix[row][col]) --col;      // 目标值小于右上角的值 剔除列
        else return true;
    }
    return false;
}


//leetcode submit region end(Prohibit modification and deletion)
