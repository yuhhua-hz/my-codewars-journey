/*
Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"

"The_Stealth_Warrior" gets converted to "TheStealthWarrior"

"The_Stealth-Warrior" gets converted to "TheStealthWarrior"

*/

#include <stdbool.h>
#include <ctype.h>

void to_camel_case(const char *text, char *camel) {

  bool es_delimitador = false; // Bandera de control
  int i = 0, j = 0; // Var control para text, camel
  
  for (; text[i] != '\0'; ++i, ++j) {
    
    // Copiar char src a dst
    camel[j] = text[i];
    
    // Si el char actual es un delimitador, activar la bandera
    if ( text[i] == '_' || text[i] == '-') es_delimitador = true;
    
    // Si la bandera esta activa, entonces el char siguiente debe ser una mayus
    if (es_delimitador) {
      // Comprobar si el char siguiente ya es una mayus, entonces solamente copia
      if (isupper(text[i+1])) {
        camel[j] = text[i+1];
        i++; // Aumentar a la siguiente pos para evitar copiar 2 veces
        es_delimitador = false;
      // Si el char siguiente es una minus, entonces convertir a mayus
      } else {
        camel[j] = text[i+1];
        camel[j] = camel[j] - 32;
        i++; // Aumentar a la pos para evitar copiar 2 veces
        es_delimitador = false; 
      }

    }
    
  }  
  camel[j] = 0; // Formalizar string de salida
  
}
