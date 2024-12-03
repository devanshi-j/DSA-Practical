#include <iostream>
#include <queue>
using namespace std;

class Node 
{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
    private :
    Node* root;

    Node * insert(Node * root , int data)
    {
        if(root == nullptr) return new Node(data);
        if (data < root->data)
        {
            root->left = insert(root->left , data);
        }
        else root->right = insert(root->right , data);

        return root;
    }

    Node* findMin(Node* root) 
    {
        while (root->left != nullptr) 
        {
            root = root->left;
        }
        return root;
    }


    Node * deleteN(Node *root , int data)
    {
        if(root == nullptr) return nullptr;
        
        if(data < root->data) root->left = deleteN(root->left, data);
        else if(data > root->data) root->right = deleteN(root->right, data);
        else {
        // Node found, handle deletion
        if (root->left == nullptr) { // Case 1 or Case 2 (right child exists or no children)
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) { // Case 2 (left child exists)
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right); // Find in-order successor
        root->data = temp->data; // Replace with in-order successor's value
        root->right = deleteN(root->right, temp->data); // Delete in-order successor
        }

        return root;
    }

    void preorder(Node* root) 
    {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) 
    {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) 
    {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    int height(Node* root)
    {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    public :
    BST() {
        root = nullptr;
    }

    void insertdata(int data)
    {
       root = insert(root , data);
    }

    void displayPreorder() 
    {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayInorder() 
    {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPostorder() 
    {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }

    void deleteNode(int data)
    {
        root = deleteN(root , data);
    }

    void heightT()
    {
        cout << "Height of the tree is: " << height(root) << endl;
    }

};

int main()
{
    BST tree;
    tree.insertdata(50);
    tree.insertdata(30);
    tree.insertdata(20);
    tree.insertdata(40);
    tree.insertdata(70);
    tree.insertdata(60);
    tree.insertdata(80);
    tree.displayPreorder();
    tree.displayInorder();
    tree.displayPostorder();
    tree.deleteNode(20);
    tree.displayPreorder();
    tree.displayInorder();
    tree.heightT();
    
    return 0;
}
