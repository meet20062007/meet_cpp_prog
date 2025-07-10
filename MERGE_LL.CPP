/*
   Linked list
       -> Create node
       -> Create Linked List
       -> Insert
       -> Delete
       -> Display
       -> exit
*/

#include<iostream.h>
#include<conio.h>

class node
{
   int info;

   public:

   node *next;
   int get_info()
   {
      return info;
   }

   node()
   {
      info=0;
      next=NULL;
   }
   node(int x)
   {
      info=x;
      next=NULL;
   }
   ~node()
   {
      delete next;
      info=NULL;
   }
};

class linkedlist
{
   public:

   node *first,*last,*curr,*first2,*curr2,*last2;
   void menu_ins();
   void begin_ins();
   void aft_ins();
   void pos_ins();
   void menu_del();
   void display();
   void display2();
   void create_LL();
   void create_LL_2();
   void begin_del();
   void end_del();
   void data_del();
   void pos_del();
   void merge(linkedlist);
   void null_LL_2()
   {
   first2=last2=curr2=NULL;
   }
   linkedlist()
   {
      first=last=curr=NULL;
   }
   linkedlist(int y)
   {
      first2=curr2=last2=NULL;
   }

};

void linkedlist :: create_LL()
{
   int x;

   cout<<"\n\t Enter Data: ";
   cin>>x;

   node *temp = new node(x);

   if(first==NULL)
    first=temp;
   else
     last->next=temp;

     last=temp;
     cout<<"\n\t Data entered successfully...";
     display();
}
void linkedlist :: create_LL_2()
{
   int x;

   cout<<"\n\t Enter Data: ";
   cin>>x;

   node *temp = new node(x);

   if(first2==NULL)
    first2=temp;
   else
     last2->next=temp;

     last2=temp;
     cout<<"\n\t Data entered successfully...";
     display2();
}


void linkedlist :: aft_ins()
{
   int x;

   cout<<"\n\t Enter data: ";
   cin>>x;

   node *temp = new node(x);
   curr=first;

   cout<<"\n\t After which data you want to add: ";
   cin>>x;

   while(curr->get_info()!=x && curr->next!=NULL)
     curr=curr->next;

   if(curr->next==NULL && curr->get_info()!=x)
   {
      cout<<"\n\t Data not found...";
      getch();
      return;
   }
   else if(curr->next==NULL)
   {
      curr->next=temp;
      last=temp;
   }
   else
   {
      temp->next=curr->next;
      curr->next=temp;
   }

   cout<<"\n\t Data inserted succefully...";
   display();
}

void linkedlist :: pos_ins()
{
   int x,pos;

   cout<<"\n\t Enter data: ";
   cin>>x;

   node *temp = new node(x);

   curr=first;

   cout<<"\n\tEnter position no.: ";
   cin>>pos;
   for(int i=1;i<pos-1 && curr->next!=NULL;i++)
     curr=curr->next;

     if(curr->next==NULL&&i!=pos-1)
     {
	cout<<"\n\t Position invalid...";
	getch();
	return;
     }
     else if(curr->next!=NULL)
     {
       temp->next=curr->next;
       curr->next=temp;
     }

     if(i==pos-1)
     {
	 if(first==NULL)
	   first=temp;
	 else
	   last->next=temp;

	 last=temp;
     }
     cout<<"\n\t Data inserted succefully...";
     display();
}

void linkedlist :: menu_ins()
{
   int n;

   do{
       clrscr();
       cout<<"\n\t\t\t# Insert Menu #\n";
       cout<<"\n\t 1.Begin Insert";
       cout<<"\n\t 2.End Insert";
       cout<<"\n\t 3.After Data Insert";
       cout<<"\n\t 4.Specific Position Insert";
       cout<<"\n\t 5.Exit";
       cout<<"\n\n\t Enter your choice: ";
       cin>>n;

       switch(n)
       {
	  case 1:
		   begin_ins();
		   break;

	  case 2:
		   create_LL();
		   break;

	  case 3:
		   aft_ins();
		   break;

	  case 4:
		   pos_ins();
		   break;
	  case 5:
		   break;

	  default :
		   cout<<"\n\t Enter an appropriate choice";
		   getch();

       }
     }while(n!=5);

   getch();

}

void linkedlist :: begin_ins()
{
   int x;

   cout<<"\n\t Enter data: ";
   cin>>x;

   node *temp = new node(x);

     temp->next=first;
     first=temp;

    if(last==NULL)
       last=temp;

   cout<<"\n\t Data inserted successfuly...";
   display();
}

