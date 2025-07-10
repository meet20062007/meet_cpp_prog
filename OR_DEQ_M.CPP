// Output Restricted De_Queue
#include<iostream.h>
#include<conio.h>

class ir_deq
{
		int *arr,size,f,r;
	public:
		ir_deq(int);
		void insert_from_front();
		void insert_from_rear();
		void delete_();
		void display();
};
ir_deq :: ir_deq(int n)
{
	f=-1;
	r=-1;
	arr=new int[n];
	size=n;
}
void ir_deq :: insert_from_front()
{
   /*	if(r!=-1 && arr[r-1]!=0)
	{
	cout<<arr[r-1]<<" is successfully deleted";
	arr[r]=0;
	r--;
	getch();
	}
	else
	{
	cout<<"De-Queue Underflow";
	getch();
	}       */
	if(f!=-1 && arr[f-1]==0)
	{
	cout<<"Enter the element : ";
	cin>>arr[f-1];
	f--;
	getch();
	}
	else
	{
	cout<<"De-Queue Overflow";
	getch();
	}

}
void ir_deq :: insert_from_rear()
{
	if(f==-1 && r==-1)
	f=r=0;

	if(r!=size)
	{
	cout<<"enter the element : ";
	cin>>arr[r];
	r++;
	}
	else
	{
	cout<<"De-Queue overflow";
	getch();
	}
}
void ir_deq :: delete_()
{

	if(f!=-1 && f!=r+1 && f!=size)
	{
	cout<<arr[f]<<" is successfully deleted";
	arr[f]=0;
	f++;
	getch();
	}
	else
	{
	cout<<"De-Queue Overflow";
	getch();
	}

}
void ir_deq :: display()
{
	int i,j;
	cout<<"front =>   ";
	for(i=0;i<r;i++)
	{
		cout<<arr[i]<<"   ";
	}
	cout<<"<= rear";
	getch();
}

void main()
{
	int elements,i,j,choice;
	clrscr();

	cout<<"Enter the no of the elements of de queue : ";
	cin>>elements;
	ir_deq p1(elements);

	do{
		clrscr();
		cout<<"\t\t\t1. Insert from front\n";
		cout<<"\t\t\t2. Insert from rear\n";
		cout<<"\t\t\t3. Delete \n";
		cout<<"\t\t\t4. Display\n";
		cout<<"\t\t\t5. Exit\n";
		cout<<"\t\t\t Enter your choice:";
		cin>>choice;

		switch(choice)
		{
			case 1:  p1.insert_from_front();
			break;

			case 2:  p1.insert_from_rear();
			break;

			case 3:  p1.delete_();
			break;

			case 4:  p1.display();
			break;

			case 5:
			break;
		}
		if(choice<=0 || choice>5)
		{
			cout<<"Enter a correct choice";
			getch();
		}

	}while(choice!=5);

	getch();
}