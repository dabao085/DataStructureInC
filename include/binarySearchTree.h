/*
 * Author: Cheng xiang
 * Date: 2019-2-25
 * header of tree structure, templates defination must located in header
*/

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_
#include <iostream>
#include <algorithm>
#include "exceptions.h"

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr)
    {}

    BinarySearchTree(const BinarySearchTree &rhs) : root(nullptr)
    {
        root = clone(rhs.root);
    }

    // BinarySearchTree(BinarySearchTree && rhs) : root(rhs->root)
    // {
    //     rhs.root = nullptr;
    // }
    
    BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        BinarySearchTree temp(rhs);
        std::swap(*this, temp); //Effective C++ item 11
        return *this;   //Effective C++ item 10
    }

    ~BinarySearchTree()
    {
        makeEmpty();
    }

    const Comparable &findMax() const
    {
        if(isEmpty())
        {
            throw UnderflowException{};
        }
        return findMax(root)->element;
    }

    const Comparable &findMin() const
    {
        if(isEmpty())
        {
            throw UnderflowException{};
        }
        return findMin(root)->element;
    }

    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    // void printTree() const
    // {
    //     printTree(cout, root);
    // }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(const Comparable & x)
    {
        insert(x, root);
    }

    void remove(const Comparable & x)
    {
        remove(x, root);
    }

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left; //left child
        BinaryNode *right; //right child

        BinaryNode(const Comparable &x, BinaryNode *lt, BinaryNode *rt):
        element(x), left(lt), right(rt){}
    };

    void remove(const Comparable &x, BinaryNode * & t)
    {
        if(t == nullptr)
            return ;
        else if(x < t->element)
        {
            remove(x, t->left);
        }
        else if(x > t->element)
        {
            remove(x, t->right);
        }
        else    //find the element which will be removed
        {
            if((t->left != nullptr) && (t->right != nullptr))   //have both tow children(left child and right child).
            {
                t->element = findMin(t->right)->element;        //get the min of right subtree
                remove(t->element, t->right);                   //remove the min of right subtree
            }
            else
            {
                BinaryNode *oldNode = t;
                if(t->left != nullptr)  //left child is avaliable.
                {
                    t = t->left;
                }
                else    //right child is avaliable or right child is nullptr.
                {
                    t = t->right;
                }
                delete oldNode; //needn't make oldNode to nullptr, cause pointer "oldNode" is a tmp object, it will release after out of range.
            }
        }
    }

    bool contains(const Comparable &x, BinaryNode *t) const
    {
        if(t == nullptr)
        {
            return false;
        }
        else if (x < t->element)
        {
            return contains(x, t->left);
        }
        else if(x > t->element)
        {
            return contains(x, t->right);
        }
        else
        {
            return true;
        }
    }

    void makeEmpty(BinaryNode * & t)
    {
        if(t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;    //delete之后不要忘记赋上nullptr;
    }

    // void printTree(const ostream & os, BinaryNode *t)
    // {

    // }

    BinaryNode *findMax(BinaryNode *t) const
    {
        if(t != nullptr)
        {
            while(t->right != nullptr)
            {
                t = t->right;
            }
        }
        return t;
    }

    BinaryNode *findMin(BinaryNode *t) const
    {
        if(t != nullptr)
        {
            while(t->left != nullptr)
            {
                t = t->left;
            }
        }
        return t;
    }

    void insert(const Comparable &x, BinaryNode *& t)
    {
        if(t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }
        else if(x < t->element)
        {
            insert(x, t->left);
        }
        else if(x > t->element)
        {
            insert(x, t->right);
        }
        else//有重复元素，不做操作
        {
            /* code */
        }
    }

    BinaryNode *root;
};

//implement in function object
// template <typename Object, typename Comparable = less<Object>>
// class BinarySearchTreeWithComp
// {
// public:
//   BinarySearchTree();
//   BinarySearchTree(const BinarySearchTree &rhs);
//   BinarySearchTree &operator=(const BinarySearchTree &rhs);
//   ~BinarySearchTree();

//   const Object &findMax() const;
//   const Object &findMin() const;
//   bool contains(const Object &x) const;
//   bool isEmpty() const;
//   void printTree() const;

//   void makeEmpty();
//   void insert(const Object & x);
//   void remove(const Object & x);

// private:
//   struct BinaryNode
//   {
//     Object element;
//     BinaryNode *left; //left child
//     BinaryNode *right; //right child

//     BinaryNode(const Object &x, BinaryNode *lt, BinaryNode *rt):
//     element(x), left(lt), right(rt){}
//   };

//   void remove(const Object &x, BinaryNode * & t);
//   bool contains(const Object &x, BinaryNode *t) const;
//   void makeEmpty(BinaryNode * & t);
//   void print(BinaryNode *t);

//   BinaryNode *root;
// };
#endif