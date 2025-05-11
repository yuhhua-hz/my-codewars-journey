/*
Write a function that takes in a string of one or more words, and returns the same string, but with all words that have five or more letters reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

Examples:

"Hey fellow warriors"  --> "Hey wollef sroirraw" 
"This is a test        --> "This is a test" 
"This is another test" --> "This is rehtona test"
*/

#include <algorithm>  // std::reverse
#include <sstream>    // std::istringstream
#include <string>

std::string spinWords(const std::string &str)
{
  bool isFirst {true};
  std::string rts {};           // String resultante
  std::istringstream iss(str);  // Tokenizar por espacio
  std::string token;            // Var para guarda los token de palabras
  
  while (iss >> token) {
    // Comprobar si el token de palabra es superior a 5
    if (token.length() >= 5) {
      std::reverse(token.begin(), token.end()); // Revertir
    }
    
    // Si no es la primera palabra, entonces agregar espacios
    if (!isFirst) rts += ' ';
    else isFirst = false; // Apagar la bandera despues de haber procesado
    
    rts += token; // Agregar el token de palabra al string resultante
  }
  
  return rts;
   
}
