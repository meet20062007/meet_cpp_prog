// evaluate  from postfix
#include<iostream.h>
#include<conio.h>
#include<math.h>

class ev_postfix
{
		char *arr;
		int num_of_operands;
	public:
		ev_postfix(int);
		void input(int);
		void evaluate(int);

};
ev_postfix :: ev_postfix(int x)
{
	arr=new char[x+1];
}
void ev_postfix :: input(int x)
{
	do
	{
		int i;
		num_of_operands=0;
		clrscr();
		cout<<"\n Enter the expression :";
		for(i=0;i<x;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<x;i++)
		{
		      //	cout<<arr[i];
			if(arr[i]!='+' && arr[i]!='-' && arr[i]!='*' && arr[i]!='/' && arr[i]!='^')
			{
			num_of_operands++;
			}
		}
		if(num_of_operands+num_of_operands-x!=1)
		{
			cout<<"\n Enter a correct experssion";
			getch();
		}

	}while(num_of_operands+num_of_operands-x!=1);
}
void ev_postfix :: evaluate(int x)
{
	int stack[10];
	int i=0,j=-1;
	for(i=0;i<x;i++)
	{
		switch(arr[i])
		{
			case '+': stack[j-1] = stack[j-1] + stack[j];
				j--;
				break;
			case '-':stack[j-1] = stack[j-1] - stack[j];
				j--;
				break;
			case '*':stack[j-1] = stack[j-1] * stack[j];
				j--;
				break;
			case '/':stack[j-1] = stack[j-1] / stack[j];
				j--;
				break;
			case '^':stack[j-1] = pow(stack[j-1],stack[j]);
				j--;
				break;
			default:
				j++;
				stack[j]=arr[i]-48;
		}
	}
	cout<<endl<<"Ans="<<stack[0];
	getch();
}

void main()
{
	int i,j,n;
	do
	{
		clrscr();

		cout<<"Enter the size of the expression:";
		cin>>n;
		if(n==0)
		{
			cout<<"Enter correct size";
			getch();
		}
	}while(n==0);
	clrscr();

	ev_postfix p1(n);

	p1.input(n);
	p1.evaluate(n);


	getch();
}