/**
  @progName luis carlos 
  @desc pagina generada
  @author jose antonio hernandez  
  @date 11 febrero 2018
 */
#include <iostream>
using namespace std;

/**
  @funcName metodo mafer
  @desc atributo pepe
  @param mordida de mafer
  @return pepe y mafer
 */
int factorial(int iNum) {
	int iFac=1;
	// Calculate the factorial with a FOR loop
	for(int iC=1; iC<=iNum; iC++){
		iFac = iFac*iC;
		
	}
	return iFac; // This value is returned to caller
	
}
/**
 @funcName baia baia
 @desc sugar tititititi
 @return pepe y mafer
	 
	 */
int validaEntero(){
		int iNum;
	do{
			cout << "Numero ";
			cin >> iNum;
	}while (iNum < 1 || iNum > 10); return iNum;
}
/**
 @funcName ya se acabo
 @desc gran final 
 */
int main(){
		int iNumero, iResult; iNumero = validaEntero(); iResult = factorial(iNumero);
		cout << "Factorial = " << iResult << endl;
		return 0;
		
}
