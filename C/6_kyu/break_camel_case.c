/*
Complete the solution so that the function will break up camel casing, using a space between words.

Example
"camelCasing"  =>  "camel Casing"
"identifier"   =>  "identifier"
""             =>  ""
*/

#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

char* solution(const char *camelCase) {
  
  char* output = malloc(100 * sizeof(char));
  
  if (output == NULL) return NULL;
  
  if (*camelCase == '\0') {
    output[0] = '\0';
    return output;
  }
  
  int i = 0, j = 0;
  while (*(camelCase + i) != '\0') {
    
    if (islower(camelCase[i])) {
      output[j] = camelCase[i];
      j++;
    } else if(isupper(camelCase[i])) {
      output[j++] = 32;
      output[j] = camelCase[i];
      j++;
    }
    i++;
  }
  *(output + j) = 0;
  
  return output;
}
