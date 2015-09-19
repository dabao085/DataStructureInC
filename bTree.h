#ifndef _B_TREE_

struct TreeNode;
typedef struct TreeNode* ptrToTree;
typedef ptrToTree Tree;

struct TreeNode
{
  int data;
  Tree left;
  Tree right;
};


#endif
