/*Proyecto del II Parcial
Tema: Porcentaje de automatizaci?n de las empresas
Integrantes:
1... Baque De La Cruz Joffre Darío
2... Burgos Mero Erick Ariel
3... Gutiérrez Suarez Mario Miguel
4... Laínez Dominguez Diego Isaías
5... Melena Santander Diana Lucia
6... Nuñez Zamora Miguel Alejandro
7... Pacha Rivera Kleber Slader
8... Rocafuerte Tomala Jair Ariel
9... Rodríguez Catuto Ángel José
10... Salcedo Tomala Sammy Jordy
11... Suarez Ricardo Bryan Estuar
12... Suárez Yagual Vanessa Angelica
13... Tomalá Bernabé Richard Enrique
14... Villaprado Laje Max Anderson 

Curso: Auto1/1
Fecha: 8/02/2023*/

//Definici?n de Librer?as
#include<iostream>
#include<stdio.h>  
#include<windows.h> //Libreria que permite usar la funcion system
#include<ctype.h>
#include<unistd.h>
#include <conio.h>
#include <regex>	//Libreria que funciona con expresiones regulares que permiten aplicar validaciones en el ingreso de datos por el usuario.
#include <fstream>//Libreria para controlar, extraer, leer, abrir archivos txt.
#include <algorithm> 
#include <string> //Libreria para declarar variables tipo cadena o string
#include <cmath> //Libreria para hacer calculos matematicos
#include"crite.h" //Libreria local que calcula el promedio porcentual de los 5 criterios
using namespace std;

//Definici?n de Variables Globales
int limf=40, limc=100, i, j, op, c;
char rp;
FILE *doc;
//Definici?n de Estructuras de Datos
struct criterios
{
	float c1; //criterio 1: Creacion de productos
	float c2; //criterio 2: Validacion de garantia 
	float c3; //criterio 3: Equipo especializado
	float c4; //criterio 4: Ventas, produccion y exportacion
	float c5; //criterio 5: Innovacion
	float ct; //Total de criterios
};
struct empresa
{
	char noem[30]; //nombre de la empresa
	char resp[50]; //responsable
	char pres[40]; //producto estrella
	char diem[100]; //direccion de la empresa
	char ciu [30]; //ciudad
	char cel[30]; //telefono convencional o celular
	char co [40]; //correo electronico empresarial 
	char link [40]; //link de la pagina 
	struct criterios dc; //datos de criterios 
};

//definicion de variables tipo estructura 
struct empresa de; //datos de empresa 

//Definicion de prototipos de funciones y procedimientos
//Procedimiento Gotoxy
void gotoxy(int x, int y);
//Procedimiento borde
void p_borde();
//Procedimiento datos generales
void p_datos();
//Procedimiento menu de opciones
void p_dmenu();
//procedimiento de ingreso de datos 
void p_ingreso();
//Procedimiento para consultas
void p_consultas();
//Procedimiento para nomina 
void p_nomina();
//Procedimiento para graficos
void p_graficos();
//Procedimiento de Extraccion de lineas en especifico
void removeFirstN(string &str, int n);

//Funci?n Principal
int main()
{
	do
	{
		system("cls"); //Borrado de pantalla 
		system("color B");//Color del borde 
		//llamado al procedimiento borde
		p_borde();
		//llamado al procedimiento datos generales
		p_datos();
		//llamado al procedimiento datos del menu de opciones
		p_dmenu();
		gotoxy(21,37);cout<<"Desea volver al menu principal (S/N): ";
		//Validacion para que las respuestas ingresadas por el usuario sean solo "S" o "N", mayúsculas o minúsculas
		bool valid= false; //Variable valid iniciada en falso
		while (!valid){ //Bucle que se repetira hasta que la variable valid sea verdadero. 
			gotoxy(60,37);
			if (cin>>rp && rp =='s' || rp =='n' || rp =='S' || rp =='N') {	//Si la respuesta es la correcta...
				valid = true;												//...valid sera verdadero y se romperá el bucle y se seguirá con el programa
			} else {		//Caso contrario nos mostrará un mensaje que evitará la continuación del programa hasta que se ingrese un caracter valido ('S' o 'N')
			gotoxy(21,39);cout << "Ingrese una opcion valida. *Presione Enter para continuar*" << endl;
			gotoxy(79,39);int key = getch(); //Espera una tecla cualquiera
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}do {
			gotoxy(60,37);cout <<"                            "<<endl;
			gotoxy(21,39);cout << "                                                          " << endl;
			break;
		}while(getch());
		}
		getchar();
		
	}while(rp=='S'||rp=='s');
	//Pausa
	gotoxy(21,39);system("Pause");
	exit(0);
	
		
}

