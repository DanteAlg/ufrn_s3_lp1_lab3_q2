#include "movimentacao.h"

Movimentacao::Movimentacao(std::string _descricao, double _valor, char _tipo):
  descricao(_descricao), valor(_valor), tipo(_tipo) {}

Movimentacao::~Movimentacao() {}

std::string Movimentacao::getDescricao() {
  return descricao;
}

double Movimentacao::getValor() {
  return valor;
}

char Movimentacao::getTipo() {
  return tipo;
}

double 
operator+(Movimentacao &m1, Movimentacao &m2) {
  return (m1.getValor() + m2.getValor());
}


std::ostream& operator<< (std::ostream &o, Movimentacao &m) {
  o << m.getDescricao() << " no valor de: R$ " << m.getValor();
  return o;
}
