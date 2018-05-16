#ifndef CONTA_H_
#define CONTA_H_

#include <ostream>
#include <vector>
#include <memory>

#include "movimentacao.h"

class Conta {
  public:
    Conta(std::string, std::string, double);
    virtual ~Conta();

  protected:
    std::string agencia;
    std::string numero;
    double saldo;
    std::vector<std::shared_ptr<Movimentacao>> extrato;

  public:
    std::string getAgencia();
    std::string getNumero();
    double getSaldo();
    bool matchNum(std::string num);
    void transferir(std::shared_ptr<Conta> &conta, double valor);

    virtual void addMovimentacao(std::string, double, char);

    friend std::ostream& operator<< (std::ostream& o, Conta &c);

  private:
    virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