//Declaraci?n de prototipos de funciones y procedimientos
//Procedimiento gotoxy
void gotoxy(int x, int y)	//Funcion gotoxy permite ubicar datos en pantalla segun coordenadas especificadas por los argumentos 'x' y 'y'
 { 
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  //columna
    dwPos.Y= y;  //fila
    SetConsoleCursorPosition(hcon,dwPos);  
 }
 //Procedimiento Borde
 void p_borde()
 {
 	for(i=1;i<=limf-1;i++)
 	{
 		gotoxy(1,1);printf("%c",201);
 		gotoxy(1,40);printf("%c",200);
 		gotoxy(100,1);printf("%c",187);
 		gotoxy(100,40);printf("%c",188);
 		
 		
		if(i>=6)
		{
		 gotoxy(20,i);printf("%c",179);
		}
		 
 		gotoxy(limc,i);printf("%c",186);
 		gotoxy(1,i);printf("%c",186);
	}
	
	for(j=2;j<=limc-1;j++)
 	{
 		gotoxy(j,1);printf("%c",205);
 		gotoxy(j,6);printf("%c",196);
 		gotoxy(j,40);printf("%c",205);
	}
	
 }
//Procedimiento datos generales
void p_datos()
{
	gotoxy(29,2);cout<<"Universidad Estatal Peninsula de Santa Elena.";
	gotoxy(30,3);cout<<"Facultad de Sistemas y Telecomunicaciones.";
}
//Procedimiento datos del menu de opciones
void p_dmenu()
{
	gotoxy(3,7);cout<<"Menu de Opciones.";
	gotoxy(3,8);cout<<"1. Ingresos.";
	gotoxy(3,9);cout<<"2. Consultas.";
	gotoxy(3,10);cout<<"3. Nomina.";
	gotoxy(3,11);cout<<"4. Grafico.";
	gotoxy(3,12);cout<<"5. Salir.";
	gotoxy(21,38);cout<<"Digite la opcion a utilizar: ";
	//Validacion para evitar que se ingrese una opcion fuera del rango de 1 a 5
	bool valid = false;
	while (!valid) {	//bucle que se mantendra hasta que la variable valid sea verdadero
		gotoxy(50,38);      
		if (cin >> op && op >= 1 && op <= 5) { //si se ingresa una opcion correcta...
			valid = true;						//...valid sera verdadero y se rompera el bucle
		} else {	//Si no es correcta la opcion, se mostrara la validacion 
			gotoxy(21,39);cout << "Ingrese una opcion valida. *Presione Enter para continuar*" << endl;
			gotoxy(79,39);int key = getch(); //Espera una tecla cualquiera
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}do {
			gotoxy(50,38);cout <<"                            "<<endl;
			gotoxy(21,39);cout << "                                                          " << endl;
			break;
		}while(getch());
	}

	getchar();

	switch(op)
	{
		case 1:
				gotoxy(41,7);cout<<"DATOS DE EMPRESAS";
				p_ingreso();
		break;
		
		case 2:
				gotoxy(41,7);cout<<"CONSULTA DE EMPRESAS";
				p_consultas();
		break;
		
		case 3:
				gotoxy(41,7);cout<<"NOMINA DE EMPRESAS";
				p_nomina();
		break;
		
		case 4:
				gotoxy(30,7);cout<<"GRAFICAS DEL PORCENTAJE DE AUTOMATIZACION DE LAS EMPRESAS";
				p_graficos();
		break;
		
		case 5:
				gotoxy(21,40);exit(0);
		break;
	}
	
}

