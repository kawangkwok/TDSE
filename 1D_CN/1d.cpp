#include "header.h"

const double dx=0.0005;
const double dt=2*dx*dx;
const double lambda = 2*dx*dx/dt;
const int m=2000;
double p[2001][2]; //psi
double e[2001][2];
double f[2001][2];
const double dx2 = dx*dx;
double p_s[2001][2];
int u;
string s[20];

int main(){
  cout<<"Time?\n";
  cin>> u;

  time(u,s);
  initial(p);
  
  for(int i =1 ; i<=u ; i++){
    ef_factor(p,e,f);
    update(p_s,e,f);
      for (int j = 0 ; j<=m ; j++){	
       	p[j][0]=p_s[j][0];
       	p[j][1]=p_s[j][1];
      };
  if((i%200)==0){
    ofstream myfile;
    myfile.open (s[i/200]);
    for (int t = 0 ; t<=m ; t++){
      myfile <<t*dx<<","<< p[t][0]<<","<<p[t][1]<<","<<p[t][0]*p[t][0]+p[t][1]*p[t][1]<<"\n";
    };
    myfile.close();	
      };
  };
  return 0;
}














