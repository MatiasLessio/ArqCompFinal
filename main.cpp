#include <iostream>
#include <string>
#include <conio.h> // getch
#include <Windows.h>
#include <cstdlib>
#include <vector>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;
void retardo (unsigned long int);
void mostrar (unsigned char);
void choque(unsigned long int);
void carrera(unsigned long int);
void ola_humana(unsigned long int);
void carga_de_bateria(unsigned long int);
void auto_fantastico(unsigned long int);
void semaforo_de_carrera(unsigned long int);
void piedrita(unsigned long int);
int main(){
    unsigned long int speedini = 150000000;
    unsigned long int speed = 150000000;
    
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("Santiago");
    usuarios.push_back("Matias");

    // Se añaden claves al vector
    claves.push_back("123sr");
    claves.push_back("123ml");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;
    int opcion = 0;

    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUSUARIO: ";
        getline(cin, usuario);
        char caracter;
        cout << "\tPASSWORD: ";
        caracter = getch();
        password = "";
        while (caracter != ENTER)
        {
            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout <<"*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }
        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }
        if (!ingresa)
        {
            cout <<"El usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }
    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
          do {
        system("cls");
        cout << "Seleccione el numero de la secuencia a visualizar"<<endl;
        cout<< "(1) Auto Fantastico" << endl;
        cout<< "(2) El Choque" << endl;
        cout<< "(3) La Carrera" << endl;
        cout<< "(4) Bateria Cargando"<<endl;
        cout<< "(5) Ola Humana"<<endl;
        cout<< "(6) Semaforo de Carrera"<<endl;
        cout<< "(7) Piedrita"<<endl;
        cout<< "(8) Salir "<<endl;
        while ((opcion < 1)) {
            cout << "Secuencia: ";
            cin >> opcion;
        }
        switch (opcion) {
            case 1:
                system("cls");
                auto_fantastico(speed);
                opcion = 0;
                speed = speedini;
                break;
            case 2:
                system("cls");
                choque(speed);
                opcion = 0;
                speed = speedini;
                break;
            case 3:
                system("cls");
                carrera(speed);
                opcion = 0;
                speed = speedini;
                break;
            case 4:
                system("cls");
                carga_de_bateria(speed);
                opcion = 0;
                speed=speedini;
                break;
            case 5:
                system("cls");
                ola_humana(speed);
                opcion = 0;
                speed=speedini;
                break;
            case 6:
                system("cls");
                semaforo_de_carrera(speed);
                opcion = 0;
                speed=speedini;
                break;
            case 7:
                system("cls");
                piedrita(speed);
                opcion = 0;
                speed=speedini;
                break;
            case 8:
                system("cls");
                cout<<"El sistema ha sido apagado"<<endl;
                break;
            default:
                system("cls");
                cout<<"El numero ingresado no corresponde a una secuencia valida"<<endl;
                opcion = 0;
        }
        cout << "Presione cualquier tecla para continuar "<<endl;
    } while (opcion != 8);
    }

    //cin.get();
}

void retardo(unsigned long int a){
    while (a) a--;
}
void mostrar (unsigned char dato){

  for (unsigned char mask = 128; mask > 0; mask>>=1)
    {
        if (dato&mask)
        {
            cout<<"*";
        }
        else {
            cout<<"_";
        }
    }
}
void carga_de_bateria(unsigned long int speed){
unsigned char tabla []={0x0,0x80,0xC0, 0xE0, 0xF0,0xF8, 0xFC, 0xFE, 0xFF};
    while (1) {
        for (int i = 0; i < 9; i++) {
          cout<<"Bateria Cargando"<<endl;
            cout<< "Presione ESC para volver al menu principal"<<endl;
            cout<<"Delay: "<<speed<<endl;
            mostrar(tabla[i]);
            retardo(speed);
            system("cls");

if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
    }
}
}
void ola_humana(unsigned long int speed){
  unsigned int pos = 0xE0;
  while(1){
  for (int i = 0; i < 8; ++i) {
    cout<<"Ola Humana"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(pos);
    pos >>= 1;
    retardo(speed);
    system("cls");

if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}

  }
  pos = 0x07;
  for (int i = 0; i < 6; ++i) {
    cout<<"Ola Humana"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(pos);
    pos <<= 1;
    retardo(speed);
    system("cls");

    if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
  }
}
}
void semaforo_de_carrera(unsigned long int speed){
  unsigned int pos = 0x80;
  while(1){
  for (int i = 0; i < 3; ++i) {
    cout<<"Semaforo de Carrera"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(pos);
    pos >>= 2;
    pos+=0x80;
    retardo(speed);
    system("cls");

if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}

  }
  pos = 0x80;
  for (int i = 0; i < 8; ++i) {
    cout<<"Semaforo de Carrera"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed/4<<endl;
    mostrar(pos);
    pos >>= 1;
    pos+=0x80;
    retardo(speed/4);
    system("cls");

    if ((speed - 5000000) > 250000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
  }
  pos = 0x80;
}
}
void auto_fantastico(unsigned long int speed){
  unsigned int pos = 0x80;
  while(1){
  for (int i = 0; i < 8; ++i) {
    cout<<"Auto Fantastico"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(pos);
    pos >>= 1;
    retardo(speed);
    system("cls");

if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}


  }
  pos = 0x02;
  for (int i = 0; i < 6; ++i) {
    cout<<"Auto Fantastico"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(pos);
    pos <<= 1;
    retardo(speed);
    system("cls");


if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
  }
}
}
void choque (unsigned long int speed){
  unsigned char tabla[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42};
while(1){

  for (int i = 0; i < 6; ++i) {
    cout<<"El Choque"<<endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(tabla[i]);
    retardo(speed);
    system("cls");
if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
 }
}
}
void carrera (unsigned long int speed){
unsigned char tabla[] = 
{0xA0,0x30,0x08,0x06,0x03,0x01};
while(1){

  for (int i = 0; i < 6; ++i) {
    cout<< "(3) La Carrera" << endl;
    cout<< "Presione ESC para volver al menu principal"<<endl;
    cout<<"Delay: "<<speed<<endl;
    mostrar(tabla[i]);
    retardo(speed);
    system("cls");

if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
  }
}
}
void piedrita(unsigned long int speed){
    unsigned char tabla []={0x80,0x20,0x08,0x02};
    while (1) {
        for (int i = 0; i < 4; i++) {
          cout<<"Piedrita"<<endl;
            cout<< "Presione ESC para volver al menu principal"<<endl;
            cout<<"Delay: "<<speed<<endl;
            mostrar(tabla[i]);
            retardo(speed);
            system("cls");

if ((speed - 5000000) > 1000000){
    if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
    if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
    }
}
}