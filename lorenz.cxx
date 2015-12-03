#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

void f(double* , const int, const int, const double, double, double, double);

int main(){
  const double dt=0.001;
  const int a=10;
  const int b=28;
  const double c=8.0/3.0;
  double x,y,z;
  double k1[3]; //see Runge Kutta 
  double k2[3]; //3 dimensions since 3d problem
  double k3[3];
  double k4[3];
  const int T=100;
  const int N=T/dt;
  
  x=1;
  y=1;
  z=1;
  
  ofstream out("RungeJunge.txt");
  out << 0 << "\t" << x << "\t" << y << "\t" << z << endl; //don't forget to save the start value
  
  for(int i=0; i<N;i++){
    f(k1,a,b,c,x,y,z); //calculates k1
    f(k2,a,b,c,x+dt/2*k1[0],y+dt/2*k1[1],z+dt/2*k1[2]); //calculates k2
    f(k3,a,b,c,x+dt/2*k2[0],y+dt/2*k2[1],z+dt/2*k2[2]); //calculates k3
    f(k4,a,b,c,x+dt*k3[0],y+dt*k3[1],z+dt*k3[2]); //calculates k4
    
    x+=dt/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
    y+=dt/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
    z+=dt/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
  
  out << i*dt << "\t" << x << "\t" << y << "\t" << z << endl;
  }
  
  out.close();
    
  return 0;
}


void f(double* p, const int a, const int b, const double c, double x, double y, double z){
  p[0]=a*(y-x);
  p[1]=x*(b-z)-y;
  p[2]=x*y-c*z;
}