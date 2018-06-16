#include <iostream>
//#include "Rac.h"
#include "Polinomio.h"
using namespace std; /*cout*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void presentar(Polinomio& Pfpiv,    /*Polinomio fila pivote*/
               Rac &Rfactor1,       /*Racianal factor1*/
			   Polinomio& Pfpivc1,  /*Polinomio fila pivote c/ elemento pivote 1*/
			   Polinomio& Pnfpiv,   /*Polinomio no fila pivote*/
			   Rac &Rfactor2,       /*Racianal factor2*/
			   Polinomio& Pnfpivc0);/*Polinomio no fila pivote con 0 arriba o abajo del 1*/

#define INITIAL_PROOF
#define SECOND_PROOF
#ifdef CLASE_LUNES
int main(int argc, char** argv) {
#ifdef INITIAL_PROOF
	Rac rac1;rac1.n=-30;rac1.d=60;rac1.mcd=30;
	Rac rac2=rac1+rac1+rac1;
	cout<<"rac1="<<endl<<rac1;
	cout<<"mcd="<<rac1.calc_mcd()<<endl;
	rac1.simplificar();
	cout<<"rac1 simplificado="<<endl;
	cout<<rac1;
	cout<<"rac2="<<endl<<rac2<<endl;
	Rac rac3=rac1+rac2;
	cout<<"rac3="<<endl<<rac3<<endl;
//	int A=2;int& a=A;
	Rac sum=rac1+2;
	cout<<"sum="<<sum<<endl;
	Rac sum1=3+rac1;
	cout<<"sum1="<<sum1<<endl;
	
	Rac *RacPt=new Rac[3];
	*(RacPt+0)=rac1;
	*(RacPt+1)=rac2;
	*(RacPt+2)=rac3;
	Polinomio P(2,RacPt);
	cout<<"P="<<endl<<P<<endl;
	Polinomio Q=P+P; 
	cout<<"Q=P+P"<<endl<<Q<<endl;
	Rac Rac_PT1[]={Rac(60,1),Rac(40,1),Rac(50,1),Rac(0,1),Rac(-1,1),Rac(0,1),Rac(1,1),Rac(100,1)};
	Rac *f1=new Rac(1,2);
	Polinomio PFactor1(0,f1);
	Polinomio& Pfactor1=PFactor1;
	Polinomio pnfpiv(7,Rac_PT1);
	Polinomio Ptmp=pnfpiv*Pfactor1;
	Polinomio& Pfpivc1=Ptmp;
	cout<<Pfpivc1<<endl;
#endif /*INITIAL_PROOF*/
#ifdef SECOND_PROOF
	Rac RacPT1[]={Rac(60,1),Rac(40,1),Rac(50,1),Rac(0,1),
	              Rac(-1,1),Rac(0,1),Rac(1,1),Rac(100,1)};
	Rac *factor1=new Rac(1,50);
	
	
	Rac *factor2=new Rac(-67,1);
	Rac RacPT[]={Rac(57,1),Rac(52,1),Rac(67,1),Rac(-1,1),
	             Rac(0,1),Rac(1,1),Rac(0,1),Rac(300,1)};
	
	Polinomio PFactor1(0,factor1);
	Polinomio pfpiv(7,RacPT1),pnfpiv(7,RacPT);
	cout<<"pfpiv="<<endl;
	cout<<pfpiv<<endl;
	Polinomio& Pfactor1=PFactor1;
	
	Polinomio Ptmp=pfpiv*Pfactor1;
	Polinomio& Pfpivc1=Ptmp;
	cout<<"Pfpivc1="<<endl;
	cout<<Pfpivc1<<endl;
	
	Polinomio PFactor2(0,factor2);
	Polinomio& Pfactor2=PFactor2;
	Polinomio Ptmp1=Pfpivc1*Pfactor2;
	Polinomio Ptmp2=pnfpiv+Ptmp1;
	Polinomio& Pnfpivc0=Ptmp2;
#define AVANCE
#ifdef AVANCE	
	presentar(pfpiv,     /*Polinomio fila pivote*/
               *factor1, /*Racianal factor1*/
			   Pfpivc1,  /*Polinomio fila pivote c/ elemento pivote 1*/
			   pnfpiv,   /*Polinomio no fila pivote*/
			   *factor2, /*Racianal factor2*/
			   Pnfpivc0);/*Polinomio no fila pivote con 0 arriba o abajo del 1*/
#endif /*AVANCE*/
#endif /*SECOND_PROOF*/
	return 0;
}
#endif //CLASE_LUNES
