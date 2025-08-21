/*
In this kata, you have an input string and you should check whether it is a valid message. To decide that, you need to split the string by the numbers, and then compare the numbers with the number of characters in the following substring.

For example "3hey5hello2hi" should be split into 3, hey, 5, hello, 2, hi and the function should return true, because "hey" is 3 characters, "hello" is 5, and "hi" is 2; as the numbers and the character counts match, the result is true.

Notes:

    Messages are composed of only letters and digits
    Numbers may have multiple digits: e.g. "4code13hellocodewars" is a valid message
    Every number must match the number of character in the following substring, otherwise the message is invalid: e.g. "hello5" and "2hi2" are invalid
    If the message is an empty string, you should return true
*/

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isAValidMessage(const char* msg){  
  
  // Caso vacio -> es valido
  if (*msg == '\0') return true;
    
  // Caso cadena empieza con letra
  if (isalpha(*msg)) return false;
  
  char num_str[5];
  int num, i = 0, k = 0;
  while (*(msg + i) != '\0') {
    while (isdigit(*(msg + i))) {
      num_str[k++] = *(msg + i);
      i++;
    }
    
    *(num_str + k) = '\0';    // Terminar la cadena num_str
    num = atoi(num_str);      // Convertirlo a numero
    memset(num_str, 0, 5);    // Reset para la siguiente iteracion
    k = 0;                    // Reset
    
    // Contar las letras tras el numero
    int char_count = 0;
    while (isalpha(*(msg + i))) {
      char_count++;
      i++;
    }
    
    // Validar
    if (num != char_count) return false;
  }
  
  return true;
    
}
