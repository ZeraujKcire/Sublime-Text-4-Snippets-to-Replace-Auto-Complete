// Realizado por Erick Ignacio Rodr�guez JU�REZ.    //
// Licenciatura en Matem�ticas Aplicadas.           //
// OPEN G.L. v.2                                    //

#include<stdio.h>  //librer�a normal.
#include<stdlib.h> //librer�a normal.
#include<fstream>  //librer�a para archivos.
#include<string.h> //librer�a para strings.
#include<iostream> //librer�a para el cout y cin.
#include<vector>
using namespace std;

using std::cout;     using std::cerr;
using std::endl;     using std::string;
using std::ifstream; using std::vector;

// Procedimiento para crear un archivo con nombre y extensi�n. (*)
void nuevo (string &extension) {

  ofstream archivo1;       //archivo que se guarda en el b�fer para generarse despu�s.
  string nombre_de_archivo;//nombre del nuevo archivo.
  string parrafo1;         //variable que guardar� la l�nea del nuevo archivo 

  cout<<"\n\nINSERT THE FILENAME : "; cin.ignore(); // el cin.ignore() es necesario una sola vez para poder introducir una nueva l�nea.
  getline(cin,nombre_de_archivo);                             // se registra el nombre del archivo.



  nombre_de_archivo += "." + extension;             // se coloca la extensi�n del archivo.
  archivo1.open(nombre_de_archivo.c_str(),ios::out);// se genera el archivo en el directorio actual.

  if (archivo1.fail()) {// si no se puede abrir, archivo1.fail() = True. 
    cout<<"\n\n=========\n\nFILE COULDNT GENERATED.\n\n=========\n\n";
    getchar();
    exit(1); // se cierra �ste nivel, i.e. se vuelve a la pantalla inicial.
  }

  cout<<"\n\nINSERT THE PARAGRAPH : "; getline(cin,parrafo1);//se guarda una l�nea.
  archivo1<<parrafo1;                                         //se escribe la l�nea en el archivo.

  archivo1.close(); // se cierra el archivo y sale del b�fer. Esta l�nea es necesaria para que se escriba correctamente.
}

// Procedimiento para a�adir una l�nea al final de un archivo. (**)
void editar(string &extension) {

  ofstream archivo2; // archivo que se guardar� en el b�fer (puede ser nuevo si es que no existe ninguno en el directorio actual).
  string texto_final;// variable que guarda la l�nea que quiere a�adirse al final.
  string nombre1;    // variable que guarda el nombre del archivo.

  cout<<"INSERT THE FILENAME : "; cin.ignore(); // cin.ignore() es necesario una sola vez para detener la consola, y poder escribir. 
  getline(cin,nombre1);                                            // se obtiene el nombre.

  nombre1 += "." + extension;              // se a�ade la extensi�n al nombre.
  archivo2.open(nombre1.c_str(),ios::app); // se copia en el b�fer el archivo.

  if(archivo2.fail()) {// cuando no hay ningun archivo que pueda ser copiado archivo2.fail() = True.
    cout<<"\n\n=========\n\nFILE COULDN'T GENERATED.\n\n=========\n\n";
    getchar();// se recibe una l�nea vac�a para detener el programa.
    exit(1);  // se cierra �ste nivel, i.e. se vuelve a la pantalla inicial.
  }

  cout<<"\n\nINSERT TEXT TO ADD AT THE END : "; getline(cin,texto_final); // se guarda la l�nea a a�adir.

  archivo2<<endl;       // se a�ade un salto de l�nea.
  archivo2<<texto_final;// se a�ade el texto a la �ltima l�nea.

  archivo2.close(); // se cierra el archivo y sale del b�fer para escribirse en el archivo original.
}

