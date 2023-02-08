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
	float c1; //criterio 1
	float c2; //criterio 2
	float c3; //criterio 3
	float c4; //criterio 4
	float c5; //criterio 5
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
		system("cls");
		system("color B");
		//llamado al procedimiento borde
		p_borde();
		//llamado al procedimiento datos generales
		p_datos();
		//llamado al procedimiento datos del menu de opciones
		p_dmenu();
		gotoxy(21,37);cout<<"Desea volver al menu principal (S/N): ";
		
		bool valid= false;
		while (!valid){
			gotoxy(60,37);
			if (cin>>rp && rp =='s' || rp =='n' || rp =='S' || rp =='N') {
				valid = true;
			} else {
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
void gotoxy(int x, int y)
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
	
	bool valid = false;
	while (!valid) {
		gotoxy(50,38);         //y
		if (cin >> op && op >= 1 && op <= 5) {
			valid = true;
		} else {
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
				gotoxy(41,7);cout<<"GRAFICA DE EMPRESAS";
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
	doc = fopen("proyect.txt","a");
	
	
	//////////////////////////////////////////////
	//VALIDACION DE NOMBRE DE EMPRESA
	/////////////////////////////////////////////
	while(true) {
		gotoxy(22,8);cout<<"Nombre de la Empresa: ";gets(de.noem);
		bool valid = true;
		//Impedir que avance si no se ha contestado nada
		if (strlen(de.noem) == 0) {
        gotoxy(22,9);cout << "*Este espacio no puede quedar vacio.*" << endl;
        gotoxy(22,10);cout << "Presiona cualquier tecla para continuar..."<< endl;
        gotoxy(64,10);int key = getch();
        do {
            gotoxy(22,9);cout << "                                                                      " << endl;
            gotoxy(22,10);cout << "                                          "<< endl;
            break;
        }while (getch());
        continue;
   		}
		for (int i=0; i < strlen(de.noem); i++){
			if (!isalpha(de.noem[i]) && de.noem[i] != ' ') {
				valid = false;
				break;
			}
		} 	if (valid){
			break;
		}	else {
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
		if(valid == (regex_match(de.pres,pro_estr))){
			break;
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
		//Impedir que avance si no se ha contestado nada
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
		if(valid == (regex_match(de.co,email_expr))){
			break;
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
    	while (getline(file, vec[i])) {
    	if(linea == rr) {
    		empres = vec[i];
	    	int n = 35;
	    	removeFirstN(empres,n);
	    	transform(empres.begin(),empres.end(), empres.begin(), ::tolower);
	    	empres.erase(remove_if(empres.begin(), empres.end(), ::isspace), empres.end());
	    	emp1.push_back(empres); 
	    	rr=rr+13;
		}
		linea++;
	}
	file.close();
	
	gotoxy(22,8);cout<<"----------Consulte la informacion de la empresa a continuacion----------";
	gotoxy(22,10);cout<<"Ingrese el nombre de la empresa: ";
	getline(cin, k);

    k.erase(remove_if(k.begin(), k.end(), ::isspace), k.end());
	transform(k.begin(),k.end(), k.begin(), ::tolower);
	
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
	}
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
	string res_usuario;//Variable para guardar la respuesta del usuario (siguiente, atras, salir)
	
	//Abrir el archivo txt y almacenar su informacion en el vector 
	gotoxy(22,8);
	doc = fopen("proyect.txt","rt");
	while((c=getc(doc)) != EOF)
	{
		linea += c;//Seguir usando la variable linea para el almacenamiento de datos luego de ser vaciada el if()
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
		gotoxy(21,38);cout << "Presiona 's'(siguiente pagina), 'a'(pagina anterior), 'q'(cerrar): ";
		gotoxy(87,38);getline(cin, res_usuario);
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
			if(inicio + n_lineas >= lineas.size()){
				continue;
			}
        	inicio += n_lineas;//El contador aumenta 
        	} else if (res_usuario == "a" || res_usuario == "A"){
        	if(inicio <= 0){
            	continue;
        	}
        	inicio -= n_lineas;//El contador disminuye
        	} else if (res_usuario == "q" || res_usuario == "Q") {
        	  break;
        	}else {
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
        	int value = stoi(arr[i]);
            data.push_back(value);   
			i++;
			x=x+13;
        }
        if (line == z) {
        	string str = arr[i];
    		int n = 35;
    		removeFirstN(str,n);
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