//procedimiento de ingreso de datos 
void p_ingreso()
{
	doc = fopen("proyect.txt","a"); //Guardar el documento de documento de texto
	
	
	//////////////////////////////////////////////
	//VALIDACION DE NOMBRE DE EMPRESA
	/////////////////////////////////////////////
	while(true) {
		gotoxy(22,8);cout<<"Nombre de la Empresa: ";gets(de.noem);
		bool valid = true; //Variable que nos permitirá romper el bucle
		
		//Evitar que el programa avance si no se ha ingresado nada
		if (strlen(de.noem) == 0) { //Se comprueba con la funcion strlen si la cadena de caracteres "noem" esta vacia. strlen cuenta los caracteres ingresados, si esta es 0, significa que esta vacio
        gotoxy(22,9);cout << "*Este espacio no puede quedar vacio.*" << endl; 	//Mensaje de validacion 
        gotoxy(22,10);cout << "Presiona cualquier tecla para continuar..."<< endl; 
        gotoxy(64,10);int key = getch(); //Se espera a que se presione una tecla . La funcion getch captura el caracter ingresado desde el teclado
        do {		//Lo siguiente borra los mensajes anteriores de la validacion
            gotoxy(22,9);cout << "                                                                      " << endl;
            gotoxy(22,10);cout << "                                          "<< endl;
            break;
        }while (getch());
        continue; //La instrucción continue; se salta el resto del codigo dentro del bucle y se repetirá esta validación
   		}
   		
		for (int i=0; i < strlen(de.noem); i++){	//Se realiza el conteo de caracteres con la funcion strlen
			if (!isalpha(de.noem[i]) && de.noem[i] != ' ') {	//Con la sentencia if se comprueba si la variable "noem" es diferente de una letra alfabetica a traves de !isalpha...
				valid = false;								//... y que sea distinto de un espacio ' '. Cuando es asi, la variable valid pasa a ser falso...
				break;										//y con break se rompe el ciclo for
			}
		} 	if (valid){	//Cuando la variable valid sea falsa, con la funcion break se rompera el bucle. Significa que solo se ingreso letras en esta opcion
			break;
		}	else {	//Validacion si la variable valid no paso a ser falso. Significara que se ingreso caracteres distintos a letras
				gotoxy(22,9);cout << "Por favor, ingresa solo letras." << endl;
				gotoxy(22,10);cout << "Presiona cualquier tecla para continuar..."<< endl;
  				gotoxy(64,10);int key = getch();
			do {
				gotoxy(44,8);cout <<"                              "<<endl;
				gotoxy(22,9);cout << "                               " << endl;
				gotoxy(22,10);cout << "                                          "<< endl;
				break;
			}while (getch());
		}
	}
	
	//////////////////////////////////////////////
	//VALIDACION DE RESPONSABLE
	/////////////////////////////////////////////
	
	while(true) {
	gotoxy(22,9);cout<<"Responsable: ";gets(de.resp);
	bool valid = true;
	//Evitar que el programa avance si no se ha ingresado nada
	if (strlen(de.resp) == 0) {
        gotoxy(22,10);cout << "*Este espacio no puede quedar vacio.*" << endl;
        gotoxy(22,11);cout << "Presiona cualquier tecla para continuar..."<< endl;
        gotoxy(64,11);int key = getch();
        do {
            gotoxy(22,10);cout << "                                                                      " << endl;
            gotoxy(22,11);cout << "                                          "<< endl;
            break;
        }while (getch());
   		continue;
		}
		for (int i=0; i < strlen(de.resp); i++){
			if (!isalpha(de.resp[i]) && de.resp[i] != ' ' && de.resp[i] != '-') {
				valid = false;
				break;
			}
		} 	if (valid){
			break;
		}	else {
				gotoxy(22,10);cout << "Por favor, ingresa solo letras." << endl;
				gotoxy(22,11);cout << "Presiona cualquier tecla para continuar..."<< endl;
  				gotoxy(64,11);int key = getch();
			do {
				gotoxy(34,9);cout <<"                              "<<endl;
				gotoxy(22,10);cout << "                               " << endl;
				gotoxy(22,11);cout << "                                          "<< endl;
				break;
			}while (getch());
		}
   	}
   	
   	//////////////////////////////////////////////
	//Validación de Producto Estrella
	/////////////////////////////////////////////
   	regex pro_estr("^.{1,}$");
	bool valid = true;
	while(true){
		gotoxy(22,10);cout<<"Producto estrella: ";gets(de.pres);
		if(valid == (regex_match(de.pres,pro_estr))){ //Verifica si los caracteres ingresados en la varaible "pres" son segun lo especificado en pro_estr...
			break;									//... si esto es correcto el bucle se rompe con la funcion break	
		}
        else
        {
			gotoxy(22,11);cout<<"*Este espacio no puede quedar vacio.*"<<endl;
			gotoxy(22,12);cout << "*Presiona cualquier tecla para continuar...*"<< endl;
  			gotoxy(66,12);int key = getch();
			do {
				gotoxy(22,10);cout <<"                                        "<<endl;
				gotoxy(22,11);cout <<"                                                      "<<endl;
				gotoxy(22,12);cout <<"                                                      "<< endl;
				break;
			}while (getch());
		}
	}
	
	//////////////////////////////////////////////
	//Validación de Direccion
	/////////////////////////////////////////////
	regex direc_emp("^.{1,}$");
	while(true){
	gotoxy(22,11);cout<<"Direccion de la empresa: ";gets(de.diem);
	//Evitar que el programa avance si no se ha ingresado nada
	if(valid == (regex_match(de.diem,direc_emp))){
			break;
		}
        else
        {
			gotoxy(22,12);cout<<"*Este espacio no puede quedar vacio.*"<<endl;
			gotoxy(22,13);cout << "*Presiona cualquier tecla para continuar...*"<< endl;
  			gotoxy(66,13);int key = getch();
			do {
				gotoxy(22,12);cout <<"                                        "<<endl;
				gotoxy(22,13);cout <<"                                                      "<<endl;
				gotoxy(22,13);cout <<"                                                      "<< endl;
				break;
			}while (getch());
		}
	}
	
	//////////////////////////////////////////////
	//Validación de Ciudad
	/////////////////////////////////////////////
	regex ciu("^.{1,}$");
	while(true){
	gotoxy(22,12);cout<<"Ciudad: ";gets(de.ciu);
	//Evitar que el programa avance si no se ha ingresado nada
	if(valid == (regex_match(de.ciu,ciu))){
			break;
		}
        else
        {
			gotoxy(22,13);cout<<"*Este espacio no puede quedar vacio.*"<<endl;
			gotoxy(22,14);cout << "*Presiona cualquier tecla para continuar...*"<< endl;
  			gotoxy(66,14);int key = getch();
			do {
				gotoxy(22,12);cout <<"                                        "<<endl;
				gotoxy(22,13);cout <<"                                                      "<<endl;
				gotoxy(22,14);cout <<"                                                      "<< endl;
				break;
			}while (getch());
		}
	}
	
	//////////////////////////////////////////////
	//Validación de Telefono convencional o celular
	/////////////////////////////////////////////
	while(true){
		gotoxy(22,13);cout<<"Telefono convencional o celular: ";gets(de.cel);
		bool valid = true;	
		//Evitar que el programa avance si no se ha ingresado nada
		if (strlen(de.cel) == 0) {
        gotoxy(22,14);cout << "Estas seguro que quieres dejar este espacio vacio(S/N): " << endl;
        gotoxy(77,14);cin>>rp;
        if(rp == 's' || rp == 'S') {
            gotoxy(22,14);cout << "                                                         " << endl;
            cin.ignore(1000, '\n');
            break;
        }
        else {
			do {
				gotoxy(55,13);cout <<"                              "<<endl;
				gotoxy(22,14);cout << "                                                                      " << endl;
            	cin.ignore(1000, '\n');
				break;
			}while (getch());
		continue;
		}
		
   		}
		for (int i = 0; i < strlen(de.cel); i++) {
			if (!isdigit(de.cel[i]) && de.cel[i] != '+' && de.cel[i] != '(' && de.cel[i] != ')' && de.cel[i] != ' ' && de.cel[i] != '-') {
			valid = false;
			break;
			}
		}
        if (valid){
			break;
		}
        else {
				gotoxy(22,14);cout << "Por favor, ingresa un numero de telefono convencional o celular valido." << endl;
				gotoxy(22,15);cout << "Presiona cualquier tecla para continuar..."<< endl;
  				gotoxy(64,15);int key = getch();
			do {
				gotoxy(54,13);cout <<"                                        "<<endl;
				gotoxy(22,14);cout << "                                                                       " << endl;
				gotoxy(22,15);cout << "                                          "<< endl;
				break;
			}while (getch());
		}
	}

	//////////////////////////////////////////////
	//VALIDACION DE CORREO ELECTRONICO
	/////////////////////////////////////////////
	
	regex email_expr("(\\w+)([\\.|_|-]?)(\\w*)@(\\w+)(\\.(\\w{2,6}))+");
	while(true){
		gotoxy(22,14);cout<<"Correo electronico empresarial: ";gets(de.co);
		if(valid == (regex_match(de.co,email_expr))){ //Verifica si los caracteres ingresados en la varaible "co" son segun lo especificado en email_expr...
			break;									//... si esto es correcto el bucle se rompe con la funcion break
		}
        else
        {
			gotoxy(22,15);cout<<"*Correo electronico invalido*"<<endl;
			gotoxy(22,16);cout << "*Presiona cualquier tecla para continuar...*"<< endl;
  			gotoxy(66,16);int key = getch();
			do {
				gotoxy(54,14);cout <<"                                        "<<endl;
				gotoxy(22,15);cout <<"                                                     "<<endl;
				gotoxy(22,16);cout <<"                                                      "<< endl;
				break;
			}while (getch());
		}
	}
	
	//////////////////////////////////////////////
	//VALIDACION DE link pagina de la empresa
	/////////////////////////////////////////////
	
	
	regex link_expr("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"); //Ejemplo http://www.asdasdasd.com
	while(true){
		gotoxy(22,15);cout<<"Link de la pagina: ";gets(de.link);
		if(valid == (regex_match(de.link,link_expr))){
			break;
		}
        else
        {
			gotoxy(22,16);cout<<"*Link invalido*"<<endl;
			gotoxy(22,17);cout << "*Presiona cualquier tecla para continuar...*"<< endl;
  			gotoxy(66,17);int key = getch();
			do {
				gotoxy(30,15);cout <<"                                                 "<<endl;
				gotoxy(22,16);cout <<"                                                     "<<endl;
				gotoxy(22,17);cout <<"                                                      "<< endl;
				break;
			}while (getch());
		}	
	}
	gotoxy(22,16);cout<<endl;
	gotoxy(22,17);cout<<"----------Criterios de automatizacion----------";
	gotoxy(22,18);cout<<endl;
    gotoxy(22,19);cout<<"Creacion de productos            (0-100%) : ";cin>>de.dc.c1;gotoxy(68,19);cout<<"%";
	gotoxy(22,20);cout<<"Validacion de garantia           (0-100%) : ";cin>>de.dc.c2;gotoxy(68,20);cout<<"%";
	gotoxy(22,21);cout<<"Equipo especializado             (0-100%) : ";cin>>de.dc.c3;gotoxy(68,21);cout<<"%";
	gotoxy(22,22);cout<<"Ventas, produccion y exportacion (0-100%) : ";cin>>de.dc.c4;gotoxy(68,22);cout<<"%";
	gotoxy(22,23);cout<<"Innovacion                       (0-100%) : ";cin>>de.dc.c5;gotoxy(68,23);cout<<"%";
	gotoxy(22,24);cout<<"-----------------------------------------------";
	
	de.dc.ct=F_Criterios(de.dc.c1, de.dc.c2, de.dc.c3, de.dc.c4, de.dc.c5); //Llama a la libreria que esta almacenada en crite.h y esta a su vez calcula el promedio porcentual
	
	gotoxy(22,25);cout<<"Porcentaje de Automatizacion: ";gotoxy(51,25);cout<<" "<<de.dc.ct;cout<<"%";

	fprintf(doc,"%s %s \n","Nombre de la empresa            : " ,de.noem);
	fprintf(doc,"%s %s \n","Responsable                     : " ,de.resp);
	fprintf(doc,"%s %s \n","Producto estrella               : " ,de.pres);
	fprintf(doc,"%s %s \n","Direccion de la empresa	        : " ,de.diem);
	fprintf(doc,"%s %s \n","Ciudad                          : " ,de.ciu);
	fprintf(doc,"%s %s \n","Telefono convencional o celular	: " ,de.cel);
	fprintf(doc,"%s %s \n","Correo electronico empresarial  : " ,de.co);
	fprintf(doc,"%s %s \n","Link de la pagina               : " ,de.link);
	fprintf(doc,"\n %s \n", "---Porcentaje de Automatizacion---");
	fprintf(doc,"%f \n",round(de.dc.ct));
	fprintf(doc,"\n \n");
	fclose(doc);
}

