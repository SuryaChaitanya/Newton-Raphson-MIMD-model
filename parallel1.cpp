#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>
#include<fstream>
#include<ctime>
#define N 10
#define degree 8	//
using namespace std;

pthread_t processor[N+1];
double arr[5];
int a=-8, b=8, r=10;
double root=INFINITY;
double c=0.00001;
double s=(b-a)/(N+1);
double s_time;
int func[degree]={8,0,0,0,0,17,0,1};
int func_dir[degree];

void deri()
{
	func_dir[0]=0;
	for(int i=1;i<degree;i++ )
	{
		func_dir[i]=func[i-1]*(degree-i);
	}
}
float f(int func[], float x)
{
	double sol=0;
	for(int i=0;i<degree;i++)
	sol+=func[i]*pow(x,degree-i-1);
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
			ofstream f;
			f.open("rootpara.txt");
			f<<"ROOT\tTIME\n";
			f<<root;
			f<<"\t";
			double t=(clock()-s_time)/(double)(CLOCKS_PER_SEC)*1000;
			f<<t;
			f.close();
			cout<<"\n The solution is saved in file "<<endl;
			exit(1);
		}
		x_old=x_new;
	}
	return (NULL);
}
int main()
{
	deri();
	cout<<clock()<<endl;

	for(int k=1;k<=N;k++) 
	{
		pthread_create(&processor[k], NULL, parallel_root, &k);
	}

	s_time=clock();
	for(int i=0;i<N;i++)
		pthread_join(processor[i],NULL);


	cout<<"-----The root is not saved in file-----\n";
	ofstream f;
	f.open("rootseq.txt");
	f<<"Couldn't find root";
	f.close();
	return 0;
}
