#ifndef MODEL_H
#define MODEL_H

#include"AbstractView.h"
#include<list>
using namespace std;


class Model{
private:
    list<AbstractView*> observers;

public:
    void attach(AbstractView* o){observers.push_back(o);}
    void detach(AbstractView* o){observers.remove(o);}
    void Notify(){
        for(list<AbstractView*>::iterator itr=observers.begin(); itr!=observers.end(); itr++)
            (*itr)->update();
    }

    virtual ~Model(){observers.erase(observers.begin(),observers.end());}
};

#endif // MODEL_H