//Funcion para remover n caracteres
void removeFirstN(string &str, int n)
{
    str.erase(0, n); 
}

//Este procedimiento permite encontrar un indice dentro de un vector
void getIndex(vector<string>emp1, string k)
{
    auto it = find(emp1.begin(), emp1.end(), k);
  
    if (it != emp1.end()) 
    {
      
        int index = it - emp1.begin();
        cout << index << endl;
    }
    else {
        cout << "-1" << endl;
    }
}
	
//Procedimiento de Consultas
void p_consultas()
{
	string vec[100];
	int i = 0;
	int j = 0;
	int linea = 1;
	int rr = 1;
	string ax1;
	string ax4;
	string k;
	string empres;
	vector<string>emp1;
	vector<string>lines;
	int a = 0;
	int pit = 13;
	bool empresaEncontrada = false;
	
	// Abrir el archivo en modo de lectura
    ifstream file("proyect.txt");
    
    // Verificar si el archivo se abrió correctamente
    if (!file.is_open()) {
        gotoxy(22,13);cout << "Se necesitan datos para mostrar esta opcion."<< endl;
        gotoxy(22,14);cout << "No se ha registrado ninguna informacion" << endl;
        gotoxy(63,14);int key = getch();
        do{
        	gotoxy(22,13);cout << "                                              "<< endl;
        	gotoxy(22,14);cout << "                                           " << endl;
        	break;
		}while(getch());
        
    }else {
    	while (getline(file, vec[i])) { //Extrae una linea del archivo de texto y lo guarda dentro del vector vec
    	if(linea == rr) { 
    		empres = vec[i];	//Se le asigna a la variable empres los caracteres de vec
	    	int n = 35; 		//Numero de lineas a remover 
	    	removeFirstN(empres,n); //Se remueve 35 caracteres del contenido de la variable empres
	    	transform(empres.begin(),empres.end(), empres.begin(), ::tolower); //Transforma a minuscula los nombres de las empresas permitiendo la consulta tanto en minuscula como en mayuscula 
	    	empres.erase(remove_if(empres.begin(), empres.end(), ::isspace), empres.end()); //Elimina el espacio luego del nombre de la empresa 
	    	emp1.push_back(empres); //Envia el contenido de empres a emp1
	    	rr=rr+13; //Contador que encuentra la linea en la que se encuentra el nombre de la empresa
		}
		linea++;
	}
	file.close();
	
	gotoxy(22,8);cout<<"----------Consulte la informacion de la empresa a continuacion----------";
	gotoxy(22,10);cout<<"Ingrese el nombre de la empresa: ";
	getline(cin, k);

    k.erase(remove_if(k.begin(), k.end(), ::isspace), k.end()); //Ignorar el espacio luego del nombre
	transform(k.begin(),k.end(), k.begin(), ::tolower);	//Transforma a minuscula los nombres de las empresas
	//Proceso de impresion de los datos en pantalla
	for(i = 0; i < emp1.size(); i++){
		ax1 = emp1[i];
		if (k == ax1){
			empresaEncontrada = true;
			ifstream file("proyect.txt");
		    if (file.is_open()) {
		        while (getline(file, ax4)) {
		            lines.push_back(ax4);
		        }
		        file.close();
		    } else {
		        gotoxy(22,9);cout << "Se necesitan datos para mostrar esta opcion."<< endl;
        		gotoxy(22,10);cout << "No se ha registrado ninguna informacion" << endl;
		    }
				j= 0;
		    for (const auto &l : lines) {	
				if (j>= (i*13) && j<((i*13)+13)){
			        gotoxy(22,pit);cout << l << endl;
		    		pit++;
		    	}
		    	j++;
		    }
			break;
		}    		
	}	//Validacion si la empresa no es encontrada 
		if(!empresaEncontrada){
			gotoxy(22,14);cout<<"*La empresa que ingresaste no existe*"<<endl;
			gotoxy(22,15);cout << "*Presiona cualquier tecla para continuar...*"<<endl;
	  		gotoxy(66,15);int key = getch();
	  		cin.clear();
	  		gotoxy(55,10);cout<<"                                     "<<endl;
	        gotoxy(22,14);cout<<"                                                   "<<endl;
	        gotoxy(22,15);cout<<"                                                       "<<endl;
	        p_consultas();//Repite el procedimiento de consulta si no se encuentra el nombre
	        gotoxy(21,37); system("pause");//pausa...xd
	        main();//funcion principal o pagina principal del codigo
		}
	}
    
    
}

