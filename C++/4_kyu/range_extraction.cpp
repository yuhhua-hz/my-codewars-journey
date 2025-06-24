/*
A format for expressing an ordered list of integers is to use a comma separated list of either

individual integers
or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"
Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:

range_extraction((const []){-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}, 23);
returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
*/

#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  
  std::string output {};
  
  int streak {1}; // Empezar en 1 porque 1-2-3 es una racha de 3 y no 2 en caso de empezar en 0
  int current_num {0}, prev_num {0}, start_num {0}, end_num {0};

  for (size_t i = 0; i < args.size(); ++i) {
    if (i == 0) {
      prev_num = args[i];  // Asignar el primer numero como el anterior para comparar posterior
      start_num = args[i]; // Empezar a trackear una racha 
      continue;            // Saltar a la siguiente iteracion
    }
    
    current_num = args[i]; 
    if (current_num == prev_num + 1) {
      streak++;               // Aumentar la racha
      prev_num = current_num; // Actualizar el numero previo
     
    } else {
      // Se rompe la racha procesar las rachas hasta el momento y preparar variables para la siguiente iteracion
      
      end_num = prev_num;     // Marcar el final de la racha con el numero anterior
      
      // Procesar las rachas
      if (!output.empty()) output += ','; // Agregar comas cuando la cadena resultante no este vacia
                                          
      if (streak == 1) {
        output += std::to_string(start_num);
      } else if (streak == 2) {
        output += std::to_string(start_num);
        output += ',';
        output += std::to_string(end_num);
      } else if (streak >= 3) {
        output += std::to_string(start_num);
        output += '-';
        output += std::to_string(end_num);
      }
   
      streak = 1;             // Resetear la racha
      start_num = current_num;// Comenzar una nueva racha con el non el numero actual
      prev_num = current_num; // Actualizar el numero previo
      
    }

    
  }
  
  // Procesar la ultima secuencia. La secuencia de salida del bucle es mediante rachas
  // Entonces esta ultima racha no se procesa ya que finaliza antes el bucle y no se rompe

  end_num = prev_num;     // Marcar el final de la racha con el numero anterior    

  if (!output.empty()) output += ','; // Agregar comas cuando la cadena resultante no este vacia
  // Procesar las rachas                                          
  if (streak == 1) {
    output += std::to_string(start_num);
  } else if (streak == 2) {
    output += std::to_string(start_num);
    output += ',';
    output += std::to_string(end_num);
  } else if (streak >= 3) {
    output += std::to_string(start_num);
    output += '-';
    output += std::to_string(end_num);
  }

  return output;
}
