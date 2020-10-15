#include <iostream>
#include <fstream>
#include <stack>
#include <stdlib.h>
using namespace std;
struct node 
{ 
     
    int data; 
    node* left; 
    node* right; 
}; 

node* newNode(int data); 
void printInorder (node* node) ;
node* buildTree (int inorder[], int start, int end); 
void printInorder (node* node) ;
void printPreorder(node* node);
int mid (int arr[], int strt, int end) ;
void printPostorder(node* node);
int HeightOfTree(struct node *root);
void Print_Level_Left_To_Right(struct node *root, int level);
void Print_Level_Right_To_Left(struct node *root, int level);
void printReverseZigZag(struct node *root);

void binaryTreeToBST(node* root);
void arrayToBST(int* arr,  node* root, int* index_ptr);
int countNodes( node* root);
void storeInorder(node* node, int inorder[], int* index_ptr);
int compare(const void* a, const void* b);
void Inordertraversal(struct node* node, int inorder[], int *index_ptr);



int mid (int arr[], int strt, int end) 
{ 
    int i;
    i=end-strt;
    if(i%2 == 0)
    {
        i=i/2;
    }
    else{
    
    i=i/2 +1;
    
    }
    return strt + i; 
} 
node* buildTree (int inorder[], int start, int end) 
{ 
    if (start > end) 
        return NULL; 
int i = mid (inorder, start, end); 
 node *root = newNode(inorder[i]); 

    if (start == end) 
        return root; 
root->left = buildTree (inorder, start, i - 1); 
    root->right = buildTree (inorder, i + 1, end); 

    return root; 
} 

node* newNode (int data) 
{ 
    node* Node = new node(); 
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 

    return Node; 
} 





void printInorder (node* node) 
{ 
    if (node == NULL) 
        return; 

   printInorder (node->left); 

    cout<<node->data<<" "; 

    printInorder (node->right); 
    return ;
} 

void printPreorder(node* node)
{
    if (node == NULL) 
    {
        return; 
    }
   cout<<node->data<<" "; 
   printPreorder (node->left); 
   printPreorder (node->right); 
   return ;

}

void printPostorder(node* node)
{
    
    if (node == NULL) 
    {
        return; 
    }
    
    printPostorder (node->left); 
    printPostorder (node->right); 
    cout<<node->data<<" ";
    return ;

}







   
 
int main()
{
    int data[10000];
    ifstream myfile;
    myfile.open("a.txt");
int i=0;
    while(1)
    { 
    	myfile >> data[i];
    	if(data[i]==-1)
    	{
    		break;
    	}
    	i++;
    }
    i--;
    for(int j=0 ; j<=i ; j++)
    {
    	cout<<data[j]<<" ";
    }
    
    int inorder[i];
    for(int j=0 ; data[j]!=-1 ; j++)
    {
        inorder[j]=data[j];
    }
    cout<<'\n';
     node *root = buildTree(inorder, 0, i);

     cout<<"Which tree traversal do you want to print \n enter 1 for inorder traversal \n enter 2 for preorder \n enter 3 for postorder \n enter 4 for ReverseZigZag \n enter 5 for binary tree to BST \n enter 0 for terminating "<<"\n";
     int which;
     
     while(1)
     {
     	cin>>which;

     if(which == 1)
     {
     	cout << "Inorder traversal of the constructed tree is \n"; 
        printInorder(root);
        cout<<"\n";
     }
     else if(which == 2)
     {
     	cout << "Preorder traversal of the constructed tree is \n"; 
       printPreorder(root);
       cout<<'\n' ;

     }
     else if(which == 3)
     {
     	cout << "Postorder traversal of the constructed tree is \n"; 
       printPostorder(root);
       cout<<'\n'; 

     }
     else if(which == 4)
     {
     	cout << "\nReverseZigZag order traversal of the constructed tree is \n"; 
        printReverseZigZag(root);
        cout<<'\n' ;

     }

     else if(which == 5)
     {
     	cout << "\nBST of the following binary tree is \n"; 
        binaryTreeToBST(root);
        cout<<'\n' ;

     }
     else if(which == 0)
     {
     	break;
     }

     }




    //  cout << "Inorder traversal of the constructed tree is \n"; 
    // printInorder(root);

    
    // cout << "\nzigzagrder traversal of the constructed tree is \n"; 
    // zizagorder(root);
    // cout<<'\n' ;


    // cout<<'\n' ;
    // cout << "Prerder traversal of the constructed tree is \n"; 
    // printPreorder(root);
    // cout<<'\n' ;
    // cout << "Postrder traversal of the constructed tree is \n"; 
    // printPostorder(root);
    // cout<<'\n'; 

    

	return 0;
}


void Print_Level_Left_To_Right(struct node *root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        cout << root->data << " ";

    else if (level > 1)
    {
        Print_Level_Left_To_Right(root->left, level - 1);
        Print_Level_Left_To_Right(root->right, level - 1);
    }
}
void Print_Level_Right_To_Left(struct node *root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        cout << root->data << " ";

    else if (level > 1)
    {
        Print_Level_Right_To_Left(root->right, level - 1);
        Print_Level_Right_To_Left(root->left, level - 1);
    }
}

int HeightOfTree(struct node *root)
{
    if (root == NULL)
        return 0;

    // Compute the height of each subtree
    int lheight = HeightOfTree(root->left);
    int rheight = HeightOfTree(root->right);

    // Return the maximum of two
    return max(lheight + 1, rheight + 1);
}

void printReverseZigZag(struct node *root)
{
    // Flag is used to mark the change
    // in level
    int flag = 1;

    // Height of tree
    int height = HeightOfTree(root);

    for (int i = height; i >= 1; i--)
    {

        // If flag value is one print nodes
        // from right to left
        if (flag == 1)
        {
            Print_Level_Right_To_Left(root, i);

            // Mark flag as zero so that next time
            // tree is traversed from left to right
            flag = 0;
        }

        // If flag is zero print nodes
        // from left to right
        else if (flag == 0)
        {
            Print_Level_Left_To_Right(root, i);

            // Mark flag as one so that next time
            // nodes are printed from right to left
            flag = 1;
        }
    }
}

void arrayToBST (int *arr, struct node* root, int *index_ptr){
   if (root == NULL)
      return;
   arrayToBST (arr, root->left, index_ptr);
   root->data = arr[*index_ptr];
   (*index_ptr)++;
   arrayToBST (arr, root->right, index_ptr);
}

void binaryTreeToBST(node* root) 
{ 
	if (root == NULL) 
		return; 

	int n = countNodes(root);
   int *arr = new int[n];
   int i = 0;
   Inordertraversal(root, arr, &i);
   qsort(arr, n, sizeof(arr[0]), compare);
   i = 0;
   arrayToBST (arr, root, &i);
   delete [] arr;
   
}

int countNodes(struct node* root){
   if (root == NULL)
      return 0;
   return countNodes (root->left) +
   countNodes (root->right) + 1;
}

void Inordertraversal(struct node* node, int inorder[], int *index_ptr){
   if (node == NULL)
      return;
   Inordertraversal(node->left, inorder, index_ptr);
   inorder[*index_ptr] = node->data;
   (*index_ptr)++;
   Inordertraversal(node->right, inorder, index_ptr);
}

int compare(const void* a, const void* b) 
{ 
	return (*(int*)a - *(int*)b); 
}