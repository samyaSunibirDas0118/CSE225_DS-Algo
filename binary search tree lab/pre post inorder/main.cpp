#include <iostream>
using namespace std;

struct TreeNode
{
    int info;
    TreeNode *left;
    TreeNode *right;
};
TreeNode* Insert (TreeNode* root,int value);
bool Search(TreeNode* root, int value);
void PrintInorder(TreeNode* root);
void PrintPostOrder(TreeNode* root);
void PrintPreOrder(TreeNode* root);

int main(void)
{
    TreeNode *root = NULL;
    int count, input;
    cout <<"How many nodes ? ";
    cin >> count;
    cout <<"\nEnter nodes : ";
    for(int i=0; i<count; i++)
    {
        cin >> input;
        root = Insert(root, input);
    }
    cout <<"\nIn order Print : ";
    PrintInorder(root);
    cout <<endl;
    cout <<"\nPost Order Print : ";
    PrintPostOrder(root);
    cout <<endl;
    cout <<"Pre Order Print : ";
    PrintPreOrder(root);
    cout <<endl;

    return 0;
}
TreeNode* Insert(TreeNode* root, int value)
{
    if(root == NULL){
        TreeNode* newNode = new TreeNode;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->info = value;
        root = newNode;
    }
    else if(value <= root->info){
        root->left = Insert(root->left, value);
    }
    else{
        root->right = Insert(root->right, value);
    }
    return root;
}
void PrintInorder(TreeNode* root)
{
    if(root != NULL){
        PrintInorder(root->left);
        cout <<root->info<<"-->";
        PrintInorder(root->right);
    }
}
void PrintPostOrder(TreeNode* root)
{
    if(root != NULL){
        PrintPostOrder(root->left);
        PrintPostOrder(root->right);
        cout <<root->info<<"-->";
    }
}
void PrintPreOrder(TreeNode* root)
{
    if(root != NULL){
        cout <<root->info<<"-->";
        PrintPreOrder(root->left);
        PrintPreOrder(root->right);
    }
}
bool Search(TreeNode* root, int value)
{
    if(root == NULL)
        return false;
    else if(root->info == value)
        return true;
    else if(value <= root->info)
        return Search(root->left, value);
    else
        return Search(root->right, value);
}
