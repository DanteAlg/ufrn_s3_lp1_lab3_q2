#include "poupanca.h"

Poupanca::Poupanca(std::string _agencia, std::string _numero, double _saldo):
    Conta(_agencia, _numero, _saldo) {}

Poupanca::~Poupanca() {}

void Poupanca::addMovimentacao(std::string desc, double valor, char tipo) {
  int novo_valor = saldo + valor;

  if ((tipo == 'C') || (tipo == 'D' && novo_valor >= 0)) {
    extrato.push_back(std::make_shared<Movimentacao>(desc, valor, tipo));
    valor = novo_valor;
  }
}


std::ostream& 
Poupanca::print(std::ostream &o) const {
  for(int i = 0; i < extrato.size(); i++) {
    o << *extrato[i] << std::endl;
  }

  return o;
}

