#ifndef MODEL_H
#define MODEL_H
#include"AbstractView.h"

class Model{
public:
  virtual ~Model(){}
  virtual void attach(AbstractView* o)=0;
  virtual void detach(AbstractView* o)=0;
  virtual void Notify()=0;
};

#endif // MODEL_H
