	// TREE PROGRAM
#include <iostream.h>
#include <conio.h>

class node
{


   public:
	int info;
	node* right;
	node* left;

   int get_info()
   {
      return info;
   }

   node()
   {
      info=0;
      right=NULL;
      left=NULL;
   }

   node(int x)
   {
      info=x;
      right=NULL;
      left=NULL;
   }

   ~node()
   {
      delete right;
      delete left;
      info=NULL;
   }

};

class tree
{
	public:
		node *root_node;

		void insert();
		void del();
		node* delete_rec(node*,int);
		node* find_min(node*);
		void search();
		int search_rec(node*,int);
		void disp_in();
		void inorder(node*);
		void disp_pre();
		void preorder(node*);
		void disp_post();
		void postorder(node*);


	tree()
	{
		root_node=NULL;
	}


};

void tree :: insert()
{
	int x,flag=0;

	cout<<"\n\tEnter the data to insert :";
	cin>>x;

	node *temp = new node(x);

	if(root_node==NULL)
	{
		root_node=temp;
		return;
	}
	node *curr=root_node;

	while(flag!=1)
	{
		if(x>curr->get_info())
		{
			if(curr->right==NULL)
			{
				curr->right=temp;
				flag=1;
			}
			else
			{
				curr=curr->right;
			}
		}
		else
		{
			if(curr->left==NULL)
			{
				curr->left=temp;
				flag=1;
			}
			else
			{
				curr=curr->left;
			}
		}
	}

}

void tree :: del()
{
	int x;
	cout<<"\nEnter data to delete";
	cin>>x;
	root_node=delete_rec(root_node,x);
	cout<<"\n the data is deleted (if it existed)";
	getch();
}

node* tree :: delete_rec(node* root,int key)
{
	if (root==NULL)
	return NULL;

	if(key<root->get_info())
	{
		root->left=delete_rec(root->left,key);
	}
	else if(key>root->get_info())
	{
		root->right=delete_rec(root->left,key);
	}
	else
	{
		if(root->left==NULL &&root->right==NULL)
		{
			delete root;
			return NULL;
		}
		else if(root->left==NULL)
		{
			node* temp=root->right;
			root->right=NULL;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			node* temp=root->left;
			root->left=NULL;
			delete root;
			return temp;
		}

		node* temp = find_min(root->right);
		root->info=temp->get_info();
	  //	root->right=delete_rec(root->right,temp->get_info());
	  //	root->left=root->left;
	    //	root->right=root->right;
	  //	root = new node(temp->get_info());

	   //	root->left=delete_rec(root->left,temp->get_info());
		root->right=delete_rec(root->right,temp->get_info());

	}
	return root;
}

node* tree :: find_min(node* curr)
{
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}

void tree :: search()
{
	int data;
	cout<<"\nEnter data to search";
	cin>>data;

	if(search_rec(root_node,data))
		cout<<"Data found in the tree";
	else
		cout<<"Data not fount in the tree";

	getch();
}

int tree :: search_rec(node *temp,int data)
{
	if (temp==NULL)
		return 0;

	if(temp->get_info()==data)
		return 1;

	if(data<temp->get_info())
		return search_rec(temp->left,data);
	else
		return search_rec(temp->right,data);
}

void tree :: disp_in()
{
	cout<<"Inorder : \n\t";
	inorder(root_node);
}

void tree :: inorder(node* temp)
{
	if (temp!=NULL)
	{
			inorder(temp->left);
			cout<<temp->get_info()<<" ";
			inorder(temp->right);
	}
}

void tree :: disp_pre()
{
	cout<<"Preorder Display :\n\t";
	preorder(root_node);
}

void tree :: preorder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->get_info()<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void tree :: disp_post()
{
	cout<<"Postorder Display :\n\t";
	postorder(root_node);
}

void tree :: postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->get_info()<<" ";
	}
}

void main()
{
   int n;
   tree obj;

   do{
       clrscr();
       cout<<"\n\t\t\t# Main Menu #\n";
       cout<<"\n\t 1.Insert";
       cout<<"\n\t 2.Delete";
       cout<<"\n\t 3.Search";
       cout<<"\n\t 4.Inorder Display";
       cout<<"\n\t 5.Preorder Display";
       cout<<"\n\t 6.Postorder Display";
       cout<<"\n\t 7.Exit";

       cout<<"\n\n\t Enter your choice: ";
       cin>>n;

	switch(n)
	{
	    case 1:
		   obj.insert();
		   break;

	    case 2:
		   obj.del();
		   getch();
		   break;

	    case 3:
		   obj.search();
		   break;

	    case 4:

		   obj.disp_in();
		   getch();
		   break;

	    case 5:
		   obj.disp_pre();
		   getch();
		   break;

	    case 6:
		   obj.disp_post();
		   getch();
		   break;

	    case 7:
		   break;


	    default:
		   cout<<"\n\tEnter an appropriate choice";
		   break;
	}
     }while(n!=7);

   getch();
	}