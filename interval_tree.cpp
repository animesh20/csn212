#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 
struct node
{
    int l,h,maxi;
    struct node *left, *right;
};
 

struct node *newNode(int l, int h)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->l = l;
    temp->h = h;
    temp->maxi=h;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->l<<":"<<root->h<<":"<<root->maxi<<" ";
        inorder(root->right);
    }
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct node* insert(struct node* node, int l, int h)
{
    if (node == NULL) return newNode(l,h);
    if (l < node->l)
        node->left  = insert(node->left, l, h);
    else
        node->right = insert(node->right,l, h);
	node->maxi=max(node->h,max((node->left==NULL)?0:node->left->maxi,
			   					  (node->right==NULL)?0:node->right->maxi));
    return node;
}
 

struct node* deleteNode(struct node* node, int l, int h)
{
    
    if (node == NULL) return node;
 
    
    if (l < node->l)
        node->left = deleteNode(node->left, l, h);
 
    else if (l > node->l)
        node->right = deleteNode(node->right,l,h);
 
    
    else if(l==node->l&&h==node->h)
    {
        
        if (node->left == NULL)
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
 
        
        struct node* temp = minValueNode(node->right);
 

        node->l = temp->l;
        node->h=temp->h;
        node->maxi=temp->maxi;
 
        node->right = deleteNode(node->right, temp->l,temp->h);
    }
    node->maxi=max(node->h,max((node->left==NULL)?0:node->left->maxi,
			   					  (node->right==NULL)?0:node->right->maxi));
    return node;
}


bool doOVerlap(int l1, int h1, int l2, int h2)
{
    if (l1 <= h2 && l2 <= h1)
        return true;
    return false;
}
 

void search(struct node* node, int l, int h)
{
    
    if (node == NULL) return;
 
    if (doOVerlap(node->l,node->h,l,h)){
    	cout<<node->l<<":"<<node->h<<endl;
    	return;
	}
        
 
    if (node->left != NULL && node->left->maxi >= l)
        search(node->left,l,h);
    search(node->right,l,h);
}
 

int main()
{
	int ch,l,h;
	struct node *root = NULL;
	while(true){
		cin>>ch>>l>>h;
		if(ch==1){
			root = insert(root,l,h);
			inorder(root);
		}
		else if(ch==2){
			root = deleteNode(root,l,h);
			inorder(root);
		}
		else if(ch==3){
			search(root,l,h);
		}
		else{
			break;
		}
		cout<<endl;
	}
	return 0;
}

