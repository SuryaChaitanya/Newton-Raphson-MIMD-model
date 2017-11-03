#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

#define N 5
using namespace std;
double arr[5];

float f(int func[], float x)
{
	double sol=0;
	sol+=func[0]*pow(x,3);
	sol+=func[1]*pow(x,2);
	sol+=func[2]*pow(x,1);
	sol+=func[3];
	return sol;
}

void main_function(int func[], int func_dir[], int a,int b,double c,int r, double root)
{
	
	double s=(b-a)/(N+1);
	double x_new, x_old;
	for(int k=0;k<N;k++)
	{
		x_old=a+(k*s);
		root=INFINITY;
		int iteration=0;
		while(iteration<r && root==INFINITY)
		{
			iteration++;
			x_new=x_old-(f(func,x_old)/f(func_dir,x_old));
			if(abs(x_new-x_old)<c)
				{
					root=x_new;
					cout<<root<<"\t";
					exit(1);
				}
			x_old=x_new;
			
		}
		//arr[k]=root;

	}
}

int main()
{
	// f(x)  = x3 -  0  - 4x - 5;
	// f'(x) = 0x3 + 3x2 +0  - 4     
/*	cout<<"Enter the f(x) [in the format a,b,c,d whereax^3+bx^2+cx+d]  :: ";
	for(int i=0;i<4;i++)
		cin>>func[i];
	cout<<"Enter the f'(x) [in the format a,b,c,d whereax^3+bx^2+cx+d] :: ";
	for(int i=0;i<4;i++)
	cin>>func_dir[i];
	
	
*/

/*
	int a,b;
	float c;
	int r;
	cin>>a>>b>>c>>r;
*/
	int func[]={1,0,-4,5};
	int func_dir[]={0,3,0,-4};

	//int func[]={0,0,}
	int a=-3;
	int b=3;
	double c=0.000001;
	int r=10;
	main_function(func, func_dir, a,b,c,r,INFINITY);
	//for(int i=0;i<5;i++)
		//cout<<arr[i]<<endl;


}