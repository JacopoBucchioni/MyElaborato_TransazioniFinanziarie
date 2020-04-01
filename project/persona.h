#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona
{
public:
  Persona(string n, string c, string cf="", string e="", string p="");

  string getNome() const;
  void setNome(string n);
  string getCognome() const;
  void setCognome(string c);
  void setEmail(string e);
  string getEmail() const;
  void setPhoneNumber(string p);
  string getPhoneNumber() const;
  void setCF(string cf);
  string getCF() const;

private:
  string nome;
  string cognome;
  string CF;
  string email;
  string phoneNumber;
};

#endif // PERSONA_H
