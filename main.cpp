#include "pilha.h"
#include "func.h"

int main()
{
  string infixo;
  cout << "Entre com a expressão: ";
  cin >> infixo;
  cout << "A expressão fica: " << toPostfix(infixo) << endl;

  return 0;
}