// Procedimiento para abrir un archivo que ya existe. (***)
void abrir(string &extension) {

  string nombre3;                                // variable que guarda el nombre del archivo.
  cout<<"\nINSERT THE FILENAME : "; cin.ignore(); // cin.ignore() tiene que usarse una �nica vez para detener la consola.
  getline(cin,nombre3);                          // se guarda el nombre del archivo.

  nombre3 += "." + extension; cout<<"\n\n"; // se completa el nombre del archivo.

  ifstream fs(nombre3.c_str(),ios::in); // se encuentra en archivo con el nombre indicado en el directorio actual, y se le etiqueta como fs.
  char linea[128];                      // variable que guardar� cada una de las l�neas del archivo fs.

  if(fs.fail()) cout<<"\n\n========\n\nFILE DOESN'T EXISTS.\n\n==========\n\n"<<endl;// fs.fail() = True cuando fs sea vac�o.
  else while(!fs.eof()) { // si fs no es vac�o, entonces se procede a copiar cada una de sus l�neas. fs.EndOfFile = True cuando se llegue a la �ltima linea.
    fs.getline(linea,sizeof(linea)); // se guarda en l�nea un rengl�n del archivo.
    cout<<linea<<endl;               // se imprime la l�nea en la terminal.
  }
  fs.close();              // se cierra el archivo original.
  cout<<"\n\n"; getchar(); // se recibe una l�nea vac�a para pausar el programa.
}

