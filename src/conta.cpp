#include "conta.h"

Conta::Conta(std::string _agencia, std::string _numero, double _saldo):
    agencia(_agencia), numero(_numero), saldo(_saldo) {}

Conta::~Conta() {}

std::string Conta::getAgencia() {
  return agencia;
}

std::string Conta::getNumero() {
  return numero;
}

bool Conta::matchNum(std::string num) {
  return (numero.compare(num) == 0);
}

double Conta::getSaldo() {
  return saldo;
}

void Conta::addMovimentacao(std::string, double, char) {}

void Conta::transferir(std::shared_ptr<Conta> &conta, double valor) {
  if (saldo > valor) {
    addMovimentacao("Transferencia financeira", -valor, 'D');
    conta->addMovimentacao("Transferencia financeira", valor, 'C');
  }
  else {
    std::cout << "Saldo insuficiente" << std::endl;
  }
}

std::ostream& operator<< (std::ostream &o, Conta &c) {
  return c.print(o);
}
