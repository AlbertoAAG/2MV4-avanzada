#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>   /*sprintf()*/

using namespace std;
 
int main() {
  string filename = "Test.b";
  float d = 3.14;
  ofstream archivo(filename.c_str());
  char str[1000];
  sprintf(str,"%.02f %i %s\n",d,123,"abc");
  archivo<<str;
  archivo.close();
  
  // open file for reading
  std::ifstream istrm(filename.c_str());
  if (!istrm.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else { 
    std::string s;
    istrm>>s;
    float f=atof(&s[0]);
    istrm>>s;
    int i=atoi(&s[0]);
    istrm>>s;
    
    cout<<f<<" "<<i<<" "<<s<<endl;
  }
  string filename1 = "Prueba.txt";
  ofstream archivo1(filename1.c_str());
  string s1="pol:1/1:1/2:4/1";
  string s2="pol:1/1:3/2:4/1:5/4";
  archivo1<<s1<<endl;
  archivo1<<s2<<endl;
  archivo1.close();
  return 0;
}//end main()














