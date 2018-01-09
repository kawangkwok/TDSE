#include "header.h"

const double dx = 0.02;
const double dt=0.00005;
const int m = 200;
double p[201][2];
double p_s[201][2];
string s[20];
int u;

int main(){
  cout<<"Time?\n";
  cin>> u;
  time(u,s);
  
  initial(p);
  
  for(int i = 1 ; i<=u+1 ; i++){
    up(p_s, p);
    if(i%50){
    ofstream myfile;
    myfile.open (s[i/50]);
    for (int t = 0 ; t<=m ; t++){
      myfile <<t*dx<<","<< p_s[t][0]<<","<<p_s[t][1]<<","<<(p_s[t][0]*p_s[t][0])+(p_s[t][1]*p_s[t][1])<<"\n";
    };
    myfile.close();
    };
    for (int j =0;j<=m;j++){
      p[j][0] = p_s[j][0];
      p[j][1] = p_s[j][1];
    };
  };
};








