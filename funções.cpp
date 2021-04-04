#include "pilha.h"

bool corresponde(char a, char b)
{
  if (a == '{' && b == '}')
    return 1;
  else if (a == '[' && b == ']')
    return 1;
  else if (a == '(' && b == ')')
    return 1;
  else
    return 0;
}

bool checarPont(string s, Pilha c)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      c.empilha(s[i]);
    }
    else if (c.vazia() || !corresponde(c.retornaTopo(), s[i]))
    {
      return false;
    }
    else
    {
      c.desempilha();
    }
  }
  if (c.vazia())
    return true;
  else
    return false;
}

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
  else
    return -1;
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

string toPostfix(string infix)
{
  Pilha st;
  char symbol;
  string postfix = "";
  int d = 0; //Lexical
  int f = 0; //Sintaxe

  for (int i = 0; i < infix.length(); ++i)
  {
    if (prioridade(infix[i]) == 0)
    {
      d++;
      break;
    }
    if (infix[i] == '(')
      f++;
    else if (infix[i] == ')')
      f--;
    else if (infix[i] == '{')
      f++;
    else if (infix[i] == '}')
      f--;
    else if (infix[i] == '[')
      f++;
    else if (infix[i] == ']')
      f--;
  }
  for (int i = 1; i < infix.length(); i++)
  {
    int previous = prioridade(infix[i - 1]);
    int present = prioridade(infix[i]);
    if ((previous >= 1 && previous <= 6) && (present >= 1 && present <= 6))
    {
      f++;
      break;
    }
    if (previous == 10 && present == 10)
    {
      f++;
      break;
    }
  }

  cout << "Valor de f: " << f << endl;
  cout << "Valor de d: " << d << endl;

  if (f == 0 && d == 0)
  {
    for (int i = 0; i < infix.length(); ++i)
    {
      symbol = infix[i];
      if (prioridade(symbol) == 10)
      {
        postfix += symbol;
      }
      else if (symbol == '(')
      {
        st.empilha(symbol);
      }
      else if (symbol == ')')
      {
        while (st.retornaTopo() != '(')
        {
          int d = st.desempilha();
          postfix += to_string(d);
        }
        st.desempilha();
      }
      else
      {
        while (!st.vazia() && !(st.retornaTopo() == '(') && prioridade(symbol) <= prioridade(st.retornaTopo()))
        {
          int d = st.desempilha();
          postfix += to_string(d);
          st.empilha(symbol);
        }
      }
    }
    while (!st.vazia())
    {
      int d = st.desempilha();
      postfix += to_string(d);
    }
  }
  else if (d != 0)
  {
    postfix = "Erro Lexical!";
  }
  else if (f != 0)
  {
    postfix = "Erro Sintático!";
  }

  return postfix;
}