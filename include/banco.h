#ifndef BANCO_H_
#define BANCO_H_

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "movimentacao.h"
#include "conta.h"
#include "corrente.h"
#include "poupanca.h"

class Banco {
  public:
    Banco();
    ~Banco();

  private:
    std::vector<std::shared_ptr<Conta>> contas;
    int conta_id;

  public:
    void abrir();

  private:
    void menu();

    void criarConta();
    void excluirConta();
    void sacar();
    void depositar();
    void extrato();
    void transferir();

    void getConta();
};

#endif
