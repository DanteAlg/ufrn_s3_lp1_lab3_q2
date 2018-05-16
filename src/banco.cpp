#include "banco.h"

Banco::Banco() {}

Banco::~Banco() {}

void Banco::abrir() {
  int escolha = -1;

  while(escolha != 0) {
    std::cout << "Digite uma operação válida: " << std::endl;
    std::cout << "1 - Criar conta" << std::endl;
    std::cout << "2 - Excluir conta" << std::endl;
    std::cout << "3 - Sacar" << std::endl;
    std::cout << "4 - Depositar" << std::endl;
    std::cout << "5 - Extrato" << std::endl;
    std::cout << "6 - Transferência" << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cin >> escolha;

    if (escolha == 1)
      criarConta();
    else if (escolha == 2)
      excluirConta();
    else if (escolha == 3)
      sacar();
    else if (escolha == 4)
      depositar();
    else if (escolha == 5)
      extrato();
    else if (escolha == 6)
      transferir();
    else if (escolha == 0)
      std::cout << "Fechamos por hoje :/ amanhã fazemos mais transacoes!" << std::endl;
    else {
      std::cout << "Opcao invalida! Tente Novamente: " << std::endl;
      escolha = -1;
    }
  }
}

void Banco::criarConta() {
  int aux;
  std::string agencia, numero;
  double saldo, limite;
  char status;

  std::cout << "Qual o tipo de conta?" << std::endl;
  std::cout << "1 - corrente" << std::endl;
  std::cout << "2 - poupanca" << std::endl;

  std::cin >> aux;

  if (aux == 1) {
    std::cout << "Digite a agencia: ";
    std::cin >> agencia;
    std::cout << std::endl;

    std::cout << "Digite o número da conta: ";
    std::cin >> numero;
    std::cout << std::endl;

    std::cout << "Digite o saldo atual: ";
    std::cin >> saldo;
    std::cout << std::endl;

    std::cout << "Digite E se for conta especial, se não digite N: ";
    std::cin >> status;
    std::cout << std::endl;

    std::cout << "Digite o limite da conta: ";
    std::cin >> limite;
    std::cout << std::endl;

    contas.push_back(std::make_shared<Corrente>(agencia, numero, saldo, status, limite));
  }
  else {
    std::cout << "Digite a agencia: ";
    std::cin >> agencia;
    std::cout << std::endl;

    std::cout << "Digite o número da conta: ";
    std::cin >> numero;
    std::cout << std::endl;

    std::cout << "Digite o saldo atual: ";
    std::cin >> saldo;
    std::cout << std::endl;

    contas.push_back(std::make_shared<Poupanca>(agencia, numero, saldo));
  }
}

void Banco::excluirConta() {
  getConta();

  if (conta_id > -1) {
    contas.erase(contas.begin() + conta_id);
    std::cout << "Conta excluida com sucesso" << std::endl;
  }
  else
    std::cout << "Conta não encontrada..." << std::endl;
}

void Banco::sacar() {
  double valor;
  getConta();

  if (conta_id > -1) {
    std::cout << "Digite o valor a sacar: ";
    std::cin >> valor;
    std::cout << std::endl;

    contas[conta_id]->addMovimentacao("Saque em conta", -valor, 'D');
  }
  else
    std::cout << "Conta não encontrada..." << std::endl;
}

void Banco::depositar() {
  double valor;
  getConta();

  if (conta_id > -1) {
    std::cout << "Digite o valor a depositar: ";
    std::cin >> valor;
    std::cout << std::endl;

    contas[conta_id]->addMovimentacao("Deposito em conta", valor, 'C');
  }
  else
    std::cout << "Conta não encontrada..." << std::endl;
}

void Banco::extrato() {
  getConta();

  if (conta_id > -1) {
    std::cout << *contas[conta_id] << std::endl;
  }
  else
    std::cout << "Conta não encontrada..." << std::endl;
}

void Banco::transferir() {
  conta_id = -1;
  int dest_id = -1;
  double valor;
  std::string numero_orig, numero_dest;

  std::cout << "Digite o número da conta de origem: ";
  std::cin >> numero_orig;
  std::cout << std::endl;

  for (int i = 0; i < contas.size(); i++) {
    if (contas[i]->matchNum(numero_orig)) {
      conta_id = i;
    }
  }

  if (conta_id > -1) {
    std::cout << "Digite o número da conta de destino: ";
    std::cin >> numero_dest;
    std::cout << std::endl;

    for (int i = 0; i < contas.size(); i++) {
      if (contas[i]->matchNum(numero_dest)) {
        dest_id = i;
      }
    }

    if (dest_id > -1) {
      std::cout << "Digite o valor de transferência: ";
      std::cin >> valor;
      std::cout << std::endl;

      contas[conta_id]->transferir(contas[dest_id], valor);
    } 
    else {
      std::cout << "Não existe conta de destino" << std::endl;
    }
  }
  else {
    std::cout << "Não existe conta de origem" << std::endl;
  }
}

void Banco::getConta() {
  conta_id = -1;
  std::string numero;

  std::cout << "Digite o número da conta: ";
  std::cin >> numero;

  for (int i = 0; i < contas.size(); i++) {
    if (contas[i]->matchNum(numero)) {
      conta_id = i;
    }
  }
}
