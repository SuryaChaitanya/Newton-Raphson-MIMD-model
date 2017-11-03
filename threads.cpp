#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>
#define N 6					//Number of processors

using namespace std;

pthread_t processor[N+1];	

int a=-4, b=4, r=10;		//(a,b) range and r = iteration
double root=INFINITY;		//ROOT=Infinity
double c=0.00001;			//percision

double s=(b-a)/(N+1);		


int func[]={0,1,-2,-2};
int func_dir[]={0,0,2,-2};

float f(int func[], float x)
{
	double sol=0;
	sol+=func[0]*pow(x,3);
	sol+=func[1]*pow(x,2);
	sol+=func[2]*pow(x,1);
	sol+=func[3];
	return sol;
}
void *parallel_root(void *p)
{
	
	int *k;
	k=(int *)p;
	
	double x_new, x_old;
	x_old=a+((*k)*s);

	int iteration=0;
	while(iteration<r && root==INFINITY)
	{
		iteration++;
		x_new=x_old-(f(func,x_old)/f(func_dir,x_old));
		if(abs(x_new-x_old)<c)
			{

					root=x_new;	
			}
		x_old=x_new;
	}
	
	return (NULL);

}

int main()
{
	cout<<"\n The solution is "<<endl;
	
	for(int k=1;k<=N;k++) 
	{
		pthread_create(&processor[k], NULL, parallel_root, &k);
	}

	for(int i=0;i<N;i++)
		pthread_join(processor[i],NULL);
	
	
}