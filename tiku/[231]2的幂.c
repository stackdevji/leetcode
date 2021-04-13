//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。 
//
// 示例 1: 
//
// 输入: 1
//输出: true
//解释: 20 = 1 
//
// 示例 2: 
//
// 输入: 16
//输出: true
//解释: 24 = 16 
//
// 示例 3: 
//
// 输入: 218
//输出: false 
// Related Topics 位运算 数学

// 思想在编写位中1的个数时
// 使用的方法是 n & (n-1) 他的操作时将n的最右位的1变成0
// 2的幂次方的二进制只有一位是1 所以 n & (n - 1) = 0

//leetcode submit region begin(Prohibit modification and deletion)


bool isPowerOfTwo(int n){
    if (n <= 0) return false;
    return n & (n - 1) ? false : true;
}


//leetcode submit region end(Prohibit modification and deletion)
