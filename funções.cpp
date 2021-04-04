#include "pilha.h"

int prioridade(char x)
{
  if (x == '|')
    return 1;
  else if (x == '.')
    return 2;
  else if (x == '>' || x == '<' || x == '=' || x == '#')
    return 3;
  else if (x == '+' || x == '-')
    return 4;
  else if (x == '*' || x == '/')
    return 5;
  else if (x == '^')
    return 6;
  else if (x == '(' || x == ')')
    return 7;
  else if (((int)x >= 48 && (int)x <= 57) || ((int)x >= 65 && (int)x <= 90) || ((int)x >= 97 && (int)x <= 122))
    return 10;
  else
    return 0;
}

bool Operador(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '|' || c == '.' || c == '>' || c == '<' || c == '=' || c == '#')
    return true;
  else
    return false;
}

bool caracter(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    return true;
  else
    return false;
}

string toPostfix(string infixo)
{
  Pilha pilha(1000);
  char simbolo;
  string posfixo = "";
  int l = 0; //Lexical
  int s = 0; //Sintaxe

  for (int i = 0; i < infixo.length(); ++i)
  {
    if (prioridade(infixo[i]) == 0)
    {
      l++;
      break;
    }
    if (infixo[i] == '(')
      s++;
    else if (infixo[i] == ')')
      s--;
    else if (infixo[i] == '{')
      s++;
    else if (infixo[i] == '}')
      s--;
    else if (infixo[i] == '[')
      s++;
    else if (infixo[i] == ']')
      s--;
  }
  for (int i = 1; i < infixo.length(); i++)
  {
    int anterior = prioridade(infixo[i - 1]);
    int atual = prioridade(infixo[i]);
    if ((anterior >= 1 && anterior <= 6) && (atual >= 1 && atual <= 6))
    {
      s++;
      break;
    }
    if (anterior == 10 && atual == 10)
    {
      s++;
      break;
    }
  }

  if (l == 0 && s == 0)
  {
    for (int i = 0; i < infixo.length(); ++i)
    {
      simbolo = infixo[i];
      if (caracter(simbolo))
      {
        posfixo += simbolo;
      }
      else if (simbolo == '(')
      {
        pilha.empilha(simbolo);
      }
      else if (simbolo == ')')
      {
        while (char(pilha.retornaItemdoTopo()) != '(')
        {
          posfixo += to_string(pilha.desempilha());
        }
        pilha.desempilha();
      }
      else
      {
        while (!pilha.vazia() && !(char(pilha.retornaItemdoTopo()) == '(') && prioridade(simbolo) <= prioridade(char(pilha.retornaItemdoTopo())))
        {
          posfixo += to_string(pilha.desempilha());
          pilha.empilha(simbolo);
        }
      }
    }
    while (!pilha.vazia())
    {
      posfixo += to_string(pilha.desempilha());
    }
  }
  else if (l != 0)
  {
    posfixo = "Erro Lexical!";
  }
  else if (s != 0)
  {
    posfixo = "Erro Sintático!";
  }

  return posfixo;
}
