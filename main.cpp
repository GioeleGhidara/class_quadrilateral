#include<iostream>

#include "CRectangle.h"
#include "CRhombus.h"

/*polimorfismo è tipo l'overloading degli operatori, una cosa polimorfa
nella prog ad oggetto è tipo con l'operatore uguale che ha piu significati(?)
*/
int main() {

	Quadrilateral *A, *B, *C; 
	float s1,s2,s3,s4;
	
	Rectangle rectA(10,5);
	Rectangle rectB(3,7);
	Rhombus rhoC(2,1);
	
	A = &rectA;
	/*puntatore della classe padre che punta ad un oggetta della classe figlio, poiché tutto quello che
	ha la classe figlio è anche della classe padre tramite ereditarietà. Eredita tutto quello che è
	public e quello che è virtual. Serve soprattutto per funzioni da mettere in classe padre e utilizzarlo nelle classi figlio 
	-> una sola funzione per tutte le classi figlio che ne fanno parte. ES: 
	void coloraArea (Quadrilateral *P) {...} 
	int main ()
	{
	colorArea (& rectA);
	colorArea (& rhoC);
	}	
	*/
	B = &rectB;
	C = &rhoC;

	cout << endl;
	cout << "**** quadrilateral A ****" << endl;
	/*chiamata al Dump di Quadrilateral, fa parte del meccanismo di ereditarietà*/
	A->Dump(); 			
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral C ****" << endl;
	C->Dump(); 
	cout << "**** ***** ****" << endl;
	
	cout << endl;
	cout << "**** rectangle A ****" << endl;
	/*chiamata del Dump a rectangle A*/
	rectA.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** rectangle B ****" << endl;
	rectB.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** rectangle C ****" << endl;
	rhoC.Dump(); 
	cout << "**** ***** ****" << endl;
	
	/*oggetti diversi ma uguali nei contenuti, infatti le chiamate a Dump() daranno medesimi risultati*/
	rectA = rectB; 
	
	cout << endl;
	cout << "**** quadrilateral A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	/*se chiamassi A->GetArea() non compilerebbe perché nella classe quadrilateral non esiste, essendo in rectangle
	infatti dovrei chiamare rectA.GetArea() per farla funzionare*/

	rectB.SetWidth(12);
	cout << endl;
	cout << "**** quadrilateral A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** quadrilateral B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	/*B è un quadrilatero essendo puntatore ad un rettangolo e GetSides fa parte delle proprietà del quadrilatero*/
	B->GetSides(s1,s2,s3,s4);
	cout << "rectangle B - sides:" << s1 << " " << s2 << " "<< s3 << " "<< s4 << endl; 
	
	C->GetSides(s1,s2,s3,s4);
	cout << "rhombus C - sides:" << s1 << " " << s2 << " "<< s3 << " "<< s4 << endl;
	
	rhoC.SetDiagL(8);
	C->GetSides(s1,s2,s3,s4);
	cout << "rhombus C - sides:" << s1 << " " << s2 << " "<< s3 << " "<< s4 << endl;

//	C->GetArea(); 
	
		
	
	return 0;

}