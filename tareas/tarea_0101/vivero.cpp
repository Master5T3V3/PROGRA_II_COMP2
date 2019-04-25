/*Programa desarrollado por Brian Steve Rodas Hernandez
	Carnet: RH18031
		Creacion de un programa que ejecute funciones de un vivero*/

///////////////////////////////////////////////////////////////////////////////////////////////////
//Definicion de librerias y parametros a utilizar dentro del codigo

#include <iostream> //Libreria de entradas y salidas
#include <stdlib.h> //Libreria de funciones adicionales
#include <queue> //Libreria de colas
#include <string.h> //Libreria de opciones para cadenas

using namespace std; //Simplificacion del codigo

///////////////////////////////////////////////////////////////////////////////////////////////////
//Desarrollo de clases a utilizar dentro del codigo

class Hoja { //Calse hoja a utilizar en clase arbol
	private:
		string forma; //Variable de forma de hoja
		
	public:
		Hoja() { //Constructor de la clase hoja
		}
		void setforma(string h) { //Setear forma de la hoja
			this->forma = h; //Asignar valor de la variable h
		}
		string getforma() { //Obtener valores
			return this->forma; //Retornar valor asignado a variable forma de la hoja
		}
		~Hoja() { //Destructor de la clase hoja
		}
};

class Tallo { //Clase tallo a utilizar en clase arbol
	private:
		float longitud; //Variable de longitud para el tallo
	
	public:
		Tallo() { //Constructor de la clase tallo
		}
		void setlongitud(float l) { //Setear longitud del tallo
			this->longitud = l; //Asignar valor de la variable l
		}
		float getlongitud() { //Obtener valores
			return this->longitud; //Retornar el valor asignado a longitud del tallo
		}
		~Tallo() { //Destructor de la clase
		}
};

class Arbol {     
	private:
		string nComun; //Variable de nombre comun
		string nomCient; //Variable de nombre cientifico
		string familia; //Variable de familia
		Hoja *hoja; //Informacion de hoja por medio de agregacion
		Tallo *tallo; //Informacion de tallo por composicion
		
	public:
		Arbol() { //Constructor de la clase principal arbol
			this->nComun; //Publicar variable de nombre comund
			this->nomCient; //Publicar variable de nombre cientifico
			this->familia; ////Publicar variable de famila
			this->hoja = new Hoja(); //Crear nueva hoja
			this->tallo = new Tallo(); //Crear nuevo tallo
		}	
		void setnComun(string com) { //Setear nombre comun
			this->nComun = com; //Obtener valor de la variable com
		}
		string getnComun() { //Obtener valores
			return this->nComun; //Retornar valor de nombre comun
		}
		void setnomCient(string cie) { //Setear nombre cientifico
			this->nomCient = cie; //Asignar valor de la variable cie
		}
		string getnomCient() { //Obtener valores
			return this->nomCient; //Retornar valor de nombre cientifico
		}
		void setfamilia(string fam) { //Setear familia
			this->familia = fam; //Asignar valor de la variable fam
		}
		string getfamilia() { //Obtener valores
			return this->familia; //Retornar valor de familia
		}
		void sethoja(string h) { //Setear forma de la hoja
			hoja->setforma(h); //Asignar valor de la variable h
		}
		string gethoja() { //Obtener valores
			return hoja->getforma(); //Retornar valor de la forma
		}
		void settallo(float l) { //Setear longitud del tallo
			tallo->setlongitud(l); //Asignar valor de la variable l
		}
		float gettallo() { //Obtener valores
			return tallo->getlongitud(); //Retornar valor de la longitud
		}
		~Arbol(){ //Destructor de la clase principal arbol
		}
};	
	
class ArbolFrutal:public Arbol { //Clase arbol frutal con paso de valores por herencia
	public:
		ArbolFrutal() { //Constructor de la clase arbol frutal
		}
		~ArbolFrutal() { //Destructor de la clase arbol frutal
		}
};
	
