/*
In this example you have to validate if a user input string is alphanumeric. The given string is not nil/null/NULL/None, so you don't have to check that.

The string has the following conditions to be alphanumeric:

At least one character ("" is not valid)
Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
No whitespaces / underscore
*/

#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_alphanum(const char* str, size_t str_len) {
    
  for (size_t i = 0; i < str_len; ++i) {
    if (!isalnum(str[i])) return false;
  }
  return true;
}

bool alphanumeric(const char *str_in) {
  
  size_t len = strlen(str_in);
  
  if (len == 0) return false;
  
  bool output = is_alphanum(str_in, len);
  
  return output;

}
