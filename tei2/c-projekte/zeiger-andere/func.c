#include<stdio.h>
// MACROS !!!!!
#define pi 3.14

void swap(float *a, float *b)
{
   float temp = *a;
   *a = *b;
   *b = temp;	

}
int main()
{
   float x = 4.0;
   float y;
  // ZEIGER DEKLAATION 
   float *z;
   float *zz;
   y = x*pi;
  // ZEIGER EIN ADRESSE ZUWEISEN 
   zz = &x;
   z = &y;
 
   printf("%f\n",y);
   printf("%f\n",*z);
 
  // FUNKTION AUFRUF SWAP GEHT NUR MIT ZEIGE SONST WIRD NUR EINE KOPIE WEITER GEGEBEN
   swap(z,zz);
  
   printf("%f , %f \n",x,y);
  // RETURN 0 IMMER WICHTIG FÜR SYSTEM ALS RÜCKGABEWERT
   return 0;


}
