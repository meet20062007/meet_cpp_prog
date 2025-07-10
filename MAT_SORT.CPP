// Matrix Sorter

#include<iostream.h>
#include<conio.h>

int mat[50][50];
int mat_temp[50][50];
int flat_mat[2500];
class matrix
{
	public:
		int rows,cols;
		void inp_mat();
		void sort_row();
		void disp();
		void sort_col();
		void sort_matrix();
};

void matrix :: inp_mat()
{
	cout<<"\n\t Enter Number of rows: ";
	cin>>rows;
	cout<<"\n\t Enter Number of columns: ";
	cin>>cols;

	cout<<"Enter the matrix: \n";

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>mat[i][j];
		}
	}
}

void matrix :: sort_row()
{
	int temp;

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			mat_temp[i][j]=mat[i][j];
		}
	}

	for(i=0;i<rows;i++)
	{
		for(int j=0;j<cols-1;j++)
		{
			for(int k=0;k<cols-j-1;k++)
			{
				if(mat_temp[i][k]>mat_temp[i][k+1])
				{
					temp=mat_temp[i][k+1];
					mat_temp[i][k+1]=mat_temp[i][k];
					mat_temp[i][k]=temp;

				}
			}
		}
	}
	cout<<"\n\tRow wise sorted";
}

void matrix :: sort_col()
{
	int temp;

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			mat_temp[i][j]=mat[i][j];
		}
	}

	for(i=0;i<cols;i++)
	{
		for(int j=0;j<rows-1;j++)
		{
			for(int k=0;k<rows-j-1;k++)
			{
				if(mat_temp[k][i]>mat_temp[k+1][i])
				{
					temp=mat_temp[k+1][i];
					mat_temp[k+1][i]=mat_temp[k][i];
					mat_temp[k][i]=temp;

				}
			}
		}
	}


	cout<<"\n\tcolumn wise sorted";
}

void matrix :: sort_matrix()
{
	int temp,k=0;

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			flat_mat[k]=mat[i][j];
			k++;
		}
	}

	for(i=0;i<rows*cols-1;i++)
	{
		for(int j=0;j<rows*cols-i-1;j++)
		{
			if(flat_mat[j]>flat_mat[j	+1])
			{
				temp=flat_mat[j+1];
				flat_mat[j+1]=flat_mat[j];
				flat_mat[j]=temp;
			}
		}
	}
	k=0;

	for(i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			mat_temp[i][j]=flat_mat[k];
			k++;
		}
	}

	cout<<"\n\tMatrix sorted";
}

void matrix :: disp()
{
	cout<<"\n\t";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<mat_temp[i][j]<<"  ";
		}
		cout<<"\n\t";
	}
}


void main()
{
	clrscr();

	matrix obj;

	obj.inp_mat();
	obj.sort_row();
	obj.disp();
	obj.sort_col();
	obj.disp();
	obj.sort_matrix();
	obj.disp();

	getch();
}