void linkedlist :: display()
{
     if(first==NULL)
     {
       cout<<"\n\t List 1 is empty";
       getch();
       return;
     }

     node *curr = new node(0);

     curr=first;
     cout<<"\n\n\t\t";
     cout<<"\LL 1:";
     while(curr!=NULL)
     {
	cout<<" "<<curr->get_info();
	curr=curr->next;
     }
getch();
}
void linkedlist :: display2()
{
     if(first2==NULL)
     {
       cout<<"\n\t List 2 is empty";
       getch();
       return;
     }

     node *curr2 = new node(0);

     curr2=first2;
     cout<<"\n\n\t\t";
     cout<<"\LL 2:";
     while(curr2!=NULL)
     {
	cout<<" "<<curr2->get_info();
	curr2=curr2->next;
     }
   getch();
}

void linkedlist :: menu_del()
{
   int n;

  do{
       clrscr();
       cout<<"\n\t\t\t# Delete Menu #\n";
       cout<<"\n\t 1.Begin Delete";
       cout<<"\n\t 2.End Delete";
       cout<<"\n\t 3.Specific Data Delete";
       cout<<"\n\t 4.Specific Position Delete";
       cout<<"\n\t 5.Exit";
       cout<<"\n\n\t Enter your choice: ";
       cin>>n;

       switch(n)
       {
	  case 1:
		   begin_del();
		   break;

	  case 2:
		   end_del();
		   break;

	  case 3:
		   data_del();
		   break;

	  case 4:
		   pos_del();
		   break;
	  case 5:
		   break;

	  default :
		   cout<<"\n\t Enter an appropriate choice";
		   getch();
     }
   }while(n!=5);

}

void linkedlist :: begin_del()
{
   node *temp = new node;
   temp=first;
   first=temp->next;
   cout<<"\n\n\t\t This '"<<temp->get_info()<<"' is deleted...";
   getch();
}

void linkedlist :: end_del()
{
   node *temp = new node;
   node *curr = new node;
   curr=first;

   while(curr->next!=last)
      curr=curr->next;
   temp=last;
   last=curr;
   last->next=NULL;
   cout<<"\n\n\t\t '"<<temp->get_info()<<"' is deleted...";
   getch();
}

void linkedlist :: data_del()
{
   int n;

   cout<<"\n\n\t Enter data to delete: ";
   cin>>n;

   node *curr = new node;
   node *temp = new node;

   if(first->get_info()==n)
   {
     begin_del();
     curr=first;
     return;
   }
   if(last->get_info()==n)
   {
     end_del();
     curr=first;
     return;
   }
   curr=first;

   while(curr->next->get_info()!=n && curr->next->next!=NULL)
      curr=curr->next;

   if(curr->next->next==NULL)
   {
      cout<<"\n\n\t Data No Found...";
      return;
   }

   temp=curr->next;
   curr->next=temp->next;
   cout<<"\n\n\t\t This '"<<temp->get_info()<<"' is deleted...";
   getch();
}

void linkedlist :: pos_del()
{
   int n;

   node *curr = new node;
   node *temp = new node;

   cout<<"\n\n\t Enter position to delete: ";
   cin>>n;

   curr=first;
   for(int i=1;i<n && curr->next!=NULL;i++)
      curr=curr->next;

   if(curr->next==NULL)
   {
      cout<<"\n\n\t Data No Found...";
      return;
   }
   temp=curr->next;
   curr->next=temp->next;
   cout<<"\n\n\t\t This '"<<temp->get_info()<<"' is deleted...";

   getch();
}
void linkedlist :: merge(linkedlist x1)
{

	if(first==NULL)
	{
	    cout<<"List 1 empty cannot merge";
	   getch();
	   return;
	}
	else if(x1.first2==NULL)
	{
	   cout<<"List 2 empty cannot merge";
	   getch();
	   return;
	}
	else
	{
	   last->next=x1.first2;
	   last=x1.last2;
	   last->next=NULL;
	   cout<<"Merge successfully";
	   getch();
	   null_LL_2();
	   display();
//	   x1.first1=x1.curr1=x1.last1=NULL;
	}
}

void main()
{
   int n;
   linkedlist obj;
   linkedlist obj2(0);

   do{
       clrscr();
       cout<<"\n\t\t\t# Main Menu #\n";
       cout<<"\n\t 1.Create Linked List 1";
       cout<<"\n\t 2.Create Linked List 2";
       cout<<"\n\t 3.Insert";
       cout<<"\n\t 4.Delete";
       cout<<"\n\t 5.Display";
       cout<<"\n\t 6.Merge";
       cout<<"\n\t 7.Exit";


       cout<<"\n\n\t Enter your choice: ";
       cin>>n;

	switch(n)
	{
	    case 1:
		  obj.create_LL();
		   break;

	    case 2:
		   obj2.create_LL_2();
		   break;

	    case 3:
		   obj.menu_ins();
		   break;

	    case 4:
		   obj.menu_del();
		   break;

	    case 5:
		   obj.display();
		   break;

	    case 6:
		   obj.merge(obj2);
		   break;

	    case 7:

	    default:
		   cout<<"\n\tEnter an appropriate choice";
		   break;
	}
     }while(n!=7);

   getch();
}