//Procedimiento de Nomina
void p_nomina()
{
	int n_lineas = 26;//Numero de lineas a imprimir
	
	vector<string> lineas;//Vector que guarda cada linea de archivo de txt como una cadena de caracteres para acceder a las líneas e imprimirlas en pantalla de manera controlada
	
	string linea;//Almacena temporalmente las lineas del archivo txt
	
	string res_usuario;//Variable para guardar la respuesta del usuario (siguiente, retroceder pagina, salir)
	
	//Abrir el archivo txt y almacenar su informacion en el vector 

	doc = fopen("proyect.txt","rt"); //Se abre el archivo
	//Se verifica si existe el archivo 
	if (doc == NULL) { 	// Con la funcion NULL se comprueba si doc esta apuntando a una direccion nula, por lo que no podra abrir el archivo de texto
    	gotoxy(22,13);cout << "Se necesitan datos para mostrar esta opcion."<< endl;// Mensaje para decirle al usuario que no se pudo abrir el archivo o no existe
        gotoxy(22,14);cout << "No se ha registrado ninguna informacion" << endl;
        gotoxy(63,14);int key = getch();
        do{
        	gotoxy(22,13);cout << "                                              "<< endl;
        	gotoxy(22,14);cout << "                                           " << endl;
        	break;
		}while(getch());
    	return; //Se cierra la funcion p_nomina
	}
	//Proceso de lectura y envio de la información al vector
	while((c=getc(doc)) != EOF) //lectura de los caracteres del archivo de texto para asignarles a la variable c hasta que se alcance el final del archivo
	{
		linea += c;//Asignarle los caracteres que contiene la variable c a la variable linea
		//Cada vez que se detecta un salto de linea durante la asigncion de los caracteres que contiene c a la variable linea, se hace uso de la setencia if 
		if(c == '\n')
		{
			lineas.push_back(linea);//Agrega al vector lineas, la informacion que contiene la variable linea
			linea.clear();//Se limpia el contenido de la variable linea
		}
	}
	fclose(doc);//Cerrar el archivo
	
	int inicio = 0;//Contador que permite moverse entre "paginas"
	while (true){
		for(int i = inicio; i < inicio + n_lineas; i++){ //Comienza a imprimir por lineas la informacion dentro del archivo txt   
			if(i >= lineas.size()){ //Cuando el contador i sea mayor o igual lineas.size se detiene el ciclo for con la funcion break. lineas.size permite imprimir...
					break;			//... la informacion almacenada en el vector lineas
			}
			gotoxy(22,9 + i - inicio);//Imprimi en la ubicacion deseada con el gotoxy
			cout<<lineas[i];
		}
		gotoxy(21,38);cout << "Presiona 's'(siguiente pagina), 'a'(pagina anterior), 'q'(cerrar): "; //Pregunta si desea avanzar o retroceder entre paginas, o cerrar la nomina
		gotoxy(87,38);getline(cin, res_usuario);
		//Limpiar la pantalla cuando se hace la transicion entre paginas
		if (res_usuario == "s" || res_usuario == "S" || res_usuario == "a" || res_usuario == "A" ) {
	    	gotoxy(22,8);cout<<"                                                                              ";
			gotoxy(22,9);cout<<"                                                                              ";
			gotoxy(22,10);cout<<"                                                                              ";
			gotoxy(22,11);cout<<"                                                                              ";
			gotoxy(22,12);cout<<"                                                                              ";
			gotoxy(22,13);cout<<"                                                                              ";
			gotoxy(22,14);cout<<"                                                                              ";
			gotoxy(22,15);cout<<"                                                                              ";
			gotoxy(22,16);cout<<"                                                                              ";
			gotoxy(22,17);cout<<"                                                                              ";
			gotoxy(22,18);cout<<"                                                                              ";
			gotoxy(22,19);cout<<"                                                                              ";
			gotoxy(22,20);cout<<"                                                                              ";
			gotoxy(22,21);cout<<"                                                                              ";
			gotoxy(22,22);cout<<"                                                                              ";
			gotoxy(22,23);cout<<"                                                                              ";
			gotoxy(22,24);cout<<"                                                                              ";
			gotoxy(22,25);cout<<"                                                                              ";
			gotoxy(22,26);cout<<"                                                                              ";
			gotoxy(22,27);cout<<"                                                                              ";
			gotoxy(22,28);cout<<"                                                                              ";
			gotoxy(22,29);cout<<"                                                                              ";
			gotoxy(22,30);cout<<"                                                                              ";
			gotoxy(22,31);cout<<"                                                                              ";
			gotoxy(22,32);cout<<"                                                                              ";
			gotoxy(22,33);cout<<"                                                                              ";
			gotoxy(22,34);cout<<"                                                                              ";
    	}

		if (res_usuario == "s" || res_usuario == "S") {
			if(inicio + n_lineas >= lineas.size()){	//evitar que el contador aumente cuando ya no hay datos que mostrar 
				continue;
			}
        	inicio += n_lineas;//El contador aumenta 
        } else if (res_usuario == "a" || res_usuario == "A"){
        	if(inicio <= 0){	//evitar que el contador disminuya cuando ya no hay datos mostrar  
            	continue;
        	}
        	inicio -= n_lineas;//El contador disminuye
        } else if (res_usuario == "q" || res_usuario == "Q") {	//Cierra la nomina
        	  break;
        }else {		//Validacion cuando se ingresa una opcion no valida
        	gotoxy(21,39);cout << "Escoge una opcion valida. ";
			gotoxy(47,39);cout << "*Presiona cualquier tecla para continuar...*"<< endl;
  			gotoxy(92,39);int key = getch();
			do {
				gotoxy(87,38); cout << "             " << endl;
				gotoxy(21,39);cout <<"                                                                      "<<endl;
				break;
			}while (getch());
		}
    }
}



