#include "header.h"

void time(int t, string q[20]){
    for(int i=1;i<=(t/200);i++){
    string b = to_string(i*200);
    q[i] = b+ "pc.csv";
  };
};

void initial(double y[2001][2]) {
  double  a;
  const double  x_0 = 0.4;
  const double k=500;
  const double sigma = 0.001;
  double sum = 0;

  for(int j = 0 ; j <= m; j++){
    a = exp(-1.*(j*dx-x_0)*(j*dx-x_0)/sigma );
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
  myfile.open ("0pc.csv");
  for (int t = 0 ; t<=m ; t++){
    myfile <<t*dx<<","<< y[t][0]<<","<<y[t][1]<<","<<y[t][0]*y[t][0]+y[t][1]*y[t][1]<<"\n";
  };
  myfile.close();
};

double potential(double x){
  if(0.60000<=x){
    return-2* 125000;
  };
  return 0;
};


void ef_factor(double u[2001][2],double a[2001][2],double b[2001][2]){
  a[1][0] = 2 + 2 * dx2 * potential(dx);
  a[1][1] = - 2 * lambda;
  b[1][0] = - u[2][0] + (2*dx2*potential(dx)+2) * u[1][0] - (2*lambda * u[1][1]) - u[0][0];
  b[1][1] = - u[2][1] + (2*dx2*potential(dx)+2) * u[1][1] + (2*lambda * u[1][0]) - u[0][1];
  
  for (int i = 2 ; i<=m-1 ; i++){
    double emo = a[i-1][0]*a[i-1][0] + a[i-1][1]*a[i-1][1];
    a[i][0] = 2 + 2*dx2*potential(i*dx) - (a[i-1][0]/emo);
    a[i][1] = -2 * lambda + (a[i-1][1]/emo);
    b[i][0] = -u[i+1][0]+(2*dx2*potential(i*dx)+2)*u[i][0]-2*lambda*u[i][1]-u[i-1][0]+(b[i-1][0]*a[i-1][0]+b[i-1][1]*a[i-1][1])/emo;
    b[i][1] = -u[i+1][1]+(2*dx2*potential(i*dx)+2)*u[i][1]+2*lambda*u[i][0]-u[i-1][1]+(b[i-1][1]*a[i-1][0]-b[i-1][0]*a[i-1][1])/emo;
  };
};
 
void update(double p_new[2001][2],double a[2001][2], double b[2001][2]){
  double sum =0;
  double mod = a[m-1][0]*a[m-1][0]+a[m-1][1]*a[m-1][1];
  p_new[m-1][0] = -(b[m-1][0]*a[m-1][0] + b[m-1][1]*a[m-1][1])/mod;
  p_new[m-1][1] = -(b[m-1][1]*a[m-1][0] - b[m-1][0]*a[m-1][1])/mod;
  //p_new[m][0]=p_s[m][1]=p_new[0][0]=p_s[0][0]=p_new[m][1]=p_s[m][0]=p_new[0][1]=p_s[0][1]=0; //boundary condition

  for(int i=m-2 ; i>=1 ; i--){
    double  em = a[i][0]*a[i][0]+a[i][1]*a[i][1];
    p_new[i][0] = ( (p_new[i+1][0]-b[i][0]) * a[i][0] + (p_new[i+1][1]-b[i][1]) * a[i][1] )/em;
    p_new[i][1] = ( (p_new[i+1][1]-b[i][1]) * a[i][0] - (p_new[i+1][0]-b[i][0]) * a[i][1] )/em;
    
  };

  for (int q = 0 ; q <=m ; q++){
    sum = sum + p_new[q][0]*p_new[q][0]+p_new[q][1]*p_new[q][1];
  };
  sum=sqrt(sum);
  
  for (int w = 0 ; w <=m; w++){
    p_new[w][0]=p_new[w][0]/sum;
    p_new[w][1]=p_new[w][1]/sum;
  };
 
}
