#include "viewtransazioni.h"

ViewTransazioni::ViewTransazioni(Transazioni* t) : subject(t)
{
    subject->attach(this);
    update();
}

void ViewTransazioni::update(){
    transazioni = subject->getUltimaTransizione();
}

ViewTransazioni::~ViewTransazioni(){
    subject->detach(this);
}

QString const ViewTransazioni::getTransazioni(){ return transazioni;}

Transazioni* ViewTransazioni::getSubject() const{
    return subject;
}
