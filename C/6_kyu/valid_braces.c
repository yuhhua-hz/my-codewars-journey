/*
Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.

Examples
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False
*/

#include <stdbool.h>

#define MAX_TAM 1000

bool valid_braces (const char *braces)
{
  char stack[MAX_TAM] = {0};
  int sp = 0;
  
  int i = 0;
  while (*(braces + i) != '\0') {
    // Si es una apertura agregarlo a la pila
    if ( braces[i] == '{' || braces[i] == '[' || braces[i] == '(') {
      stack[sp] = braces[i];
      sp++; // Apunta al siguiente espacio libre
    // Si es un cierre
    } else if (braces[i] == '}' || braces[i] == ']' || braces[i] == ')') {
      if (sp == 0) { // Y la pila esta vacia devolver false
        return false;
      } else {       // Si la pila no esta a 0 y pueden formar parejas
        // Forma parejas entonces decrementar la pila
        if (braces[i] == '}' && stack[sp - 1] == '{') sp--;
        else if (braces[i] == ']' && stack[sp - 1] == '[') sp--;
        else if (braces[i] == ')' && stack[sp - 1]  == '(') sp--;
        else return false; // No ha encontrado una pareja valida entonces false
      }
    }
    i++; // Procesar siguiente char
  }
  if (sp == 0) return true;
  else return false;
}