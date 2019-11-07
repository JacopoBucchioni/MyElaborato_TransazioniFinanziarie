#include "viewsaldo.h"

ViewSaldo::ViewSaldo(Saldo* s) : subject(s)
{
    subject->attach(this);
    update();
}
void ViewSaldo::update(){
    stato = subject->getSaldo();
}
ViewSaldo::~ViewSaldo(){
    subject->detach(this);
}
double ViewSaldo::getState()const {return stato;}

Saldo* ViewSaldo::getSubject() const{
    return subject;
}

