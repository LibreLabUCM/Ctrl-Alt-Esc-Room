#include <iostream>
using namespace std;
#include <fstream>

int menu();
void segundaOpcion(string &claveGeneral);
string buscarNumeros(string cadena);
string recogerCadena(string nombre);


int main(){
  int opcion = 0;
  string claveGeneral = "Esta es la clave final: ";
  
  cout << "  ___| |_ _ __  _    __ _| | |_  _    ___  ___  ___   _ __ ___   ___  _ __ ___  " << endl;
  cout << " / __| __| '__|| |_ / _` | | __|| |_ / _ \\/ __|/ __| | '__/ _ \\ / _ \\| '_ ` _ \\ " << endl;
  cout << "| (__| |_| | |_   _| (_| | | ||_   _|  __/\\__ \\ (__  | | | (_) | (_) | | | | | |" << endl;
  cout << " \\___|\\__|_|   |_|  \\__,_|_|\\__||_|  \\___||___/\\___| |_|  \\___/ \\___/|_| |_| |_|" << endl << endl;
                                                                                                                                                                      
  cout << "Gracias por usar el software que implementa el nuevo metodo de cifrado basado en la antigua corea -.-" << endl;
  cout << "Recuerda recoger las claves del archivo por orden" << endl;
  
  opcion = menu();

  while(opcion != 0){
    switch(opcion){
      case 1: cout << "Los archivos tienen los siguientes bombres: " << endl << "archivo1.txt" << endl << "archivo2.txt" << endl << "archivo3.txt" << endl << endl; break;
      case 2: segundaOpcion(claveGeneral); break;
    case 3: cout << "Enhorabuena por juntar las 3 claves!" << endl << claveGeneral << endl;
    }

    opcion = menu();
  }
  
  return 0;
}

int menu(){
  int opcion = 0;
  
  cout << "Que desea hacer?" <<	endl;
  cout << "1.- Mostrar el nombre de todos los archivos"	<< endl;
  cout << "2.- Recoger clave del archivo" << endl;
  cout << "3.- Mostrar la clave final" << endl;
  cout << "0.- Salir" << endl;
  cout << "Eleccion: ";
  cin >> opcion;

  if(opcion < 0 || opcion > 3){
    do{
      cout << "Eleccion incorrecta, vuelva a seleccionar: ";
      cin >> opcion;
    }while(opcion < 0 || opcion > 3);
  }
  
  return opcion;
}

void segundaOpcion(string &claveGeneral){
  string nombre, clave;
  
  cout << "Escribe el nombre del archivo: ";
  cin >> nombre;

  clave = buscarNumeros(recogerCadena(nombre));
  claveGeneral = claveGeneral + clave;
  
  cout << "Clave del archivo: " << clave << endl << endl;
}

string recogerCadena(string nombre){
  ifstream archivo;
  string cadena;
  
  archivo.open(nombre);

  if(archivo.is_open()){
    getline(archivo, cadena);
  }
  else{
    cout << "ERROR: no se ha podido abrir el archivo " << nombre << endl;
  }

  return cadena;
}

string buscarNumeros(string cadena){
  string busqueda;
  
  for(int i = 0; i < cadena.length(); i++){
    if(isdigit(cadena[i]) || isupper(cadena[i])){
      busqueda = busqueda+cadena[i];
    }
  }

  return busqueda;
}
