

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func buildTree(nums []int, begin, end int) *TreeNode {
    if begin >= end {
        return nil
    }
    max_i := begin

    for i := begin+1; i < end; i++ {
        if nums[max_i] < nums[i] {
            max_i = i
        }
    }

    return &TreeNode{
        nums[max_i],
        buildTree(nums, begin, max_i),
        buildTree(nums, max_i+1, end),
    }
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
    return buildTree(nums, 0, len(nums))

}
