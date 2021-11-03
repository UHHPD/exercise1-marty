#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

#define charToInt(c) (c-'0')

int main() {
  ifstream fin("daten.txt");
  ofstream fout("datensumme.txt");

  if (fin.good())
  {
    string sLine;
    while (getline(fin, sLine))
    {
      int sum = 0;

      for (int i=0; i<sLine.length(); ++i)
      {
        if (isdigit(sLine[i]))
        {
          int a = charToInt(sLine[i]);
          sum = sum + a;
        }
      }

      fout << sum << endl;
    }
  }
  fin.close();
  fout.close();

  return 0;
}