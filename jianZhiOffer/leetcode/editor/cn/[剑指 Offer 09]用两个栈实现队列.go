//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的
//功能。(若队列中没有元素，deleteHead 操作返回 -1 ) 
//
// 
//
// 示例 1： 
//
// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
// 
//
// 示例 2： 
//
// 输入：
//["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
//[[],[],[5],[2],[],[]]
//输出：[null,-1,null,null,5,2]
// 
//
// 提示： 
//
// 
// 1 <= values <= 10000 
// 最多会对 appendTail、deleteHead 进行 10000 次调用 
// 
// Related Topics 栈 设计 
// 👍 224 👎 0

// queue: 先进先出，
// stack: 先进后出
// stack1只做入队用
// stack2做出队用，出队时，stack2有数据直接pop. 没有数据从stack1导入数据，否则返回-1

//leetcode submit region begin(Prohibit modification and deletion)
type CQueue struct {
	Stack1 []int
	Stack2 []int
}

func Constructor() CQueue {
	return CQueue{
		Stack1: make([]int, 0),
		Stack2: make([]int, 0),
	}
}

// 在队列尾部添加元素
func (this *CQueue) AppendTail(value int)  {
	this.Stack1 = append(this.Stack1, value)
}

func (this *CQueue) Pop(s *[]int) int {
	value := (*s)[len(*s) - 1]
	(*s) = (*s)[:len(*s) - 1]
	return value
}

// 删除头部元素
func (this *CQueue) DeleteHead() int {
	l1 := len(this.Stack1)
	l2 := len(this.Stack2)

	if l2 > 0 {
		return this.Pop(&(this.Stack2))
	}

	if l1 <= 0 {
		return -1
	}

	for l1 > 0 {
		v := this.Pop(&(this.Stack1))
		this.Stack2 = append(this.Stack2, v)
		l1--
	}

	return this.Pop(&(this.Stack2))
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
//leetcode submit region end(Prohibit modification and deletion)
