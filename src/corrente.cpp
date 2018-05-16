#include "corrente.h"

Corrente::Corrente(std::string _agencia, std::string _numero, double _saldo,
    char _status, double _limite):
    Conta(_agencia, _numero, _saldo), status(_status), limite(_limite) {}

Corrente::~Corrente() {}

 char Corrente::getStatus() {
  return status;
}

double Corrente::getLimite() {
  return limite;
}

void Corrente::addMovimentacao(std::string desc, double valor, char tipo) {
  int novo_valor = saldo + valor;

  if ((tipo == 'C' && novo_valor <= limite) || (tipo == 'D' && novo_valor >= 0)) {
    extrato.push_back(std::make_shared<Movimentacao>(desc, valor, tipo));
    valor = novo_valor;
  }
}

std::ostream& 
Corrente::print(std::ostream &o) const {
  for(int i = 0; i < extrato.size(); i++) {
    o << extrato[i] << std::endl;
  }

  return o;
}