// Procedimiento para renovar el contenido de un archivo. (*v)
void sobreescribir(string &extension) {

  string contenido; // variable que guarda la nueva l�nea que se escribir� en el archivo.
  string nombre4;   // nombre del archivo 

  cout<<"INSERT THE FILENAME : "; cin.ignore(); // cin.ignore() es necesario para detener la terminal.
  getline(cin, nombre4);                                  // se guarda el nombre del archivo.

  nombre4 += "." + extension; // se completa el nombre del archivo.

  cout<<"\n\nINSERT THE NEW CONTENT OF THE FILE : "; getline(cin, contenido); // se obtiene la nueva l�nea que se escribir� en el archivo.

  ofstream fs(nombre4.c_str(), ios::out); // ios::out hace que se gener� un archivo nuevo con el mismo nombre.
  fs<<contenido<<endl;                    // se escribe la �nica l�nea que se necesita en �l.
  fs.close();                             // se cierra.

  cout<<"\n\n========\nFILE HAS BEEN MODIFIED SUCCESFULLY.\n\n==========\n\n"<<endl;
  getchar();// se recibe una l�nea vac�a para pausar el programa.
}
// Procedimiento para escribir un archivo de snippets dado un trigger y un contenido dados.(v)
void escritura_snippet(string &trigger, string &content, string &scope){
  ofstream archivo_snippet;         // archivo en el b�fer.
  string nombre_de_archivo_snippet; // nombre del sublime-snippet

  nombre_de_archivo_snippet = content + ".sublime-snippet";         // se identifica al archivo por su contenido.
  archivo_snippet.open(nombre_de_archivo_snippet.c_str(),ios::out); // se crea el archivo en el b�fer.

  // formato de snippets en Sublime Text.
  archivo_snippet<<"<snippet>"<<endl;
  archivo_snippet<<"  <content><![CDATA["<<endl;
  archivo_snippet<<content<<endl;
  archivo_snippet<<"]]></content>"<<endl;
  archivo_snippet<<"   <tabTrigger>"<<trigger<<"</tabTrigger> "<<endl;
  archivo_snippet<<"   <scope>"<<scope<<"</scope>"<<endl;
  archivo_snippet<<"</snippet>"<<endl;
  archivo_snippet.close();// se cierra el archivo.
}
// Procedimiento para leer un archivo y extraer sus snippets.(v*)
void generar_snipp(string &extension){
  string scope;
  cout<<"\n\n\tSCOPE OF THE SNIPPETS\n\t(for example, LaTeX scope is text.tex) : ";cin.ignore();// cin.ignore() es necesario una sola vez para detener la consola.
  getline(cin,scope);                 // se ingresa el lenguage para el que los snippets servir�n.
  string nombre_primer_columna, nombre_segunda_columna;
  cout<<"\n\n\tFILENAME WITH THE TRIGGERS : ";
  getline(cin,nombre_primer_columna); // se ingresa el nombre del primer archivo
  cout<<"\n\n\tFILENAME WITH THE CONTENTS : ";
  getline(cin,nombre_segunda_columna);// se ingresa el nombre del segundo archivo.

  // se a�ade la extensi�n de ambos archivos.
  nombre_primer_columna  += "." + extension; 
  nombre_segunda_columna += "." + extension;
  
  string linea_1; // variable que guardar� una sola l�nea del primer archivo a la vez.
  string linea_2; // variable que guardar� una sola l�nea del segundo archivo a la vez.

  ifstream archivo_trigger(nombre_primer_columna,ios::in);  // se genera el archivo en el b�fer que contiene los triggers.
  ifstream archivo_content(nombre_segunda_columna,ios::in); // se genera el archivo en el b�fer que contiene la definici�n del snippet.

  if(archivo_trigger.fail()||archivo_content.fail()) cout<<"COULDN'T FIND A FILE.\n\n"; // validaci�n.
  else while(!archivo_trigger.eof()){         // mientras no se llegue al final del archivo.
    getline(archivo_trigger,linea_1);         // se guarda el trigger en l�nea_1
    getline(archivo_content,linea_2);         // se guarda el contenido en l�nea_2
    escritura_snippet(linea_1,linea_2,scope); // se escribe el snippet usando (v).
  }
  archivo_trigger.close(); // se cierra el archivo.
  archivo_content.close(); // se cierra el archivo.
  cout<<"\n\n==========\n\nSNIPPETS GENERATED SUCCESFULLY.\n\n==========\n\n"<<endl;
  getchar();
}
int main ()
{
  int opcion;       // n�mero que determina la necesidad del usuario.
  string extension; // tipo de extensi�n de archivos a manejar.

  cout<<"\n\t\tSNIPPET GENERATOR\n";
  cout<<"================================================================\n";
  cout<<"\nINSERT THE EXTENSION OF THE FILES : "; cin>>extension; // se guarda la extensi�n para siempre mantenerse el tipo de archivo.

  do{
    // ----------------------------------------------------------------
    // system("clear"); // If you have Linux, use this line.
    system("CLS");   // If you have Windows, use this line.
    // ----------------------------------------------------------------    
    //                  MENU.
    cout<<"\n\t\tSNIPPET GENERATOR\n";
    cout<<"================================================================\n";
    cout<<"\n1.-\tNEW FILE.";
    cout<<"\n2.-\tADD AT THE END.";
    cout<<"\n3.-\tOPEN A FILE.";
    cout<<"\n4.-\tOVER-WRITE A FILE.";
    cout<<"\n5.-\tWRITE SNIPPETS FROM A COUPLE OF FILES.";
    cout<<"\n6.-\tEXIT.\n\n";
    cout<<"================================================================\n";
    cout<<"\nINSERT THE ACTION : "; cin>>opcion;// se ingresa la opci�n.
    
    //                  OPCIONES.
    switch(opcion){
      case 1: nuevo(extension);         break; // crea un archivo nuevo.                                        (*)
      case 2: editar(extension);        break; // a�ade texto al final de un archivo existente.                 (**)
      case 3: abrir(extension);         break; // abre un archivo existente.                                    (***)
      case 4: sobreescribir(extension); break; // sobre-escribe un archivo existente.                           (*v)
      case 5: generar_snipp(extension); break; // realiza dos b�squedas regex y los transcribe en otro archivo. (v*)
      case 6: exit(0);                  break; // salir
      default: cout<<"\n\nUNASIGNED OPTION. INSERT A VALID OPTION.\n\n";//validaci�n.
    }
  }while(opcion!=6);//se loopea mientras el usuario no quiere cerrar el programa.
  return 0;
}