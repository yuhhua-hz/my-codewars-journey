/*
It's a Pokemon battle! Your task is to calculate the damage that a particular move would do using the following formula (not the actual one from the game):

damage = 50 * (attack / defense) * effectiveness
Where:

attack = your attack power
defense = the opponent's defense
effectiveness = the effectiveness of the attack based on the matchup (see explanation below)
Effectiveness:

Attacks can be super effective, neutral, or not very effective depending on the matchup. For example, water would be super effective against fire, but not very effective against grass.

Super effective: 2x damage
Neutral: 1x damage
Not very effective: 0.5x damage
To prevent this kata from being tedious, you'll only be dealing with four types: fire, water, grass, and electric. Here is the effectiveness of each matchup:

fire > grass

fire < water

fire = electric

water < grass

water < electric

grass = electric

For this kata, any type against itself is not very effective. Also, assume that the relationships between different types are symmetric (if A is super effective against B, then B is not very effective against A).

The function you must implement takes in:

1. your type
2. the opponent's type
3. your attack power
4. the opponent's defense
*/

#include <string.h>

enum {
  FIRE = 0,
  WATER,
  GRASS,
  ELECTRIC
};

int type_enum_conversion(const char* type) {
  
  if (strcmp(type, "fire") == 0) return FIRE;
  if (strcmp(type, "water") == 0) return WATER;
  if (strcmp(type, "grass") == 0) return GRASS;
  if (strcmp(type, "electric") == 0) return ELECTRIC;
  
}

float type_effectiveness(const char* my_type, const char* opponent_type) {
  
  int my_type_e = type_enum_conversion(my_type);
  int opponent_type_e = type_enum_conversion(opponent_type);
  
  switch(my_type_e) {
      case FIRE:
        switch(opponent_type_e) {
            case FIRE: return 0.5;
            case GRASS: return 2.0;
            case ELECTRIC: return 1.0;
            case WATER: return 0.5;
        }
      case WATER:
        switch(opponent_type_e) {
            case WATER: return 0.5;
            case FIRE: return 2.0;
            case ELECTRIC: return 0.5;
            case GRASS: return 0.5;
        }
      case GRASS:
        switch(opponent_type_e) {
            case GRASS: return 0.5;
            case WATER: return 2.0;
            case ELECTRIC: return 1.0;
            case FIRE: return 0.5;
        }
      case ELECTRIC:
        switch(opponent_type_e) {
            case ELECTRIC: return 0.5;
            case WATER: return 2.0;
            case FIRE: return 1.0;
            case GRASS: return 1.0;
        }  
      
  }
  
}

int calculate_damage(const char *your_type, const char *opponent_type, int attack, int defense) {

  float effectiveness = type_effectiveness(your_type, opponent_type);
  
  int damage = 50 * (attack / defense) * effectiveness;
  
  return damage;
}
