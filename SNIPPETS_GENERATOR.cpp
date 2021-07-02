// Realizado por Erick Ignacio Rodríguez JUÁREZ.    //
// Licenciatura en Matemáticas Aplicadas.           //
// OPEN G.L. v.2                                    //

#include<stdio.h>  //librería normal.
#include<stdlib.h> //librería normal.
#include<fstream>  //librería para archivos.
#include<string.h> //librería para strings.
#include<iostream> //librería para el cout y cin.
#include<vector>
using namespace std;

using std::cout;     using std::cerr;
using std::endl;     using std::string;
using std::ifstream; using std::vector;

// Procedimiento para crear un archivo con nombre y extensión. (*)
void nuevo (string &extension) {

  ofstream archivo1;       //archivo que se guarda en el búfer para generarse después.
  string nombre_de_archivo;//nombre del nuevo archivo.
  string parrafo1;         //variable que guardará la línea del nuevo archivo 

  cout<<"\n\nINSERT THE FILENAME : "; cin.ignore(); // el cin.ignore() es necesario una sola vez para poder introducir una nueva línea.
  getline(cin,nombre_de_archivo);                             // se registra el nombre del archivo.



  nombre_de_archivo += "." + extension;             // se coloca la extensión del archivo.
  archivo1.open(nombre_de_archivo.c_str(),ios::out);// se genera el archivo en el directorio actual.

  if (archivo1.fail()) {// si no se puede abrir, archivo1.fail() = True. 
    cout<<"\n\n=========\n\nFILE COULDNT GENERATED.\n\n=========\n\n";
    getchar();
    exit(1); // se cierra éste nivel, i.e. se vuelve a la pantalla inicial.
  }

  cout<<"\n\nINSERT THE PARAGRAPH : "; getline(cin,parrafo1);//se guarda una línea.
  archivo1<<parrafo1;                                         //se escribe la línea en el archivo.

  archivo1.close(); // se cierra el archivo y sale del búfer. Esta línea es necesaria para que se escriba correctamente.
}

// Procedimiento para añadir una línea al final de un archivo. (**)
void editar(string &extension) {

  ofstream archivo2; // archivo que se guardará en el búfer (puede ser nuevo si es que no existe ninguno en el directorio actual).
  string texto_final;// variable que guarda la línea que quiere añadirse al final.
  string nombre1;    // variable que guarda el nombre del archivo.

  cout<<"INSERT THE FILENAME : "; cin.ignore(); // cin.ignore() es necesario una sola vez para detener la consola, y poder escribir. 
  getline(cin,nombre1);                                            // se obtiene el nombre.

  nombre1 += "." + extension;              // se añade la extensión al nombre.
  archivo2.open(nombre1.c_str(),ios::app); // se copia en el búfer el archivo.

  if(archivo2.fail()) {// cuando no hay ningun archivo que pueda ser copiado archivo2.fail() = True.
    cout<<"\n\n=========\n\nFILE COULDN'T GENERATED.\n\n=========\n\n";
    getchar();// se recibe una línea vacía para detener el programa.
    exit(1);  // se cierra éste nivel, i.e. se vuelve a la pantalla inicial.
  }

  cout<<"\n\nINSERT TEXT TO ADD AT THE END : "; getline(cin,texto_final); // se guarda la línea a añadir.

  archivo2<<endl;       // se añade un salto de línea.
  archivo2<<texto_final;// se añade el texto a la última línea.

  archivo2.close(); // se cierra el archivo y sale del búfer para escribirse en el archivo original.
}

// Procedimiento para abrir un archivo que ya existe. (***)
void abrir(string &extension) {

  string nombre3;                                // variable que guarda el nombre del archivo.
  cout<<"\nINSERT THE FILENAME : "; cin.ignore(); // cin.ignore() tiene que usarse una única vez para detener la consola.
  getline(cin,nombre3);                          // se guarda el nombre del archivo.

  nombre3 += "." + extension; cout<<"\n\n"; // se completa el nombre del archivo.

  ifstream fs(nombre3.c_str(),ios::in); // se encuentra en archivo con el nombre indicado en el directorio actual, y se le etiqueta como fs.
  char linea[128];                      // variable que guardará cada una de las líneas del archivo fs.

  if(fs.fail()) cout<<"\n\n========\n\nFILE DOESN'T EXISTS.\n\n==========\n\n"<<endl;// fs.fail() = True cuando fs sea vacío.
  else while(!fs.eof()) { // si fs no es vacío, entonces se procede a copiar cada una de sus líneas. fs.EndOfFile = True cuando se llegue a la íltima linea.
    fs.getline(linea,sizeof(linea)); // se guarda en línea un renglón del archivo.
    cout<<linea<<endl;               // se imprime la línea en la terminal.
  }
  fs.close();              // se cierra el archivo original.
  cout<<"\n\n"; getchar(); // se recibe una línea vacía para pausar el programa.
}

