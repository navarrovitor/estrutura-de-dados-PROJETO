#ifndef PILHA_H
#define PILHA_H

#include <string>
#include <iostream>
#define tamanho 10

using namespace std;

class Pilha
{
private:
  int *pilha;
  int  topo;
  char item[tamanho];

public:
  Pilha();
  Pilha(int e);
  bool cheia();
  bool vazia();
  int desempilha();
  void empilha(int e);
  void empilhaParenteses(char e);
  int quantidade();
  void imprimir();
  bool checarSintatica(char p[]);
};

#endif