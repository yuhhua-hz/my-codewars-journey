/*
Create a function which accepts one arbitrary string as an argument, and return a string of length 26.

The objective is to set each of the 26 characters of the output string to either '1' or '0' based on the fact whether the Nth letter of the alphabet is present in the input (independent of its case).

So if an 'a' or an 'A' appears anywhere in the input string (any number of times), set the first character of the output string to '1', otherwise to '0'. if 'b' or 'B' appears in the string, set the second character to '1', and so on for the rest of the alphabet.

For instance:

"a   **&  cZ"  =>  "10100000000000000000000001"

"aaaaaaa79345675"  =>  "10000000000000000000000000"

"&%#*"  =>  "00000000000000000000000000"
*/

#include <stdlib.h>
#include <string.h> // memset
#include <ctype.h> // isalpha(), tolower()


char *change(const char *str_in) {

  char *output = malloc(sizeof(char)*27);
  if (!output) return NULL;
  
  memset(output, '0', 26);
  
  size_t i = 0, alpha_index = 0;
  char c, last_char = '\0';
  while ((c = *(str_in + i)) != '\0') {
    
    // Usar lastChar para detectar casos de char iguales consecutivos
    if (isalpha(c) && c != last_char) {
      // Obtener el indice del char actual
      c = tolower(c);
      alpha_index = c - 'a';
      last_char = c;
      // Escribir en string de salida + posicion del indice obtenida un 1
      *(output + alpha_index) = '1';
    } else last_char = '\0'; // Reiniciar last_char si no es un alfa
    i++;

  }
  *(output+26) = '\0';
  
  return output;
}
