#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
  ifstream fin("datensumme.txt");
  
  double sum = 0;
  double vsum = 0;
  string line;

  while (getline(fin, line)) {
    sum = sum + stod(line);
  }

  double mean = sum/234;
  cout << "The mean value is: " << mean << endl;
  fin.close();

  ifstream vfin("datensumme.txt");

  while (getline(vfin, line)) {
    vsum = vsum + pow((stod(line)-mean),2);
  }

  double var = vsum/234;
  double sigma = sqrt(var);
  cout << "The variance is: " << var << endl;
  cout << "The standard deviation is: " << sigma << endl;   
  vfin.close();

  return 0;
}