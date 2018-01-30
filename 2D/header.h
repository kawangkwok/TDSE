#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

extern const double dx;
extern const double dy;
extern const double dt;
extern const int m;

void time(int, string[20]);
void initial(double[201][201][2]);
void up(double[201][201][2], double[201][201][2]);
double potential(double,double);
