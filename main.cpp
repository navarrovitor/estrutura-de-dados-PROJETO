#include "pilha.h"
#include "funções.cpp"

int main()
{
  string infix;
  cout << "entre com a expressão: " << endl;
  cin >> infix;
  cout << toPostfix(infix);
  return 0;
}
