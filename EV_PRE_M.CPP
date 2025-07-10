// evaluate  from prefix
#include<iostream.h>
#include<conio.h>
#include<math.h>

class ev_prefix
{
		char *arr;
		int num_of_operands;
	public:
		ev_prefix(int);
		void input(int);
		void evaluate(int);

};
ev_prefix :: ev_prefix(int x)
{
	arr=new char[x+1];
}
void ev_prefix :: input(int x)
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
void ev_prefix :: evaluate(int x)
{
	int stack[10];
	int i=0,j=-1;
	for(i=x-1;i>=0;i--)
	{
		switch(arr[i])
		{
			case '+': stack[j-1] = stack[j] + stack[j-1];
				j--;
				break;
			case '-':stack[j-1] = stack[j] - stack[j-1];
				j--;
				break;
			case '*':stack[j-1] = stack[j] * stack[j-1];
				j--;
				break;
			case '/':stack[j-1] = stack[j] / stack[j-1];
				j--;
				break;
			case '^':stack[j-1] = pow(stack[j],stack[j-1]);
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
		do
		{
			cout<<"Enter the size of the expression:";
			cin>>n;
				if(n%2!=1)
				{
					cout<<"Enter a correct size";
					getch();
				}
		}while(n%2!=1);

	}while(n==0);
	clrscr();

	ev_prefix p1(n);

	p1.input(n);
	p1.evaluate(n);


	getch();
}