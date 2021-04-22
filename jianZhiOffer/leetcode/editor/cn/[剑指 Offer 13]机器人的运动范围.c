//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
//格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
//它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 2： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
// 👍 274 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
int getBitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool checkMove(int i, int j, int k) {
    if (getBitSum(i) + getBitSum(j) > k) {
        return false;
    }
    return true;
}

int movingCountHandle(int m, int n, int k, int i, int j, int* visited) {
    int count = 0;
    if (i >= 0 && i < m && j >= 0 && j < n && checkMove(i, j, k) && visited[i * n + j] == 0) {
        visited[i * n + j] = 1;
        count = movingCountHandle(m, n, k, i, j - 1, visited) +
                movingCountHandle(m, n, k, i + 1, j, visited) +
                movingCountHandle(m, n, k, i, j + 1, visited) +
                movingCountHandle(m, n, k, i - 1, j, visited) + 1;
    }
    return count;
}

int movingCount(int m, int n, int k){
    if (m < 0 || n < 0 || k < 0) {
        return 0;
    }

    if (m == 0 && n == 0 && k == 0) {
        return 1;
    }

    int len = m * n;
    int *visited = (int*)malloc(sizeof(int) * len);
    memset(visited, 0, sizeof(int) * len);

    return movingCountHandle(m, n, k, 0, 0, visited);
}


//leetcode submit region end(Prohibit modification and deletion)
