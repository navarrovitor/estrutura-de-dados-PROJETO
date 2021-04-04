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
  int topo;
  char item[tamanho];

public:
  Pilha();
  Pilha(int e);
  bool cheia();
  bool vazia();
  void empilha(int e);
  int desempilha();
  int quantidade();
  void imprimir();
  // métodos para mostrar o que está dentro do privado:
  int retornaTopo();
  char retornaItemdoTopo();
};

#endif