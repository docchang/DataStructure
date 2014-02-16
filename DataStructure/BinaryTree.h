//
//  BinaryTree.h
//  Tile
//
//  Created by Dominic Chang on 1/21/14.
//
//

#ifndef __Tile__BinaryTree__
#define __Tile__BinaryTree__

#include <iostream>

#include "Constant.h"

using namespace std;

template<typename T>
class Node {
public:
    
    T value;
    
    Node()
    : left(NULL)
    , right(NULL)
    {}
    
    Node(const T & v)
    : Node(v , NULL, NULL)
    {}
    
    Node(const T & v , Node * l , Node * r)
    : value(v)
    , left(l)
    , right(r)
    {}
    
    virtual ~Node()
    {}
    
    Node * left;
    
    Node * right;
    
    bool operator <(const Node & b) const {
        return this->value < b.value;
    }
    
    friend ostream& operator<<( ostream& Out, const Node & node) {
        Out << node.value;
        return Out;
    }
    
};


//#include "Constant.h"


#include <queue>
typedef queue<Node<int> *> q_node;

#include <stack>
//typedef stack<Node<int> *> stack_node


class BinaryTree {
public:
    BinaryTree()
    : head(NULL)
    {}
    
    virtual ~BinaryTree()
    {}
    
    Node<int> * head;
    
    
    //binary search tree
    void insertNode(Node<int> *& currNode , const int & value) {
        
        if (currNode == NULL) {
            currNode = new Node<int>(value);
            return;
        }
        
        cout << DebugLog << *currNode << endl;
        
        //new Node bigger than current Node
        if (currNode->value < value) {
            insertNode(currNode->right , value);
            return;
        }
        
        //new node less than current node
        insertNode(currNode->left , value);
    }
    
    void insert(const int & value) {
        cout << DebugLog << "inserting: " << value << endl;
        insertNode(head , value);
    }
    
    
    void PreOrder(const Node<int> * node) {
        if (node == NULL) { return; }
        
        cout << DebugLog << *node << endl;
        PreOrder(node->left);
        PreOrder(node->right);
    }
    void PreOrderTraversal() {
        PreOrder(head);
    }
    
    
    
    static void PreOrderHelper(ostream & Out , const Node<int> * node) {
        if (node == NULL) {
            Out << "#" << endl;
            return;
        }
        
        Out << *node << endl;
        PreOrderHelper(Out , node->left);
        PreOrderHelper(Out , node->right);
    }
    
    friend ostream& operator<<(ostream& Out, const BinaryTree & bTree) {
        BinaryTree::PreOrderHelper(Out , bTree.head);
        return Out;
    }
    
    static void PreOrderInsert(istream& ins , Node<int> *& node) {
        
        string valueStr;
        
        if (!(ins >> valueStr)) { return; }
        
        if (valueStr == "#") { return; }
        
        int valueInt = std::stoi( valueStr );
        
        node = new Node<int>(valueInt);
        PreOrderInsert(ins , node->left);
        PreOrderInsert(ins , node->right);
    }
    
    friend istream& operator>>(std::istream& ins, BinaryTree *& bTree) {
        bTree = new BinaryTree();
        BinaryTree::PreOrderInsert(ins , bTree->head);
        return ins;
    }

    
    void InOrder(const Node<int> * node) {
        if (node == NULL) { return; }
        
        InOrder(node->left);
        cout << DebugLog << *node << endl;
        InOrder(node->right);
    }
    void InOrderTraversal() {
        InOrder(head);
    }

    void PostOrder(const Node<int> * node) {
        if (node == NULL) { return; }
        
        PostOrder(node->left);
        PostOrder(node->right);
        cout << DebugLog << *node << endl;
    }
    void PostOrderTraversal() {
        PostOrder(head);
    }
    
    void insertRandom(const int count) {
        for ( int i = 0; i < count; i++) {
            insert(ARC4RANDOM(1000));
        }
    }
    
    bool BSTValidation(const Node<int> * node , Node<int> *& prevNode) {
        
        
        cout << "Previous Node:" << ((prevNode == NULL) ? "NULL" : std::to_string(prevNode->value)) << endl;
        
        //base case
        if (node == NULL) { return true; }
        
        
        //visit left
        if (BSTValidation(node->left, prevNode) == false) { return false; }
        
        
        //fault case: Previous Node is bigger or equal to current node
        if (prevNode != NULL && prevNode->value >= node->value) {
            cout << "Fault node found:" << prevNode->value << ">=" << node->value << endl;
            return false;
        }
        
        //assign previous node
        prevNode = (Node<int> *)node;
        
        
        //visit right assigning previous node to current node
        if (BSTValidation(node->right, prevNode) == false) { return false; }
        
        
        return true;
    }
    
    
    void visit(Node<int> * node) {
        if (node == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << node->value << endl;
        }
    }
    
    void BottomUpTraversal(std::queue<Node<int> *> & q) {
        
        if (q.empty()) { return; }
        
        Node<int> * node = q.front();
        
        q.pop();
        
        if (node) {
            q.push(node->left);
            q.push(node->right);
        }
        
        BottomUpTraversal(q);
        
        visit(node);
        
    }
};


#endif /* defined(__Tile__BinaryTree__) */