//Procedimiento de Graficos
void p_graficos()
{
	string arr[100];  // Array para almacenar las líneas leídas del archivo
    int i = 0;        // Contador para el número de elementos en el array
    int line = 1;     // Número de la línea actual que se está leyendo
    
    // Abrir el archivo en modo de lectura
    ifstream file("proyect.txt");
    
    // Verificar si el archivo se abrió correctamente
    if (!file.is_open()) {
        gotoxy(22,9);cout << "Se necesitan datos para mostrar esta opcion."<< endl;
        gotoxy(22,10);cout << "No se ha registrado ninguna informacion" << endl;
    }
    
    vector<int> data;//Arreglo que almacena los datos porcentuales de cada empresa.
    vector<string> emp;
    
    int x = 11; //Variable que permite imprimir en el eje y en la posicion correcta a traves de una iteracion
    int z = 1;
    // Leer las líneas del archivo y almacenarlas en el array
	while (getline(file, arr[i])) {
        if (line == x ) {
        	int value = stoi(arr[i]); //La variable value de tipo entero recibe la conversion de los datos del array "arr" (de string a un valor de tipo int)
            data.push_back(value);   
			i++;
			x=x+13;
        }
        if (line == z) {
        	string str = arr[i];
    		int n = 35;
    		removeFirstN(str,n); //Remueve 35 caracteres 
    		z=z+13;
    		emp.push_back(str);
		}
        line++;
    }
    
    // Cerrar el archivo
    file.close();
    
	int max_value = 50;
	int y = 9; 
	for (int i = 0; i < data.size(); i++) {
		gotoxy(22,y);
	    for (int j = 0; j < data[i]* 30 / max_value; j++) {
	        printf("%c",178);
	    }
	    cout << " " << data[i] << "%   " << emp[i] << endl;
	    cout <<endl;
	    y=y+2;	
	}
}

