```In the context of binary trees, the LCA is defined as the deepest (furthest from the root) node that is a common ancestor of two specified nodes.```

Algorithm:

Here's a simple algorithm to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree:

```
1. Define a function to find the LCA:
     - The function takes three parameters: the root of the binary tree, and the two nodes, p and q, for which we want to find the LCA.
     - The function returns the LCA node or null if one or both of the nodes are not present in the tree.

2. If the root is null, return null (base case).

3. If the root is either p or q, return the root itself as it is the LCA.

4. Recursively find the LCA in the left and right subtrees:
     - Call the function recursively for the left child of the root: LCA(root.left, p, q).
     - Call the function recursively for the right child of the root: LCA(root.right, p, q).

5. If both the left and right recursive calls return non-null values, it means p and q are present in different subtrees, and the current root is the LCA. Return the root.

6. If only one of the left or right recursive calls returns a non-null value, it means both p and q are present in the same subtree. Return the non-null value as the LCA.

7. If both the left and right recursive calls return null, it means either p or q (or both) is not present in the tree. Return null as the LCA.

```

This algorithm finds the LCA by recursively traversing the binary tree and checking for the presence of nodes p and q in its left and right subtrees. By considering the cases where the nodes are present in different subtrees or in the same subtree, the algorithm determines the LCA effectively.


Iterative Implementation of the lca in a binary tree:

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p or root == q or root==nullptr) return root;

        //iterative approach
        stack<TreeNode*> st;
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=nullptr;
        st.push(root);

        while(!st.empty() and (parent.find(p)==parent.end() or parent.find(q)==parent.end())){
            auto node=st.top();
            st.pop();

            if(node->left!=nullptr){
                parent[node->left]=node;
                st.push(node->left);
            }
            if(node->right!=nullptr){
                parent[node->right]=node;
                st.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;
        while(p!=nullptr){
            ancestors.insert(p);
            p=parent[p];
        }

        while(ancestors.find(q)==ancestors.end()){
            q=parent[q];
        }
        return q;   
}
```


The time complexity of this approach is O(h), where h is the height of the BST. In the worst case, the height of a BST is O(n), where n is the number of nodes in the tree.


* >Now lets look at the recurive implementaion:

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        if(root == p or root == q or root==nullptr) return root;

        auto left_lca=lowestCommonAncestor(root->left,p,q);
        auto right_lca=lowestCommonAncestor(root->right,p,q);

        if(left_lca != nullptr and right_lca  != nullptr) return root;
        return (left_lca != nullptr)? left_lca : right_lca;
}

```

Recursive implementation of ancestor in a binary search tree:

```cpp

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }

    int pVal = p->val;
    int qVal = q->val;
    int nodeVal = root->val;
    // checking if both the p and q fall on the left side of the tree
    if (pVal < nodeVal && qVal < nodeVal) {
        return lowestCommonAncestor(root->left, p, q);
    }
    // checking if both the p and q fall on the right side of the tree 
    else if (pVal > nodeVal && qVal > nodeVal) {
        return lowestCommonAncestor(root->right, p, q);
    }
    // if both the p and q fall on the different sides of the tree
     else {
        return root;
    }

    return nullptr;
}

```



Iterative implementation of ancestor in a binary search tree:

```cpp

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

     if(root == p or root == q or root==nullptr) return root;

     //iterzaive approach
     while(root!=nullptr){
         if(root->val > p->val and root->val > q->val){
             root = root->left;
         }else if(root->val < p->val and root->val < q->val){
             root = root->right;
         }else{
             return root;
         }
     }
    return root;
}

```