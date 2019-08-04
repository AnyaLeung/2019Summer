/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean helper(TreeNode root, Integer lower, Integer upper){
        if(root==null){
            return true;
        }
        
        int val = root.val;
        if(lower!=null && val<=lower){
            return false;
        }
        if(upper!=null && val>=upper){
            return false;
        }
        
        if(!helper(root.right, val, upper)){
            return false;
        }
        if(!helper(root.left, lower, val)){
            return false;
        }
        
        return true;
    }
    public boolean isValidBST(TreeNode root) {
        return helper(root, null, null);
    }
}
