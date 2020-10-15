#include <iostream>
#include <fstream>
using namespace std;
class node 
{ 
    public: 
    int data; 
    node* left; 
    node* right; 
}; 

node* newNode(int data); 
void printInorder (node* node) ;
node* buildTree (int inorder[], int start, int end); 
void printInorder (node* node) ;
int mid (int arr[], int strt, int end) ;
void printPostorder(node* node);


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
     cout << "Inorder traversal of the constructed tree is \n"; 
    printInorder(root);
    cout<<'\n' ;
    cout << "Postrder traversal of the constructed tree is \n"; 
    printPostorder(root);
    cout<<'\n'; 

    

	return 0;
}