// Procedimiento para renovar el contenido de un archivo. (*v)
void sobreescribir(string &extension) {

  string contenido; // variable que guarda la nueva línea que se escribirá en el archivo.
  string nombre4;   // nombre del archivo 

  cout<<"INSERT THE FILENAME : "; cin.ignore(); // cin.ignore() es necesario para detener la terminal.
  getline(cin, nombre4);                                  // se guarda el nombre del archivo.

  nombre4 += "." + extension; // se completa el nombre del archivo.

  cout<<"\n\nINSERT THE NEW CONTENT OF THE FILE : "; getline(cin, contenido); // se obtiene la nueva línea que se escribirá en el archivo.

  ofstream fs(nombre4.c_str(), ios::out); // ios::out hace que se generé un archivo nuevo con el mismo nombre.
  fs<<contenido<<endl;                    // se escribe la única línea que se necesita en él.
  fs.close();                             // se cierra.

  cout<<"\n\n========\nFILE HAS BEEN MODIFIED SUCCESFULLY.\n\n==========\n\n"<<endl;
  getchar();// se recibe una línea vacía para pausar el programa.
}
// Procedimiento para escribir un archivo de snippets dado un trigger y un contenido dados.(v)
void escritura_snippet(string &trigger, string &content, string &scope){
  ofstream archivo_snippet;         // archivo en el búfer.
  string nombre_de_archivo_snippet; // nombre del sublime-snippet

  nombre_de_archivo_snippet = content + ".sublime-snippet";         // se identifica al archivo por su contenido.
  archivo_snippet.open(nombre_de_archivo_snippet.c_str(),ios::out); // se crea el archivo en el búfer.

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
  getline(cin,scope);                 // se ingresa el lenguage para el que los snippets servirán.
  string nombre_primer_columna, nombre_segunda_columna;
  cout<<"\n\n\tFILENAME WITH THE TRIGGERS : ";
  getline(cin,nombre_primer_columna); // se ingresa el nombre del primer archivo
  cout<<"\n\n\tFILENAME WITH THE CONTENTS : ";
  getline(cin,nombre_segunda_columna);// se ingresa el nombre del segundo archivo.

  // se añade la extensión de ambos archivos.
  nombre_primer_columna  += "." + extension; 
  nombre_segunda_columna += "." + extension;
  
  string linea_1; // variable que guardará una sola línea del primer archivo a la vez.
  string linea_2; // variable que guardará una sola línea del segundo archivo a la vez.

  ifstream archivo_trigger(nombre_primer_columna,ios::in);  // se genera el archivo en el búfer que contiene los triggers.
  ifstream archivo_content(nombre_segunda_columna,ios::in); // se genera el archivo en el búfer que contiene la definición del snippet.

  if(archivo_trigger.fail()||archivo_content.fail()) cout<<"COULDN'T FIND A FILE.\n\n"; // validación.
  else while(!archivo_trigger.eof()){         // mientras no se llegue al final del archivo.
    getline(archivo_trigger,linea_1);         // se guarda el trigger en línea_1
    getline(archivo_content,linea_2);         // se guarda el contenido en línea_2
    escritura_snippet(linea_1,linea_2,scope); // se escribe el snippet usando (v).
  }
  archivo_trigger.close(); // se cierra el archivo.
  archivo_content.close(); // se cierra el archivo.
  cout<<"\n\n==========\n\nSNIPPETS GENERATED SUCCESFULLY.\n\n==========\n\n"<<endl;
  getchar();
}
int main ()
{
  int opcion;       // número que determina la necesidad del usuario.
  string extension; // tipo de extensión de archivos a manejar.

  cout<<"\n\t\tSNIPPET GENERATOR\n";
  cout<<"================================================================\n";
  cout<<"\nINSERT THE EXTENSION OF THE FILES : "; cin>>extension; // se guarda la extensión para siempre mantenerse el tipo de archivo.

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
    cout<<"\nINSERT THE ACTION : "; cin>>opcion;// se ingresa la opción.
    
    //                  OPCIONES.
    switch(opcion){
      case 1: nuevo(extension);         break; // crea un archivo nuevo.                                        (*)
      case 2: editar(extension);        break; // añade texto al final de un archivo existente.                 (**)
      case 3: abrir(extension);         break; // abre un archivo existente.                                    (***)
      case 4: sobreescribir(extension); break; // sobre-escribe un archivo existente.                           (*v)
      case 5: generar_snipp(extension); break; // realiza dos búsquedas regex y los transcribe en otro archivo. (v*)
      case 6: exit(0);                  break; // salir
      default: cout<<"\n\nUNASIGNED OPTION. INSERT A VALID OPTION.\n\n";//validación.
    }
  }while(opcion!=6);//se loopea mientras el usuario no quiere cerrar el programa.
  return 0;
}