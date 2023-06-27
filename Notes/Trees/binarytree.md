## Binary Tree

A binary tree is a tree data structure where each node has at most two child nodes, referred to as the left child and the right child

➡️ Here's a brief overview of binary trees:

* The topmost node of a binary tree is called the root node.
* Each node can have at most two child nodes, referred to as the left child and the right child.
* Nodes with no children are called leaf nodes.
* The height of a binary tree is the length of the longest path from the root node to a leaf node.
* The depth of a node is the length of the path from the root node to that node.
* In-order traversal of a binary tree visits the left subtree, then the node itself, and then the right subtree.

> Lets see the implementation of the binary tree to understand it in more detail:
  * There will be insertion and deletion methods for the tree

```cpp

#include<bits/stdc++.h>

// Step 1: Create a node of the binary tree 

class Node{
    
    public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    };

// Step 2: Creating the Binary Tree
    class BinaryTree{
        public:
        BinaryTree(){
            root = NULL;
        }

        // Iterative Insertion
        void insert(int val){
            if(root == NULL){
                root = new Node(val);
                return;
            }
            queue<Node*> q;
            q.push(root);

            while(!q.empty){
                Node *currentNode =q.front();
                q.pop();

                if(currentNode->left == NULL){
                    currentNode->left = new Node(val);
                    return;
                }
                else if(currentNode->right == NULL){
                    currentNode->right = new Node(val);
                    return;
                }
                else{
                    q.push(currentNode->left);
                    q.push(currentNode->right);
                }
                    
            }

            // Recursive Implementation
            void addNode(int v) {
                root = addNodeHelper(root, v);
            }

            private:

            Node *addNodeHelper(Node *currentNode, int val) {
                if(currentNode == NULL){
                    return new Node(val)
                }

                if(currentNode->left == NULL){
                    currentNode->left = new Node(currentNode->left,val);
                }
                else if(currentNode->right == NULL){
                    currentNode->right = new Node(currentNode->right,val);
                }
                else{
                    currentNode->left=addNodeHelper(currentNode->left,val);
                    currentNode->right=addNodeHelper(currentNode->right,val);
                }

                return currentNode;
            }    
        }


    };
}

int main(){
    BinaryTree tree ;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
}

```