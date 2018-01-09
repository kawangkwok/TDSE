#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <complex>
#include <cmath>
#include <fstream>
using namespace std;


extern const double dx;
extern const double dt;
extern const double lambda;
extern const int m;
extern const double dx2;

void time(int, string[20]);
void initial(double[2001][2]);
double potential(double);
void ef_factor(double[2001][2],double[2001][2],double[2001][2]);
void update(double[2001][2],double[2001][2],double[2001][2]);