class ArbolOrnamental:public Arbol { //Clase arbol ornamental con paso de valores por herencia
	public:
		ArbolOrnamental() { //Constructor de la clase arbol ornamental
		}
		~ArbolOrnamental() { //Destructor de la clase arbol ornamental
		}
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//Prototipos de funciones para menu

void menu(); //Funcion para mostrar menu
int tomarINT(); //Funcion para tomar enteros
bool validINT(string); //Funcion para validar enteros
void select(); //Funcion para selecciones

///////////////////////////////////////////////////////////////////////////////////////////////////
//Desarrollo del codigo principal

int main() {
	queue <ArbolFrutal> colaAF; //Crear cola para frutales
	ArbolFrutal *af = new ArbolFrutal (); //Crear objeto de arbol frutal
	ArbolOrnamental *ao = new ArbolOrnamental (); //Crear objeto de arbol ornamental
	ArbolFrutal *p1; //Puntero frutal
	ArbolFrutal aux1; //Variable auxiliar frutal
	queue <ArbolOrnamental> colaAO; //Crear cola para ornamentales
	ArbolOrnamental *p2; //Puntero ornamental
	ArbolOrnamental aux2; //Variable auxiliar ornamental
	
	string com; //Variable de nombre comun
	string cie; //Variable de nombre cientifico
	string fam; //Variable de famila
	string h; //Variable de forma de hoja
	float t; //Variable de longitud de tallo;
	string dato; //Variable para hacer busqueda
	int opcM; //Variable para opcion de menu principal
	int opcS; //Variable para opcion de menu de seleccion
	
	do { //Ciclo para permitir unicamente las cinco opciones
		system("cls"); //Borrar pantalla de consola
		menu(); //Ejecutar funcion de menu visual
		opcM = tomarINT(); //Tomar dato de la opcion digitada
		system("cls"); //Borrar pantalla de consola
		
		switch(opcM) { //Switch con las opciones del menu
			case 1: //Agregar un nuevo arbol al vivero
				do { //Ciclo para permitir las dos opciones
					select(); //Ejecutar funcion de seleccion
					opcS = tomarINT(); //Tomar dato de la opcion digitada
					system("cls"); //Borrar pantalla de consola
					system("color 70"); //Cambiar colores, fondo blanco, texto negro
					
					if(opcS == 1) {//Si es un arbol frutal	
						//Pedir datos de arbol frutal
						cout << "\n\n\n\n\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese el nombre comun: ";
						cin >> com;
						af->setnComun(com);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese nombre cientifico: ";
						cin >> cie;
						af->setnomCient(cie);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese la familia: ";
						cin >> fam;
						af->setfamilia(fam);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese la forma de la hoja: ";
						cin >> h;
						af->sethoja(h);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese la longitud del tallo (cm): ";
						cin >> t;
						af->settallo(t);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						colaAF.push(*af); //Agregar conjunto de datos a la cola
					}
					
					else if(opcS == 2) { //Si es un arbol ornamental
						//Pedir datos de arbol ornamental
						cout << "\n\n\n\n\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese el nombre comun: ";
						cin >> com;
						ao->setnComun(com);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese nombre cientifico: ";
						cin >> cie;
						ao->setnomCient(cie);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese la familia: ";
						cin >> fam;
						ao->setfamilia(fam);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese la forma de la hoja: ";
						cin >> h;
						ao->sethoja(h);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Ingrese la longitud del tallo (cm): ";
						cin >> t;
						ao->settallo(t);
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						colaAO.push(*ao); //Agregar conjunto de datos a la cola
					}
					break;
				}
				while(opcS != 2); //Mientras sea diferente de las dos posibles opciones
				
				system("pause"); //Pausar pantalla de consola
				break;
						
			case 2: //Mostrar arboles en existencia
				if(colaAF.empty() == true) { //Si la cola esta vacia
					//Imprimir mensaje para indicar que la cola esta vacia
					cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t/ ###  No hay arboles frutales en existencia ### /" << endl;
					cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
				}
				else {
					p1 = &colaAF.front(); //Dirigirse al primer elemento
					//Imprimir titulo
					cout << "\n\n\n\t\t\t\t//////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t/    LISTADO DE ARBOLES FRUTALES EN EXISTENCIA   /" << endl;
					cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
					for(int i = 1; i <= colaAF.size(); i++) { //Generar ciclo para imprimir datos
						//Imprimir los arboles con sus respectivos datos
						aux1 = *p1;
						cout << "\n\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Nombre del Arbol: " << aux1.getnComun() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Nombre Cientifico: " << aux1.getnomCient() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Familia: " << aux1.getfamilia() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Forma de la hoja: " << aux1.gethoja() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Longitud del tallo (cm): " << aux1.gettallo() << endl;
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << endl;
						p1++;
					}
				}
				
				if(colaAO.empty() == true) { //Si la cola esta vacia
					//Imprimir mensaje para indicar que la cola esta vacia
					cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t/  ##No hay arboles ornamentales en existencia## /" << endl;
					cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
				}
				else {
					p2 = &colaAO.front(); //Dirigirse al primer elemento
					//Imprimir titulo
					cout << "\n\n\n\t\t\t\t//////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t/  LISTADO DE ARBOLES ORNAMENTALES EN EXISTENCIA /" << endl;
					cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
					for(int i = 1; i <= colaAO.size(); i++) { //Generar ciclo para imprimir datos
						//Imprimir los arboles con sus respectivos datos
						aux2 = *p2;
						cout << "\n\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << "\t\t\t\t  Nombre del Arbol: " << aux1.getnComun() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Nombre Cientifico: " << aux1.getnomCient() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Familia: " << aux1.getfamilia() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Forma de la hoja: " << aux1.gethoja() << endl;
						cout << "\t\t\t\t----------------------------------------------" << endl;
						cout << "\t\t\t\t  Longitud del tallo (cm): " << aux1.gettallo() << endl;
						cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
						cout << endl;
						p2++;
					}
				}
				system("pause");	
				break;
						
			case 3:
			    if(colaAF.empty() == true) { //Si la cola esta vacia
					//Imprimir mensaje para indicar que la cola esta vacia
					cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t/    ##No hay arboles frutales en existencia##   /" << endl;
					cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
				}
				else { //Si la cola tiene arboles ingresados
					cout << "\t\t\t\t///////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t Ingrese el nombre comun del arbol: ";
					cin >> dato;
					cout << "\t\t\t\t///////////////////////////////////////////////////" << endl;
					p1 = &colaAF.front();
					for(int i = 1; i <= colaAF.size(); i++) {
						aux1 = *p1;
						if(dato == aux1.getnComun()) {
							cout << "\n\t\t\t\t//////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t  Nombre del Arbol: " << aux1.getnComun() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Nombre Cientifico: " << aux1.getnomCient() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Familia: " << aux1.getfamilia() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Forma de la hoja: " << aux1.gethoja() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Longitud del tallo (cm): " << aux1.gettallo() << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
							cout << endl;	
						}
						else {
							//Imprimir mensaje para indicar que no se encuentra entre este tipo
							cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t/  ??? Arbol no encontrado como tipo frutal ???  /" << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
						}
					}
					p1++; //Contador para recorrer la cola
				}
					
				if(colaAO.empty() == true) { //Si la cola esta vacia
					//Imprimir mensaje para indicar que la cola esta vacia
					cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t/  ##No hay arboles ornamentales en existencia## /" << endl;
					cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
				}
				else { //Si la cola tiene arboles ingresados
					cout << "\t\t\t\t///////////////////////////////////////////////////" << endl;
					cout << "\t\t\t\t Ingrese el nombre comun del arbol: " << endl;
					cin >> dato;
					cout << "\t\t\t\t///////////////////////////////////////////////////" << endl;
					p2 = &colaAO.front();
					for(int i = 1; i <= colaAO.size(); i++) {
						aux2 = *p2;
						if(dato == aux2.getnComun()) {
							cout << "\n\t\t\t\t//////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t  Nombre del Arbol: " << aux2.getnComun() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Nombre Cientifico: " << aux2.getnomCient() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Familia: " << aux2.getfamilia() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Forma de la hoja: " << aux2.gethoja() << endl;
							cout << "\t\t\t\t----------------------------------------------" << endl;
							cout << "\t\t\t\t  Longitud del tallo (cm): " << aux2.gettallo() << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
							cout << endl;	
						}
						else {
							//Imprimir mensaje para indicar que no se encuentra entre este tipo
							cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t/ ?? Arbol no encontrado como tipo ornamental ?? /" << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
						}
					}
					p2++; //Contador para recorrer la cola
				}
				
				system("pause"); //Pausar pentalla de la consola
				break; //Terminar proceso
				
			case 4:
				do { //Ciclo para mostrar solo 2 opciones
					select(); //Ejecutar funcion de seleccion
					opcS = tomarINT(); //Tomar dato de la opcion digitada
					system("cls"); //Borrar pantalla de consola
					system("color 70"); //Cambiar colores, fondo blanco, texto negro
					
					if(opcS == 1) { //Si es un arbol frutal	
						if(colaAF.empty() == true ) { //Si la cola esta vacia
			   				//Imprimir mensaje para indicar que la cola esta vacia
							cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t/  ### No hay arboles frutales en existencia ### /" << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
						}
						else { //Si no esta vacia
							colaAF.pop(); //Borrar elemento de la cola
							//Imprimir mensaje para indicar que se ha borrado
							cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t/   !!!  Arbol eliminado satisfactoriamente  !!! /" << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
			   			}
					}
			   		else if(opcS == 2) {
			   			if(colaAO.empty() == true ) { //Si la cola esta vacia
			   				//Imprimir mensaje para indicar que la cola esta vacia
							cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t/  ##No hay arboles ornamentales en existencia## /" << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
						}
						else { //Si no esta vacia
							colaAO.pop(); //Borrar elemento de la cola
							//Imprimir mensaje para indicar que se ha borrado
							cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
							cout << "\t\t\t\t/   !!!  Arbol eliminado satisfactoriamente  !!! /" << endl;
							cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
						}
					}
					break;
				}
				while(opcS != 2);
				
			   	system("pause");
				break;
			
			case 5:
				break;
		}
	}
	while(opcM != 5);	
		
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Desarrollo de las funciones

void menu() { //Funcion para mostrar menu
	system("cls"); //Borrar pantalla de la consola
	system("color 70"); //Cambiar colores, fondo blanco, texto negro
	cout << endl << endl << endl << endl << endl; //Espacios de linea
	//Imprimir menu de opciones en pantalla
	cout << "\t\t\t\t ------------------------------------------------- " << endl;
	cout << "\t\t\t\t|             [[MENU DE OPERACIONES]]             |" << endl;
	cout << "\t\t\t\t|-------------------------------------------------|" << endl;
	cout << "\t\t\t\t|                                                 |" << endl;
	cout << "\t\t\t\t|        1. Agregar un nuevo arbol                |" << endl;
	cout << "\t\t\t\t|        2. Mostrar arboles en existencia         |" << endl;
	cout << "\t\t\t\t|        3. Buscar un arbol en especifico         |" << endl;
	cout << "\t\t\t\t|        4. Eliminar un arbol en existencia       |" << endl;
	cout << "\t\t\t\t|        5. Salir del programa                    |" << endl;
	cout << "\t\t\t\t|                                                 |" << endl;
	cout << "\t\t\t\t -------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\tDigite la opcion: "; //Mensaje para pedir ingreso de opcion
}

int tomarINT() { //Funcion para tomar enteros
	string numero; //Variable de cadena para el numero
	bool valido = false; //Variable booleana para validar
	
	while(!valido) { //Mientras no sea valido
		try{ //Intentar
			getline(cin, numero); //Obtener numero
			valido = validINT(numero); //Ejecutar funcion de validacion
			if(!valido) { //Si no sigue siendo valido
				throw numero; //Arrojar numero
			}
		}
		catch (string e) { //Capturar dato de la cadena
			break; //Terminar proceso
		}
	}
	
	return atoi(numero.c_str()); //Convertir string a int y regresar numero
}

bool validINT(string numero) { //Funcion para validar enteros
	int inicio = 0; //Variable de inicio de conteo
	
	if(numero.length() == 0) { //Si no hay elementos en la caena
		return 0; //Retornar valor falso
	}
	else if (numero[0] == '+' || numero[0] == '-') { //Si el elemento contiene un signo
		inicio = 1; //Iniciar en 1
		if(numero.length() == 1) { //Si la longitud es uno
			return 0; //Devolver falso
		}
	}
	
	for(int i = inicio; i < numero.length(); i++) { //Ciclo segun el temanio
		if(!isdigit(numero[i])) { //Si no es un digito
			return 0; //Retornar falso
		}
	}
	
	return 1; //Devolver verdadero, cumple los requisitos
}

void select(){ //Funcion de selecciones
	system("color 07"); //Cambiar colores, fondo negro, texto blanco
	cout << endl << endl << endl << endl << endl; //Espacios de linea
	//Imprimir menu de opciones en pantalla
	cout << "\t\t\t\t ------------------------------------------------- " << endl;
	cout << "\t\t\t\t|              [[MENU DE SELECCION]]              |" << endl;
	cout << "\t\t\t\t|-------------------------------------------------|" << endl;
	cout << "\t\t\t\t|                                                 |" << endl;
	cout << "\t\t\t\t|        1. Agregar arbol frutal                  |" << endl;
	cout << "\t\t\t\t|        2. Agregar arbol ornamental              |" << endl;
	cout << "\t\t\t\t|                                                 |" << endl;
	cout << "\t\t\t\t -------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\tDigite la opcion: "; //Mensaje para pedir ingreso de opcion
}
