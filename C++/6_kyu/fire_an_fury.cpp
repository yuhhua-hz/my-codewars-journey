/*
The President's phone is broken
He is not very happy.

The only letters still working are uppercase E, F, I, R, U, Y.

An angry tweet is sent to the department responsible for presidential phone maintenance.

Kata Task
Decipher the tweet by looking for words with known meanings.

FIRE = "You are fired!"
FURY = "I am furious."
If no known words are found, or unexpected letters are encountered, then it must be a "Fake tweet."

Notes
The tweet reads left-to-right.
Any letters not spelling words FIRE or FURY are just ignored
If multiple of the same words are found in a row then plural rules apply -
FIRE x 1 = "You are fired!"
FIRE x 2 = "You and you are fired!"
FIRE x 3 = "You and you and you are fired!"
etc...
FURY x 1 = "I am furious."
FURY x 2 = "I am really furious."
FURY x 3 = "I am really really furious."
etc...
Examples
ex1. FURYYYFIREYYFIRE = "I am furious. You and you are fired!"
ex2. FIREYYFURYYFURYYFURRYFIRE = "You are fired! I am really furious. You are fired!"
ex3. FYRYFIRUFIRUFURE = "Fake tweet."
*/

#include <string>

std::string convertFire(int count) {
  std::string output {};
  
  if (count == 1) return "You are fired!";
  
  for (int i = 0; i < count; ++i) {
    
    if (i == 0) output += "You";
    else output += "you";
    
    if (i < count - 1) output += " and ";
  }
  
  return output + " are fired!";
}

std::string convertFury(int count) {
  std::string output {};
  
  if (count == 1) return "I am furious.";
    
  for (int i = 0; i < count - 1; ++i) {
    output += "really ";
  }
  
  return "I am " + output + "furious."; 
  
}

std::string fire_and_fury(const std::string& tweet) {
  
  std::string cleanString {};  
  for (size_t i = 0; i < tweet.size(); ++i) {
    switch (tweet[i]) {
        case 'E':
        case 'F':
        case 'I':
        case 'R':
        case 'U':
        case 'Y':
          cleanString += tweet[i];
          break;
        default:
          return "Fake tweet.";
    }
  }
  
  if (cleanString.empty()) return "Fake tweet.";
    
  // Recorrer la cadea limpia, en busca de la palabra valida
  // Si forman palabra valida, empezar a mirar la siguiente letra desde 4 posiciones adelante
  // Agregar la palabra valida a la pila para procesar luego
  std::vector<std::string>f_stack {};  
  for (size_t i = 0; i <= cleanString.size() - 4; ++i) {
    
    std::string fireOrFury = cleanString.substr(i, 4);
        
    if (fireOrFury == "FIRE" || fireOrFury == "FURY") {
      f_stack.push_back(fireOrFury);
      i = i + 3; // Aumentar en 3 ya que el for incrementa ya en 1
    }
  }
  
  // No hay ninguna palabra valida entonces retornar
  if (f_stack.empty()) return "Fake tweet.";
  
  std::string currentWord {};
  std::string output {}; 
  int count {0};
  for (size_t i = 0; i < f_stack.size(); ++i) {
    // Inicialmente esta vacio esta vacio entonces agregar palabra de la pila
    if (currentWord.empty()) {
      currentWord += f_stack[i];
      count++;
    } else {
      // Si no esta vacio entonces comparar la palabra actual para ver si es la misma
      // Si se ha roto la racha entonces procesar y montar la salida hasta el momento  
      if (currentWord == f_stack[i]) count++;
      else {
        if (currentWord == "FIRE") {
          if (!output.empty()) output += " "; // Agregar espacio cuando se rompe la racha
          output += convertFire(count);
        } else if (currentWord == "FURY") {
          if (!output.empty()) output += " ";
          output += convertFury(count);
        }
       
        currentWord = f_stack[i];
        count = 1;
        
      }    
      
    }
    
  }
  
  // Procesar la ultima secuencia
  if (currentWord == "FIRE") {
    if (!output.empty()) output += " ";
    output += convertFire(count);
  } else if (currentWord == "FURY") {
    if (!output.empty()) output += " ";
    output += convertFury(count);
  }
  
  return output;
  
}
