
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Queue struct {
    l *list.List
}

func New() *Queue {
    return &Queue{list.New()}
}

func (q *Queue) Push(v interface{}) {
    q.l.PushBack(v)
}
func (q *Queue) Front() interface{} {
    e := q.l.Front()
    if e != nil {
        return e.Value
    }
    return nil
}

func (q *Queue) Pop() interface{} {
    e := q.l.Front()
    if e != nil {
        q.l.Remove(e)
        return e.Value
    }
    return nil
}

func (q *Queue) Len() int {
    return q.l.Len()
}
func (q *Queue) Empty() bool {
    return q.Len() == 0
}

func (q *Queue) Clear() {
    q.l.Init()
}

func levelOrder(root *TreeNode) [][]int {
    ans := make([][]int, 0)
    if root == nil {
        return ans
    }
    q := New()
    q.Push(root)
    for !q.Empty() {
        cr := make([]int, 0)
        for s := q.Len(); s > 0; s-- {
           root = q.Pop().(*TreeNode)
           cr = append(cr, root.Val)
           if root.Left != nil {
                q.Push(root.Left)
            }
            if root.Right != nil {
                q.Push(root.Right)
            }
        }
        ans = append(ans, cr)
    }

    return ans
}
