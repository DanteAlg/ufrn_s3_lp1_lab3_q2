#ifndef POUPANCA_H_
#define POUPANCA_H_

#include <iostream>
#include "conta.h"

class Poupanca: public Conta {
  public:
    Poupanca(std::string, std::string, double);
    ~Poupanca();
    void addMovimentacao(std::string, double, char);

  private:
    std::ostream& print(std::ostream&) const;
};

#endif
