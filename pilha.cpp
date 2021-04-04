#include "pilha.h"

Pilha::Pilha()
{}

Pilha::Pilha(int c)
{
  this->pilha = new int(c);
  this->topo = -1;
}

bool Pilha::cheia()
{
  return this->topo == tamanho - 1;
}

bool Pilha::vazia()
{
  return (this->topo == -1);
}

int Pilha::desempilha()
{
  return (this->item[this->topo--]);
}

void Pilha::empilha(int e)
{
  if (cheia())
  {
    return;
  }
  else
  {
    this->item[++this->topo] = e;
  }
}

int Pilha::quantidade(){
  return (this->topo + 1);
}

void Pilha::imprimir()
{
  Pilha aux;

  int element, quant = quantidade();

  cout
      << endl
      << "Sua pilha tem " << quantidade() << " elementos." << endl
      << "E eles são:" << endl;

  for (int i = 0; i < quant; ++i)
  {
    element = desempilha();
    cout << element << endl;
    aux.empilha(element);
  }

  for (int i = 0; i < quant; i++)
  {
    element = aux.desempilha();
    empilha(element);
  };
}

char Pilha::retornaItem(int e){
  return this->item[e];
}

int Pilha::retornaTopo(){
  if(!vazia()) {
    return this->topo;
  }
  else{
    return -1;
  }
}
