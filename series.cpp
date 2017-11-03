#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#define degree 4    //Enter degree+1 value
#define N 6
using namespace std;
double root=INFINITY;

int a=-8;
int b=8;
double c=0.00001;
int r=10;
double s=(b-a)/(N+1);
double s_time;
double root_s;

int flag=0;
int func[degree]={1,0,-4,-5};
int func_dir[degree];

float f(int func[], float x)
{
   double sol=0;
   for(int i=0;i<degree;i++)
   sol+=func[i]*pow(x,degree-i-1);
   return sol;
}

void deri()
{
   func_dir[0]=0;
   for(int i=1;i<degree;i++ )
   {
       func_dir[i]=func[i-1]*(degree-i);
   }
}
void main_function(int func[], int func_dir[], int a,int b,double c,int r, double root)
{

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
          ofstream f;
          f.open("rootseq.txt");
          f<<root;
          f<<"\t";
          
          f.close();
          if(flag==0)
              {
                root_s=root; 
                flag=1;
              }
        }
     x_old=x_new;
    }
  }
}

int main()
{ 
    s_time=clock();
    deri();
    main_function(func, func_dir, a,b,c,r,INFINITY);

    double t=(clock()-s_time)/(double)(CLOCKS_PER_SEC)*1000;

    //cout<<"The root is not saved in file\n";
    ofstream f;

    f.open("rootseq.txt");
    f<<"ROOT\tTIME\n";
    if(flag==1)
        f<<root_s<<"\t"<<t;
    else
        f<<"Couldn't find root";
    f.close();
    return 0;
}