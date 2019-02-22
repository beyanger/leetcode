
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flipEquiv(a *TreeNode, b *TreeNode) bool {
    if a == nil || b == nil {
        return a == nil && b == nil
    }
    if a.Val != b.Val {
        return false
    }
    if flipEquiv(a.Left, b.Left) && flipEquiv(a.Right, b.Right) {
        return true
    }
    if flipEquiv(a.Left, b.Right) && flipEquiv(a.Right, b.Left) {
        return true
    }
    return false
}
