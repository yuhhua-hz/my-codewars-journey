/*
Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

Examples
pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !
*/

#include <cctype>

std::string pig_it(std::string str)
{
  std::string output{};
  std::string currentWord {};
  char firstLetter {};
  bool inWord {false};
  
  for (size_t i {0}; i < str.size(); ++i) {
    
    // Si estamos ante una letra
    if (isalpha(str[i])) {
      if(!inWord) {
        inWord = true;              // Activar bandera de dentro de una palabra
        firstLetter = str[i];       // Guardar la primera letra para luego
        currentWord = "";           // Inicializar/resetear la cadena temporal
      } 
      else currentWord += str[i];   // Agregar el resto de letras a la cadena temporal
    } // Si estamos ante una NO letra (espacio o signo puntuacion)
    else {
      if (inWord) {
        inWord = false;             // Desactivar la bandera dentro de una palabra
        output += currentWord + firstLetter + "ay"; // Construir la palabra y agregarlo a la salida
      }
      output += str[i];             // Agregar el char actual NO letra a la salida
    }

  }
  
  // Procesar la ultima palabra para los casos de que no haya espacios o signo puntuacion
  if (inWord) {
    output += currentWord + firstLetter + "ay";
  }
  
  return output;
  
}