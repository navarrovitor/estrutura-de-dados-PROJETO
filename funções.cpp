#include "pilha.h"

bool corresponde(char a, char b){
  if(a == '{' && b == '}')
    return 1;
  else if(a == '[' && b == ']')
    return 1;
  else if(a == '(' && b == ')')
    return 1;
  else
    return 0;
}

bool checarPont(string s, Pilha c){
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      c.empilha(s[i]);
        } else if (c.vazia() || !corresponde(c.valTopo(),s[i])) {
            return false;
        } else {
            c.desempilha();
        }
    }
    if(c.vazia()) return true;
    else return false;
}