#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertUtil(root, val);
    }

    void inorder() {
        inorderUtil(root);
        std::cout << std::endl;
    }

    void preorder() {
        preorderUtil(root);
        std::cout << std::endl;
    }

    void postorder() {
        postorderUtil(root);
        std::cout << std::endl;
    }

    void levelByLevel() {
        levelByLevelUtil(root);
    }

    int height() {
        return heightUtil(root);
    }

    void ancestors(int val) {
        ancestorsUtil(root, val);
        std::cout << std::endl;
    }

    int whatlevelamI(int val) {
        return whatlevelamIUtil(root, val, 0);
    }

private:
    TreeNode* insertUtil(TreeNode* node, int val) {
        if (node == nullptr)
            return new TreeNode(val);

        if (val < node->data)
            node->left = insertUtil(node->left, val);
        else if (val > node->data)
            node->right = insertUtil(node->right, val);

        return node;
    }

    void inorderUtil(TreeNode* node) {
        if (node == nullptr)
            return;

        inorderUtil(node->left);
        std::cout << node->data << " ";
        inorderUtil(node->right);
    }

    void preorderUtil(TreeNode* node) {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";
        preorderUtil(node->left);
        preorderUtil(node->right);
    }

    void postorderUtil(TreeNode* node) {
        if (node == nullptr)
            return;

        postorderUtil(node->left);
        postorderUtil(node->right);
        std::cout << node->data << " ";
    }

    void levelByLevelUtil(TreeNode* node) {
        if (node == nullptr)
            return;

        std::queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                std::cout << curr->data << " ";

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            std::cout << std::endl;
        }
    }

    int heightUtil(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = heightUtil(node->left);
        int rightHeight = heightUtil(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

    bool ancestorsUtil(TreeNode* node, int val) {
        if (node == nullptr)
            return false;

        if (node->data == val)
            return true;

        if (ancestorsUtil(node->left, val) || ancestorsUtil(node->right, val)) {
            std::cout << node->data << " ";
            return true;
        }

        return false;
    }

    int whatlevelamIUtil(TreeNode* node, int val, int level) {
        if (node == nullptr)
            return -1;

        if (node->data == val)
            return level;

        int leftLevel = whatlevelamIUtil(node->left, val, level + 1);
        if (leftLevel != -1)
            return leftLevel;

        int rightLevel = whatlevelamIUtil(node->right, val, level + 1);
        return rightLevel;
    }
};

int main() {
    BST bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    std::cout << "Inorder traversal: ";
    bst.inorder();

    std::cout << "Preorder traversal: ";
    bst.preorder();

    std::cout << "Postorder traversal: ";
    bst.postorder();

    std::cout << "Level by level traversal:" << std::endl;
    bst.levelByLevel();

    std::cout << "Height of the BST: " << bst.height() << std::endl;

    std::cout << "Ancestors of 3: ";
    bst.ancestors(3);

    int dataToFind = 5;
    int level = bst.whatlevelamI(dataToFind);
    if (level != -1)
        std::cout << "Level of data " << dataToFind << " is: " << level << std::endl;
    else
        std::cout << "Data " << dataToFind << " not found in the BST." << std::endl;

    return 0;
}
