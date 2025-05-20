/*
The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 
*/

#include <string>
#include <algorithm> // std::count
#include <cctype> // tolower()
#include <unordered_map>

std::string convertToLower (std::string word) {
  std::string output {};
  for (auto c : word) {
    c = tolower(c);
    output += c;
   }
  
  return output;
}

// Segunda solucion usando diccionarios de C++
std::string duplicate_encoder(const std::string& word) {
  std::string output(word.size(), '\0');
  std::string copy = convertToLower(word);
  std::unordered_map<char, int>charCounts {};
  
  // Crear un diccionario con el char : numero_de_apariciones
  for (auto c : copy) {
    // Si el char no esta en el dicc entonces agregarlo y poner contador a 1
    if (charCounts.find(c) == charCounts.end()) charCounts[c] = 1;
    // Si ya esta agregada entonces aumentar contador
    else charCounts[c] += 1;
  }
  
  // Ir comprobando char a char con el dicc el contador y segun eso poner el parentesis correspondiente
  for (size_t i {0}; i < copy.size(); ++i) {
    output[i] = (charCounts[copy[i]] > 1) ? ')' : '(';
  }
  
  return output;
  
}




// Primera solucion
/*std::string duplicate_encoder(const std::string& word){
  
  std::string output = word;
  std::string copy {convertToLower(word)};
  
  for (size_t i{0}; i < copy.size(); ++i) {
    auto c = copy[i];
    
    auto charCount = std::count(copy.begin(), copy.end(), c);
    
    output[i] = (charCount > 1) ? ')' : '(';

  }
  
  return output;
}*/