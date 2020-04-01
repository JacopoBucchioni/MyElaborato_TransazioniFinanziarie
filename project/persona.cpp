#include "persona.h"

Persona::Persona(string n, string c, string cf, string e, string p) :
  nome(n),
  cognome(c),
  CF(cf),
  email(e),
  phoneNumber(p)
{

}

string Persona::getNome() const{return nome;}
void::Persona::setNome(string n) {nome=n;}
string Persona::getCognome() const{return cognome;}
void Persona::setCognome(string c) {cognome=c;}
void Persona::setEmail(string e){email=e;}
string Persona::getEmail() const{return email;}
void Persona::setPhoneNumber(string p){phoneNumber=p;}
string Persona::getPhoneNumber() const{return phoneNumber;}
void Persona::setCF(string cf){CF=cf;}
string Persona::getCF() const{return CF;}
