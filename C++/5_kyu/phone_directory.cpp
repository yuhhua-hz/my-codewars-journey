/*
John keeps a backup of his old personal phone book as a text file. On each line of the file he can find the phone number (formated as +X-abc-def-ghij where X stands for one or two digits), the corresponding name between < and > and the address.

Unfortunately everything is mixed, things are not always in the same order; parts of lines are cluttered with non-alpha-numeric characters (except inside phone number and name).

Examples of John's phone book lines:

"/+1-541-754-3010 156 Alphand_St. <J Steeve>\n"

" 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010!\n"

"<Anastasia> +48-421-674-8974 Via Quirinal Roma\n"

Could you help John with a program that, given the lines of his phone book and a phone number num returns a string for this number : "Phone => num, Name => name, Address => adress"

Examples:
s = "/+1-541-754-3010 156 Alphand_St. <J Steeve>\n 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010!\n"

phone(s, "1-541-754-3010") should return "Phone => 1-541-754-3010, Name => J Steeve, Address => 156 Alphand St."
It can happen that there are many people for a phone number num, then return : "Error => Too many people: num"

or it can happen that the number num is not in the phone book, in that case return: "Error => Not found: num"
*/

#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

namespace Ola {
  
  std::vector<std::string> tokenize(const std::string &str, char delimiter) {
  std::vector<std::string> tokens {};
  std::istringstream iss(str);
  std::string token {};

  while (std::getline(iss, token, delimiter)) tokens.push_back(token);

  return tokens;

  }
  
  std::string nameFinder(const std::string &str) {
    std::string name {};
    size_t begin = str.find('<');
    size_t end = str.find('>');
    
    if (begin == std::string::npos || end == std::string::npos) return "";
    
    for (size_t i = begin + 1; i < end; ++i) {
      name += str[i];
    }
    
    return name;
    
  }
  
  std::string removeWord(std::string str, std::string word) {
    
    auto w = str.find(word);
    if (w != std::string::npos) {
      str.erase(w, word.length());
    }
    
    return str;
    
  }
  
  std::string onlyAlphaNum(std::string str) {
    
    std::string output {};
    
    std::replace(str.begin(), str.end(), '_', ' ');
    
    for (auto c : str) {
      if (isalnum(c)) {
        output += c;        
      }
      if (c == ' ' || c == '-' || c == '.') output += c;
    }
    return output;
  }
  
  std::string trimSpaces(const std::string &str) {
    int start = -1;
    int end = -1;
    std::string output;
    
    // Buscar el char que no sea espacio y guardar con el indice
    for (int i = 0; i < str.length(); ++i) {
      if (!isspace(str[i])) {
        start = i;
        break;
      }
    }
    
    // Buscar el char final que no sea espacio y guardar el indice
    for (int i = str.length() - 1; i >= 0; --i) {
      if (!isspace(str[i])) {
        end = i;
        break;
      }
    }
    
    if (start == -1 || end == -1) return "";
    
    
    // Copiar unicamente desde el indice start hasta end
    for (int i = start; i <= end; i++) {
      output += str[i];
    }
    
    return output;
    
  }
  
  std::string removeConsecutiveSpaces(const std::string &str) {
    
    bool wasSpace {false};
    std::string output {};
    
    for (size_t i = 0; i < str.length(); ++i) {
      
      if (!isspace(str[i])) {
        output += str[i];
        wasSpace = false;
      }
      // Agregar el espacio si la ultima letra no fue un espacio
      if (isspace(str[i]) && !wasSpace) {
        output += " ";
        wasSpace = true;
      }
      
    }
    return output;
  }
  
    
} // namespace Ola



class PhoneDir
{
public:
    static std::string phone(const std::string& orgdr, std::string num);
};

std::string PhoneDir::phone(const std::string& orgdr, std::string num)
{
  std::vector<std::string>list_of_string = Ola::tokenize(orgdr, '\n');
  
  int occurrence {0};
  std::string match_line {};
  for (auto line : list_of_string) {
    size_t pos = line.find("+" + num);
    if (pos != std::string::npos) {
      occurrence++;
      match_line = line;
    }
  }
  
  if (occurrence == 0) return "Error => Not found: " + num;
  if (occurrence > 1) return "Error => Too many people: " + num;
  
  // Procesar la linea donde se encontro el match del numero
  if (occurrence == 1) {
      
    // Extraer el nombre
    std::string name  = Ola::nameFinder(match_line);
    std::string output_name = "Name => " + name;
    
    // Extraer el numero
    std::string output_num_phone = "Phone => " + num;
    
    // Eliminar el numero y nombre de la cadena match para procesar luego
    match_line = Ola::removeWord(match_line, num);
    match_line = Ola::removeWord(match_line, name);
    
    // Eliminar letras especiales
    std::string direction = Ola::onlyAlphaNum(match_line);
    // Eliminar espacios delante y detras y espacios consecutivos
    std::string dir_no_spaces = Ola::trimSpaces(direction);
    std::string dir_no_spaces_in_a_row = Ola::removeConsecutiveSpaces(dir_no_spaces);
    
    // Construir la salida de la direccion
    std::string output_direction = "Address => " + dir_no_spaces_in_a_row;
    
    // Construir la salida final
    std::string output = output_num_phone + ", " + output_name + ", " + output_direction;
    
    return output;
    
  }
    
}
