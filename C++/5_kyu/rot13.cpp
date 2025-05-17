/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/

#include <string>
#include <cctype>

std::string rot13(std::string msg) {
  
  std::string output;
  output.reserve(msg.size());
  
  for (auto c : msg) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      // formula para obtener el desplazamiento correspondiente
      // si c = b(98) - 97 = 1(indice) + 13 = 14 % 26 = 14 + 97 = 111(n)
      // si c = y(121) - 97 = 24(indice) + 13 = 37 % 26 = 11 + 97 = 108(l)
      output += (c - base + 13) % 26 + base;
    } else output += c;
  }
  
  return output;
}


// Version sin optimizar
/*
std::string rot13(std::string msg)
{
  std::string output (msg.size(), '\0');

  
  for (size_t i {0}; i < msg.length(); ++i) {
    
    if (isupper(msg[i])) {
      if (msg[i] >= 'A' and msg[i] <= 'M') {
        output[i] = msg[i] + 13;

      } else if (msg[i] >= 'N' and msg[i] <= 'Z') {
        output[i] = msg[i] - 13;

      }
    }
    else if (islower(msg[i])) {
      if (msg[i] >= 'a' and msg[i] <= 'm') {
        output[i] = msg[i] + 13;

      } else if (msg[i] >= 'n' and msg[i] <= 'z') {
        output[i] = msg[i] - 13;

      } 
    }
    if (!isalpha(msg[i])) output[i] = msg[i];
  }
  return output;
}
*/