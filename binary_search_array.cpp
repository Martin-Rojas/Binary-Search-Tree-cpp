#include <iostream>
#include <vector>

class TreeNode {
public:
    int value;
    TreeNode *left, *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

class binary_search_tree
{
    private:
        TreeNode *root;
    public:
        TreeNode* BuildBST(std::vector<int>& sortedArray, int start, int end) 
        { 
            // Base case
            if (start > end) {
                return NULL;
            }

            // Find the middle element
            int mid = ((start + end) / 2);

            // New node with the middle element
            TreeNode* root = new TreeNode(sortedArray[mid]);

            // Recursively build the left and right subtrees
            root->left = BuildBST(sortedArray, start, mid - 1);
            root->right = BuildBST(sortedArray, mid + 1, end);

            return root;
        }

        void setRoot(TreeNode* rootNode) 
        {
            root = rootNode;
        }

};

class ArrayBinaryTree {
private:
    std::vector<int> tree;
public:
    std::vector<int> extractedArray;
    std::vector<int> sortArrar;

    // Function to insert a new node at the first empty position
    void insert(int value) {
        tree.push_back(value);
    }
    
    // Function to get the index of the parent node
    int parent(int index) {
        if (index == 0) {
            std::cout << "Root node doesn't have a parent." << std::endl;
            return -1;
        }
        return (index - 1) / 2;
    }

    // Function to get the index of the left child
    int leftChild(int index) {
        int left = 2 * index + 1;
        if (left >= tree.size()) {
            return -1; // No left child
        }
        return left;
    }

    // Function to get the index of the right child
    int rightChild(int index) {
        int right = 2 * index + 2;
        if (right >= tree.size()) {
            return -1; // No right child
        }
        return right;
    }

    // Function to print the tree (for demonstration purposes, prints the array)
    void printTree() {
        for (int i = 0; i < tree.size(); i++) {
            std::cout << tree[i] << " ";
        }
        std::cout << std::endl;
    }

    void extractElements(){
        // Extract elements from the binary tree array into another array
        for (int i = 0; i < tree.size(); i++) {
            extractedArray.push_back(tree[i]);
        }
    }

    void displayElements(){
        // Print the extracted array
        std::cout << "Extracted Array: ";
        for (int val : extractedArray) {
            std::cout << val << " ";
        }
    }

    void bubbleSort() {
        for (int i = 0; i < extractedArray.size() - 1; i++) {
            for (int j = 0; j < extractedArray.size() - i - 1; j++) {
                if (extractedArray[j] > extractedArray[j + 1]) {
                    std::swap(extractedArray[j], extractedArray[j + 1]);
                }
            }
        }
    }
};

int main() {
    ArrayBinaryTree tree;
    
    // Inserting nodes
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    // Printing the tree
    std::cout << "Binary Tree (Array Representation): ";
    tree.printTree();

    // Example operations
    int index = 2; // Example index
    std::cout << "Parent of index " << index << ": " << tree.parent(index) << std::endl;
    std::cout << "Left child of index " << index << ": " << tree.leftChild(index) << std::endl;
    std::cout << "Right child of index " << index << ": " << tree.rightChild(index) << std::endl;
    
    std::cout << std::endl;
    std::cout << "My code .." << std::endl;
    tree.extractElements();
    tree.displayElements();
    std::cout << "My SORTED ARRAY>>>>>>" << std::endl;
    tree.bubbleSort();
    tree.displayElements();
    std::cout << std::endl;
    
    // Building BST from sorted array
    std::vector<int> sortedArray = tree.extractedArray;

    binary_search_tree bst;
    TreeNode* bstRoot = bst.BuildBST(sortedArray, 0, sortedArray.size() - 1);

    bst.setRoot(bstRoot);

    
    
    

    return 0;
}