#include <iostream>
#include <ctime>
using namespace std;
string edadydiasymeses(int dia, int mes, int anio, string nombre)
{
    /*struct tm {
      int tm_sec;   // seconds of minutes from 0 to 61
      int tm_min;   // minutes of hour from 0 to 59
      int tm_hour;  // hours of day from 0 to 24
      int tm_mday;  // day of month from 1 to 31
      int tm_mon;   // month of year from 0 to 11
      int tm_year;  // year since 1900
      int tm_wday;  // days since sunday
      int tm_yday;  // days since January 1st
      int tm_isdst; // hours of daylight savings time
    } */
    /* Fecha/hora actual basado en el sistema actual*/
    time_t now = time(0);
    /*Objeto de una estructura tm con fecha/hora local*/
    tm *time= localtime(&now);
    int anioActual=1900+(time->tm_year), mesActual=(1+time->tm_mon), diaActual=time->tm_mday;
    int diasActuales = anioActual*360 + mesActual*30 + diaActual;
    int diasPersona =  anio*360 + mes*30 + dia;
    double difdias = diasActuales - diasPersona;
    //operador para el residuo es "%", pero solo funciona en enteros
    //operador para obtener residuo en n�meros de coma flotante es "div"
    div_t anios_vida = div(difdias,360);
    //cout<<"cociente:"<< anios_vida.quot;
    //cout<<" residuo:"<< anios_vida.rem;
    div_t mes_vida = div (anios_vida.rem, 30);
    string aux="Bienvenido, " + nombre+ ", tu tienes " + to_string(anios_vida.quot) + " anios";
    aux=aux + ", meses: " + to_string(mes_vida.quot);
    aux=aux + ", dias: "+ to_string( mes_vida.rem);
    return aux;
}
int pasoporvalor(int a){
    a=a*5;
    cout<<endl<<"Dentro de la funcion: el valor de la variable a: "<<a<<endl;
    return 1;
}
int pasoporreferencia(int &a){
    a=a*5;
    cout<<endl<<"Por referencia, el valor de la variable a: "<<a<<endl;
    return 1;
}
string saludos (){
    return "Bienvenidos";
}
string saludos(string nombre){
    return "Bienvenido " + nombre;
}
string saludos(string nombre, int edad){
    if(edad>=18)
        return "Bienvenido senior " + nombre;
    else
        return "Bienvenido joven " + nombre;
}
int main() {
    cout<<edadydiasymeses(17,05,2003,"leandro");
    int a=2;
    cout<<endl;
    pasoporvalor(a);
    cout<<endl<<"En el main, valor de la variable a: "<<a<<endl;
    //
    cout<<endl;
    pasoporreferencia(a);
    cout<<endl<<"En el main el valor de la variable a: "<<a<<endl;
    //
    cout<<endl<<saludos("Juan");
    cout<<endl<<saludos();
    cout<<endl<<saludos("Jose");
    cout<<endl<<saludos("Pedro", 20);
    return 0;
}
