#ifndef CORRENTE_H_
#define CORRENTE_H_

#include <iostream>
#include "conta.h"

class Corrente: public Conta {
  public:
    Corrente(std::string _agencia, std::string _numero, double _saldo, char _status, double _limite);
    ~Corrente();

  private:
    char status;
    double limite;

  public:
    char getStatus();
    double getLimite();

    void addMovimentacao(std::string, double, char);

  private:
    std::ostream& print(std::ostream&) const;
};

#endif
