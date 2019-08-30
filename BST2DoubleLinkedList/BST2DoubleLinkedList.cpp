public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}
public class BSTToLinkList {
    private TreeNode pre;
    private TreeNode head;
    public TreeNode Convert(TreeNode root) {
        visit(root);
        return head;
    }
    private void visit(TreeNode root){
        visit(root.left);
        create(root);
        visit(root.right);
    }
    private void create(TreeNode treeNode){
        treeNode.left = pre;
        if (pre==null)
            head = treeNode;
        else
            pre.right = treeNode;
        pre = treeNode;
    }
}


void ConvertNode(BinaryTreeNode * root,BinaryTreeNode **lastnode)
{
    if(root==NULL) return ;
    BinaryTreeNode * p=root;
    if(p->leftchild!=NULL)
    ConvertNode(p->leftchild,lastnode);
    p->leftchild=*lastnode;
    if(*lastnode!=NULL)
    (*lastnode)->rightchild=p;
    *lastnode=p;
    if(p->rightchild!=NULL)
    ConvertNode(p->rightchild,lastnode);

————————————————
版权声明：本文为CSDN博主「apsara-jueying」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/gl361148026/article/details/8887134
