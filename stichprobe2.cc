#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  ifstream fin("datensumme.txt");
  ofstream fout("mittelwerte.txt");
  
  vector<double> mean(26);
  string line;

  for (int j = 0; j < 26; j++) {
    int i = 0;
    double sum = 0;

    while ((i < 9) && (getline(fin, line))) {
      sum = sum + stod(line);
      ++i;
    }

    mean[j] = sum/9;
    fout << mean[j] << endl;
  }
  fin.close();
  fout.close();

  ifstream vfin("datensumme.txt");
  ofstream vfout("varianzen.txt");

  for (int j = 0; j < 26; j++) {
    int i = 0;
    double vsum = 0;

    while ((i < 9) && (getline(vfin, line))) {
      vsum = vsum + pow((stod(line)-mean[j]),2);
      ++i;
    }

    double var = vsum/9;
    vfout << var << endl;
  }     
  vfin.close();
  vfout.close();

  ifstream inf("mittelwerte.txt");
  ifstream vinf("varianzen.txt");

  double msum = 0;
  double vvsum = 0;
  
  while (getline(inf, line)) {
    msum = msum + stod(line);
  }

  while (getline(vinf, line)) {
    vvsum = vvsum + stod(line);
  }

  double mmean = msum/26;
  double vmean = vvsum/26;
  cout << "The mean value is: " << mmean << endl;
  cout << "The variance is: " << vmean << endl;
  inf.close();
  vinf.close();

  return 0;
}