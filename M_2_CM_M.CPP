// conversion from metre to centimeter
#include<iostream.h>
#include<conio.h>

class cm;
class m
{
		float metre;
	public:
		m(float x)
		{
			metre=x;
		}
		operator float()
		{
			float temp_cm;
			temp_cm=100*metre;
			return(temp_cm);
		}
		void show_metres()
		{
			cout<<"metres = "<<metre<endl;
		}
};
class cm
{
		float centimetre;
	public:
		cm(float y)
		{
			centimetre=y;
		}
		operator float()
		{
			float temp_m;
			temp_m=centimetre/100;
			return(temp_m);
		}
		void show_centimetres()
		{
			cout<<"centimetres = "<<centimetre<<endl;
		}
};
void main()
{
	float met,cent;
	clrscr();

	cout<<"Input in metres:";
	cin>>met;
	m p1(met);

	float m_2_cm=p1;
	cm p2(m_2_cm);
	p2.show_centimetres();

	cout<<"Input in centimetres:";
	cin>>cent;
	cm p3(cent);

	float cm_2_m=p3;
	m p4(cm_2_m);
	p4.show_metres();

	getch();
}