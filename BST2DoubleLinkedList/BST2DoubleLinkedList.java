public class TreeNode {
   int val = 0;
   TreeNode left = null;
   TreeNode right = null;
   public TreeNode(int val) {
       this.val = val;
   }
}

public class Solution {
    private TreeNode head=null;
    private TreeNode last=null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        visit(pRootOfTree);
        return head;
    }

}
//中序遍历
private void visit(TreeNode root){
    if(root==null)
        return;
    visit(root.left);
    createList(root);
    visit(root.right);
}

//建表
private void createList(TreeNode node){
    //当前结点左结点连接上一个
    node.left=last;
    //为空说明当前结点是第一个结点
    if(last==null)
        head=node;
    else
        //不为空要将当前结点赋给上个结点的右结点
        last.right=node;
    //更新last
    last=node;
}
