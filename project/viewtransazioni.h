#ifndef VIEWTRANSAZIONI_H
#define VIEWTRANSAZIONI_H

#include "AbstractView.h"
#include "transazioni.h"

class ViewTransazioni : public AbstractView
{
public:
    ViewTransazioni(Transazioni* t);
    void update() override;
    ~ViewTransazioni() override;
    QString const getTransazioni();
    Transazioni* getSubject() const;

private:
    Transazioni* const subject;
    QString transazioni;
};


#endif // VIEWTRANSAZIONI_H
