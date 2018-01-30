#include "header.h"


void time(int t, string q[20]){
  for(int i=1;i<=(t/50);i++){
    string b = to_string(i*50);
    q[i] = b+ "_2dleap.csv";
  };
}

double potential(double x,double y){
  return 0;
};


void initial(double y[201][201][2]) {
  double  a;
  const double  x_0 = 2.0;
  const double  y_0 = 2.0;
  const double kx = 40.00000;
  const double ky = 0;
  double sum = 0;
  //double sum2 = 0;

  for(int i = 0 ; i <= m; i++){
    for(int j = 0 ; j <= m; j++){
      a = exp(-1.*((i*dx-x_0)*(i*dx-x_0)/0.01 + (j*dy-y_0)*(j*dy-y_0)/0.01));
      y[i][j][0] = a * cos(kx*i*dx+ky*j*dy);
      y[i][j][1] = a * sin(kx*i*dx+ky*j*dy);
      };
    };
  for (int i = 0 ; i <= m ; i++){ 
    for (int q = 0 ; q <= m ; q++){
      sum = sum + y[i][q][0]*y[i][q][0]+y[i][q][1]*y[i][q][1];
    };
  };
  sum=sqrt(sum);

  for (int i = 0 ; i <= m; i++){
    for (int w = 0 ; w <= m; w++){
      y[i][w][0]=y[i][w][0]/sum;
      y[i][w][1]=y[i][w][1]/sum;
      // if (y[i][w][0] < 1E-200){
      // 	  y[i][w][0] = 0;
      // 	};
      // if (y[i][w][1] < 1E-200){
      // 	  y[i][w][1] = 0;
      // 	};
    };
  };

  
  ofstream myfile;
  myfile.open ("0_2dleap.csv");
  for (int i = 0 ; i<=m ; i++){
    for (int t = 0 ; t<=m ; t++){
      myfile <<i*dx<<","<<t*dy<<","<< y[i][t][0]<<","<<y[i][t][1]<<","<<y[i][t][0]*y[i][t][0]+y[i][t][1]*y[i][t][1]<<"\n";
    };
  };
  myfile.close();
};


void up(double p_new[201][201][2],double a[201][201][2]){
  //double sum=0;
  for(int i = 0 ; i<=m ; i++){
    p_new[i][m][0]=p_new[i][m][1]=p_new[m][i][0]=p_new[m][i][1]=0;
  };
  for (int i =1 ; i<=m-1 ; i++){
      for (int q =1 ;q<=m-1 ; q++){
	p_new[i][q][1] = a[i][q][1] + (dt/(2*dx*dx))*(a[i+1][q][0] - 2*a[i][q][0] + a[i-1][q][0]) + (dt/(2*dy*dy))*(a[i][q+1][0] - 2*a[i][q][0] + a[i][q-1][0]) - dt*potential(i*dx,q*dy)*a[i][q][0];
      };
    };
  for (int i = 1;i<=m-1 ;i++){
    for (int q = 1 ; q<=m-1 ; q++){
      p_new[i][q][0] = a[i][q][0] - (dt/(2*dx*dx))*(p_new[i+1][q][1] - 2*p_new[i][q][1] + p_new[i-1][q][1]) - (dt/(2*dy*dy))*(p_new[i][q+1][1] - 2*p_new[i][q][1] + p_new[i][q-1][1]) + dt*potential(i*dx,q*dy)*p_new[i][q][1];
    };
  };
};
