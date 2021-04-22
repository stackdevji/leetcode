//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2
//] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。 
//
// 示例 1： 
//
// 输入：[3,4,5,1,2]
//输出：1
// 
//
// 示例 2： 
//
// 输入：[2,2,2,0,1]
//输出：0
// 
//
// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sor
//ted-array-ii/ 
// Related Topics 二分查找 
// 👍 298 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 旋转数组 前半个数组的值一定是大于等于后半个数组的值

int minByOrder(int* numbers, int numbersSize) {
    int min = numbers[0];
    for (int i = 1; i < numbersSize; i++) {
        if (min >= numbers[i]) {
            min = numbers[i];
        }
    }
    return min;
}

int minArray(int* numbers, int numbersSize){
    if (numbers == NULL || numbersSize <= 0) {
        return 0;
    }

    // 1. 初始化mid为start是应为[1,2,3]本身也是自己旋转0个元素的选装数组，所以第一个就是最小元素
    // 同样也不会进入循环，因为nums[start] < nums[end]
    int start = 0;
    int mid = start;
    int end = numbersSize - 1;
    while (numbers[start] >= numbers[end]) {2
        // 2. 正常情况，有序旋转数组的最小值分割前后子数组, 所以end对应元素是最小值
        if (end - start == 1) {
            mid =  end;
            break;
        }

        mid = (start + end) / 2;

        // 这种情况没有办法区分mid元素属于前半个子数组还是后半个子数组，所以只能顺序查找
        // 例如 [1, 0, 1, 1, 1] 和 [1, 1, 1, 0, 1]
        if (numbers[start] == numbers[end] && numbers[end] == numbers[mid]) {
            return minByOrder(numbers, numbersSize);
        }

        // 中间元素大于等于第一个元素，mid所属前一个区间，最小值在后面
        if (numbers[mid] >= numbers[start]) {
               start = mid;
        }

        // 中间元素小于等于最后一个个元素，mid所属后一个区间，最小值在前面
        if (numbers[mid] <= numbers[end]) {
            end = mid;
        }
    }

    return numbers[mid];
}


//leetcode submit region end(Prohibit modification and deletion)
