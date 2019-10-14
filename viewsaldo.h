#ifndef VIEWSALDO_H
#define VIEWSALDO_H

#include "AbstractView.h"
#include "saldo.h"

class ViewSaldo : public AbstractView
{
public:
    ViewSaldo(Saldo* s);
    virtual void update() override;
    virtual ~ViewSaldo() override;
    double getState() const;
    Saldo* getSubject() const;
private:
    double stato;
    Saldo* const subject;
};


#endif // VIEWSALDO_H
