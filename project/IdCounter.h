#ifndef IDCOUNTER_H
#define IDCOUNTER_H

#endif // IDCOUNTER_H

class IdCounter{
public:
  static unsigned int getId(){
    Id++;
    return Id;
  }

private:
  static unsigned int Id;
};
