## Binary Search Tree

A binary search Tree is a tree data structure in which the value of the left child is less than the parent node and the value of the right child is greater than the parent node.

```
    10
   /  \
  5    15
 / \   / \
2   7 12  20

```

The above tree is a binary search tree.

> Lets get into the implementation of bst:

```cpp

#include<bits/stdc++.h>
using namespace std;

class BST{
    public:
    int val;
    BST *left;
    BST *right;

    BST(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
}


// iterative implementation of bst insertion
BST* insert(BST *tree , int val){
    if(tree == NULL){
        tree = new BST(val);
        return tree;
    }
    BST *currentNode = tree;
    while(!currentNode){
        if(val < currentNode->val){
            if(currentNode->left == NULL){
                currentNode->left = new BST(val);
                break;
            }
            else{
                currentNode = currentNode->left;
            }
        }
        else{
            if(currentNode->right == NULL){
                currentNode->right = new BST(val);
                break;
            }
            else{
                currentNode = currentNode->right;
            }
        }
    }
    return tree;
}

// lets do a iterative implementation

BST* insertRecursive(BST *tree , int val){
    if(tree == NULL){
        tree = new BST(val);
        return tree;
    }
    if(val < tree->val){
        tree->left = insertRecursive(tree->left,val);
    }
    else{
        tree->right = insertRecursive(tree->right,val);
    }
    return tree;
}

// lets implement search in bst -> just need to traverse the tree and check if the root is equal to the value or not. if not equal then use the bst property to go to the left or right subtree accordingly.

bool search(BST *tree, int val){
    if(tree == NULL) return false;
    if(tree->val == val) return true;
    if(val < tree->val){
        return search(tree->left,val);
    }
    else{
        return search(tree->right,val);
    }
}


void display(BST *tree){
    if(tree == NULL){
        return;
    }
    display(tree->left);
    cout<<tree->val<<" ";
    display(tree->right);
}


int main(){
    BST *tree = NULL;
    char choice;

    do{
        int val;
        cout<<"Enter the value to be inserted in the tree: ";
        cin>>val;
        tree = insert(tree,val);
        cout<<"Do you want to insert more values? (y/n): ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');


    cout<<"The tree is: ";
    display(tree);

    cout<<"\n\nEnter the value to be searched in the tree: ";
    int val;
    cin>>val;
    if(search(tree,val)){
        cout<<"The value is present in the tree";
    }
    else{
        cout<<"The value is not present in the tree";
    }


    return 0;
}

```


### Time Complexity of BST

> We know that the time complexity of searching in a binary search tree is O(h), where h is the height of the tree. In the worst case, the height of a BST is O(n), where n is the number of nodes in the tree. Therefore, the worst-case time complexity of searching in a BST is O(n).