#include <iostream>
using namespace std;

/* ===== AVL NODE STRUCTURE ===== */
struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
};

/* ===== FUNCTION TO GET MAX ===== */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* ===== FUNCTION TO GET HEIGHT ===== */
int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

/* ===== CREATE NEW NODE ===== */
Node* newNode(int value)
{
    Node *node = new Node();
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

/* ===== BALANCE FACTOR ===== */
int getBalance(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

/* ===== RIGHT ROTATION (LL CASE) ===== */
Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* ===== LEFT ROTATION (RR CASE) ===== */
Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/* ===== INSERT NODE ===== */
Node* insert(Node* node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/* ===== INORDER TRAVERSAL ===== */
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

/* ===== MAIN FUNCTION ===== */
int main()
{
    Node *root = NULL;
    int n, value;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal of AVL Tree:\n";
    inorder(root);

    cout << endl;
    return 0;
}

