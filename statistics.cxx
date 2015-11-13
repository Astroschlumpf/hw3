#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void fuellhorn(double* poi, int len){
  srand(time(NULL)); // planting seed - Anfang fuer zufaellige Zufallszahlen
  for(int i=0; i<len; i++){
    poi[i] = rand()/((double)RAND_MAX); // Zufallszahl auf [0,1] normiert
  }
}

double mittwe(double* poi, int len){
  double mwSu = 0;
  for(int i=0; i<len; i++){
    mwSu += poi[i]/((double)len); // Summe aus x[i]/N == 1/N * Summe fuer Mittelwert
  }
  return mwSu;
}

double varw(double* poi, int len, double miwe){
  double vasu = 0;
  for(int i=0; i<len; i++){
    // Varianz v = Summe ((x[i]-m)^2/N)
    vasu += (poi[i]-miwe)*(poi[i]-miwe)/((double)len);
  }
  return vasu;
}

int main(){
   const int N = 100;
   double p[N];
   double mean, var;
   
   fuellhorn(p,N); // Array mit Zufallszahlen fuellen
   mean = mittwe(p,N); // Mittelwert
   var = varw(p,N,mean); // Varianz aus Werten und Mittelwert
   ////////////////// Note: /////////////////////
    // Random is not random at all...
    // p[0] = 0.840188, p[1] = 0.394383 ...
    // for the first and every other time!!!
    // => mean and var will always be the exact
    // same values every time as well
    // Loesung: seed aus time(NULL) nutzen und
    // mit srand(time(NULL)) setzen (s.o.)
   //////////////////////////////////////////////
   
   // for(int i=0; i<N; i++){
   //   cout << p[i] << endl; // debug
   // }

   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}
