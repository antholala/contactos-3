#include <iostream>
using namespace std;

#include <fstream>

void escribirArchivo();
void leerArchivo();

int main() 
{
  int op;
  do{
  cout<<"Opciones"<<endl;
  cout<<"1.- Ingresar datos:"<<endl;
  cout<<"2.- Leer datos"<<endl;
  cout<<"3.- Salir"<<endl;
  cin>>op;
  switch (op){
    case 1:
    escribirArchivo();
    break;
    case 2:
    leerArchivo();
    break;
  }
}
  while(op!=3);
}

void escribirArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  string nombrearchivo;
  cout<<"Ingrese el nombre del archivo: ";
  while(getchar()!='\n');  
  getline(cin,nombrearchivo);
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do
  {
    cout<<"\t Ingrese el nombre:";
    getline(cin,nombre); 
    cout<<"\t Ingrese el apellido:";
    getline(cin,apellido); 
    cout<<"\t Ingrese la edad:";
    cin>>edad;

    archivoprueba<<nombre<<" "<<apellido<<" "<<edad<<endl;

    cout<<"Desea ingresar otro contacto s/n ";

    cin>>r;

    cin.ignore();
  }
  while(r=='s');

  archivoprueba.close();

}




void leerArchivo()
{
  string nombre;
  string apellido;
  int edad;
  
  ifstream archivolectura("libreta.txt");
  string texto;
  while(!archivolectura.eof())
    {
      archivolectura>>nombre>>apellido>>edad;

      if(!archivolectura.eof())
            {
              cout<<"Nombre:"<<nombre<<endl;
              cout<<"Apellido:"<<apellido<<endl;
              cout<<"Edad:"<<edad<<endl;
            }
    }
  archivolectura.close();

}