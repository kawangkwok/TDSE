#include "header.h"

void time(int t, string q[20]){
  for(int i=1;i<=(t/50);i++){
    string b = to_string(i*50);
    q[i] = b+ "leap.csv";
  };
};

double potential(double x){
  return 0;
};


void initial(double y[201][2]){
  double  a;
  const double  x_0 = 2.0;
  const double k=40.0000;
  double sum = 0;

  for(int j = 0 ; j <= m; j++){
    a = exp(-1.*(j*dx-x_0)*(j*dx-x_0)/0.01 );
    y[j][0] = a *cos(k*j*dx);
    y[j][1] = a *sin(k*j*dx);
  };
  
  for (int q = 0 ; q <=m; q++){
    sum = sum + y[q][0]*y[q][0]+y[q][1]*y[q][1];
  };
  sum=sqrt(sum);
  
  for (int w = 0 ; w <=m; w++){
    y[w][0]=y[w][0]/sum;
    y[w][1]=y[w][1]/sum;
  };
  
  ofstream myfile;
  myfile.open ("0leap.csv");
  for (int t = 0 ; t<=m ; t++){
    myfile <<t*dx<<","<< y[t][0]<<","<<y[t][1]<<","<<y[t][0]*y[t][0]+y[t][1]*y[t][1]<<"\n";
  };
  myfile.close();
};


void up(double p_new[201][2],double a[201][2]){
  for(int q =1 ;q<=m ; q++){
    p_new[q][1] = a[q][1] + (dt/(2*dx*dx))*(a[q+1][0] - 2*a[q][0] + a[q-1][0]) - dt*potential(q*dx)*a[q][0];
  };
  
  for(int i = 1;i<=m ;i++){
    p_new[i][0] = a[i][0] - (dt/(2*dx*dx))*(p_new[i+1][1] - 2*p_new[i][1] + p_new[i-1][1]) + dt*potential(i*dx)*p_new[i][1];
  };
  // for (int q = 0 ; q <=m ; q++){
  //   sum = sum + p_new[q][0]*p_new[q][0]+p_new[q][1]*p_new[q][1];
  // };
  // sum=sqrt(sum);
  
  // for (int w = 0 ; w <=m; w++){
  //   p_new[w][0]=p_new[w][0]/sum;
  //   p_new[w][1]=p_new[w][1]/sum;
  // };
};

