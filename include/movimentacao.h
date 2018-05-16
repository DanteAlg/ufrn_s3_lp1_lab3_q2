#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include <iostream>

// D - Débito
// C - Crétito

class Movimentacao {
  public:
    Movimentacao(std::string, double, char);
    ~Movimentacao();

  private:
    std::string descricao;
    double valor;
    char tipo;

  public:
    std::string getDescricao();
    double getValor();
    char getTipo();
    friend double operator+ (Movimentacao &m1, Movimentacao &m2);
    friend std::ostream& operator<< (std::ostream& o, Movimentacao &c);
};

#endif
