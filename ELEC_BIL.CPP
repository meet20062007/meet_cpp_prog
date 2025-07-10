// electricity bill
#include<iostream.h>
#include<conio.h>

class bill
{
	private:
		char name;
		float units,n;
		float total;


	public:
		void input_and_calculation();
		void output();

};
void bill :: input_and_calculation()
{

	float temp,temp1;

		cout<<"\tEnter a name :\n\t";
		cin>>name;
		cout<<"\tnumber of units consumed :\n\t";
		cin>>units;


		if(units <= 100)
		{
			temp=units*60;
			total=temp+5000;
		}
		else if(units >100 && units <=300)
		{
			temp1=units-100;
			temp=temp1*80;
			temp=temp+6000;
			total=temp+5000;
		}
		else
		{
			temp1=units-300;
			temp=temp1*90;
			temp=temp+22000;
			temp=temp+5000;

			if(temp>=30000)
			{
				total=temp+(temp*0.15);
			}
		}

}

void bill :: output()
{
	cout<<"Name : "<<name<<endl;
	cout<<"Units Consumed : "<<units<<endl;
	cout<<"Total Rupees : "<<total/100<<endl<<endl<<endl;
}
void main()
{
	bill p1[5];
	int i,n;
	clrscr();

	cout<<"enter number of names you want to enter (max 5) :";
	cin>>n;
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		p1[i].input_and_calculation();
	}
	clrscr();
	for(i=0;i<n;i++)
	{
		p1[i].output();
	}
	getch();
}
