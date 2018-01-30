#include "header.h"


const double dx = 0.02;
const double dy = dx;
const double dt=0.00005;
const int m = 200;
double p[201][201][2];
double p_s[201][201][2];




int main(){
  int u;
  string s[20];
  cout<<"Time?\n";
  cin>> u;

  time(u,s);
  
  initial(p);
  for(int i = 1 ; i<=u+1 ; i++){
    up(p_s, p);
    if(i%50){
      ofstream myfile;
      myfile.open (s[i/50]);
      for (int i =0 ; i<=m ; i++){
	for (int t = 0 ; t<=m ; t++){
	  myfile <<i*dx<<","<<t*dy<<","<< p_s[i][t][0]<<","<<p_s[i][t][1]<<","<<(p_s[i][t][0]*p_s[i][t][0])+(p_s[i][t][1]*p_s[i][t][1])<<"\n";
	};
      };
      myfile.close();
    };
    for (int i = 0 ; i<=m ; i++){
      for (int j = 0 ; j<=m ; j++){
      p[i][j][0] = p_s[i][j][0];
      p[i][j][1] = p_s[i][j][1];
      };
    }; 
  }; 

  return 0;
};








