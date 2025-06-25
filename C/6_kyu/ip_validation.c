/*
Write an algorithm that will identify valid IPv4 addresses in dot-decimal format. IPs should be considered valid if they consist of four octets, with values between 0 and 255, inclusive.

Valid inputs examples:
Examples of valid inputs:
1.2.3.4
123.45.67.89
Invalid input examples:
1.2.3
1.2.3.4.5
123.456.78.90
123.045.067.089
Notes:
Leading zeros (e.g. 01.02.03.04) are considered invalid
Inputs are guaranteed to be a single string
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool only_digit(char *token) {
  int i = 0;
  while(token[i] != '\0') {
    if (!isdigit(token[i])) return false;
    i++;
  }
  return true;
}

bool numeric_range(char* token) {
  int temp = 0;
  
  // Si el token esta vacio retornar inmediato, sino convertirlo a entero
  if (*token == '\0') return false;
  else temp = atoi(token);
  
  // Verificar si la longitud del token es mayor 1 y si la primera letra es un 0
  size_t token_len = strlen(token);
  if (token_len > 1 && *token == '0') {
    return false;
  }
  
  // Verificar el rango
  if (temp < 0 || temp > 255) {
    return false;
  }
  return true;
}

bool is_valid_ip(const char *addr)
{
  
  // Validar que no empiece y acabe por .
  if (*addr == '.') return false;
 
  size_t addr_len = strlen(addr);
  
  if (*(addr + addr_len - 1) == '.') return false;
  
  char *addr_copy = malloc((addr_len + 1) * sizeof(char));
  
  if (addr_copy == NULL) return false;
  
  int i = 0;
  while(addr[i] != '\0') {
    addr_copy[i] = addr[i];
    i++;
  }
  addr_copy[i] = '\0';
  
  const char *delimiter = ".";
  int token_count = 0;
  
  char *token = strtok(addr_copy, delimiter);
  
  while (token != NULL) {
    token_count++;
    
    if (!only_digit(token)) {
      free(addr_copy);
      return false;
    }
    
    if (!numeric_range(token)) {
      free(addr_copy);
      return false;
    }
    
    token = strtok(NULL, delimiter);
  }
  
  if (token_count != 4) {
    free(addr_copy);
    return false;
  }
  
  free(addr_copy);
  
  return true;
}
