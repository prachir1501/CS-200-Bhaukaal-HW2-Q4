#include <iostream>
#include <fstream>
#include <stack>
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
void printPreorder(node* node);
int mid (int arr[], int strt, int end) ;
void printPostorder(node* node);

void zizagorder(struct node* root);

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

void zizagorder(struct node* root) 
{ 
    if (!root) 
    { 
     return; 
    }
    stack<struct node*> currentlevel; 
    stack<struct node*> nextlevel; 
    currentlevel.push(root); 
    bool lefttoright = true; 
    while (!currentlevel.empty()) { 
  
         
        struct node* temp = currentlevel.top(); 
        currentlevel.pop(); 
  
         
        if (temp) { 
  
            
            cout << temp->data << " "; 
  
             
            if (lefttoright) { 
                if (temp->left) 
                    nextlevel.push(temp->left); 
                if (temp->right) 
                    nextlevel.push(temp->right); 
            } 
            else { 
                if (temp->right) 
                    nextlevel.push(temp->right); 
                if (temp->left) 
                    nextlevel.push(temp->left); 
            } 
        } 
  
        if (currentlevel.empty()) { 
            lefttoright = !lefttoright; 
            swap(currentlevel, nextlevel); 
        } 
    } 
    return ;
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

     cout<<"Which tree traversal do you want to print \n enter 1 for inorder traversal \n enter 2 for preorder \n enter 3 for postorder \n enter 4 for zigzagorder"<<"\n";
     int which;
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
     	cout << "\nzigzagrder traversal of the constructed tree is \n"; 
        zizagorder(root);
        cout<<'\n' ;

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
