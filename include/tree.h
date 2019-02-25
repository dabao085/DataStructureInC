/*
 * Author: Cheng xiang
 * Date: 2019-2-25
 * header of tree structure
*/

#ifndef _TREE_H_
#define _TREE_H_

template <typename Comparable>
class BinarySearchTree
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree &rhs);
  BinarySearchTree &operator=(const BinarySearchTree &rhs);
  ~BinarySearchTree();

  const Comparable &findMax() const;
  const Comparable &findMin() const;
  bool contains(const Comparable &x) const;
  bool isEmpty() const;
  void printTree() const;

  void makeEmpty();
  void insert(const Comparable & x);
  void remote(const Comparable & x);

private:
  struct BinaryNode
  {
    Comparable element;
    BinaryNode *left; //left child
    BinaryNode *right; //right child

    BinaryNode(const Comparable &x, BinaryNode *lt, BinaryNode *rt):
    element(x), left(lt), right(rt){}
  };

  BinaryNode *root;
};

#endif
