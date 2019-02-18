/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursion but cannot pass the testcase with large amount of input ???
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //this is the empty tree;
    if(preorder.size()==0||inorder.size()==0){
      return NULL;
    }
    //build the root and divide the left tree and the right tree
    TreeNode *root=new TreeNode(preorder[0]);

    //root.val=preorder[0];
        
    //look the root value in the inorder vector
    int i;
    for(i=0;i<inorder.size();i++){
      if(inorder[i]==preorder[0]){
	break;
      } 
    }
    if(i==inorder.size()){
      return NULL;
    }
    std::vector<int> in_split_lf(inorder.begin(), inorder.begin() + i);
    //std::cout<<in_split_lf.size()<<std::endl;
    std::vector<int> in_split_rh(inorder.begin() + i+1, inorder.end());
    //std::cout<<in_split_rh.size()<<std::endl;
    std::vector<int> pre_split_lf(preorder.begin()+1,preorder.begin()+1+i);
    //std::cout<<pre_split_lf.size()<<std::endl;
    std::vector<int> pre_split_rh(preorder.begin()+i+1,preorder.end());
    //std::cout<<pre_split_rh.size()<<std::endl;
    //build the left tree and the right tree
    if(pre_split_lf.size()>0){
      root->left=buildTree(pre_split_lf,in_split_lf);
    }
    if(pre_split_rh.size()>0){
      root->right=buildTree(pre_split_rh,in_split_rh);
    }
    return root;
  }
};
