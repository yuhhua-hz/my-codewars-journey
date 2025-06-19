/*
How can you tell an extrovert from an introvert at NSA?
Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.

I found this joke on USENET, but the punchline is scrambled. Maybe you can decipher it?
According to Wikipedia, ROT13 is frequently used to obfuscate jokes on USENET.

For this task you're only supposed to substitute characters. Not spaces, punctuation, numbers, etc.

Test examples:

"EBG13 rknzcyr." -> "ROT13 example."

"This is my first ROT13 excercise!" -> "Guvf vf zl svefg EBG13 rkprepvfr!"
*/

#include <string>
#include <cctype>

std::string rot13(const std::string& str) {
  
  std::string output {};
  
  for (size_t i = 0; i < str.size(); ++i) {
    if (isalpha(str[i])) {
      int base = isupper(str[i]) ? 'A' : 'a';
      
      // Obtener la posicion de la letra actual y sumar 13 posiciones
      int offset = (str[i] - base + 13) % 26;
      
      // Escribir la letra con la posicion nueva comenzando desde la base
      output += base + offset;
    } else {
      output += str[i];
    }
  }
  
  return output;
}
