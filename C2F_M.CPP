// conversion from celcius to farenheit
#include<iostream.h>
#include<conio.h>

class degree_farenheit;
class degree_celcius
{
		float celcius;
	public:
		degree_celcius(float x)
		{
			celcius=x;
		}
		operator float()
		{
			float temp_f;
			temp_f=(9*celcius)/5+32;
			return(temp_f);
		}
		void show_celcius()
		{
			cout<<"celcius = "<<celcius<<endl;
		}
};
class degree_farenheit
{
		float farenheit;
	public:
		degree_farenheit(float y)
		{
			farenheit=y;
		}
		operator float()
		{
			float temp_c;
			temp_c=5*(farenheit-32)/9;
			return(temp_c);
		}
		void show_farenheit()
		{
			cout<<"farenheit = "<<farenheit<<endl;
		}
};
void main()
{
	float c,f;
	clrscr();

	cout<<"Input in celcius:";
	cin>>c;
	degree_celcius p1(c);

	float c_2_f=p1;
	degree_farenheit p2(c_2_f);
	p2.show_farenheit();

	cout<<"Input in farenheit:";
	cin>>f;
	degree_farenheit p3(f);

	float f_2_c=p3;
	degree_celcius p4(f_2_c);
	p4.show_celcius();

	getch();
}