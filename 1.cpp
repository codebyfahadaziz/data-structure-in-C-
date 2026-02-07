#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Find minimum value (leftmost node)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1 & 2: one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;

    int values[] = {7, 3, 10, 1, 6, 8, 13, 4, 14};
    int n = sizeof(values) / sizeof(values[0]);

    // Insert values
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    cout << "================ BST TRAVERSALS ================\n";
    cout << "Inorder   : ";
    inorder(root);

    cout << "\nPreorder  : ";
    preorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    cout << "\n\n============= DELETE OPERATIONS =============\n";

    cout << "After deleting 4  : ";
    root = deleteNode(root, 4);
    inorder(root);

    cout << "\nAfter deleting 13 : ";
    root = deleteNode(root, 13);
    inorder(root);

    cout << "\nAfter deleting 7  : ";
    root = deleteNode(root, 7);
    inorder(root);

    cout << "\n=============================================\n";
    return 0;
}

