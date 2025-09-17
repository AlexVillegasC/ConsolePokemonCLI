#include "Pokemon.h"
#include <sstream>

Pokemon::Pokemon(int id, const std::string& pokeName, int lifePoints, int pokemonLevel, int attackPoints)
    : pokeId(id), name(pokeName), life(lifePoints), level(pokemonLevel), attack(attackPoints) {}

int Pokemon::getPokeId() const {
    return pokeId;
}

std::string Pokemon::getName() const {
    return name;
}

int Pokemon::getLife() const {
    return life;
}

int Pokemon::getLevel() const {
    return level;
}

int Pokemon::getAttack() const {
    return attack;
}

std::string Pokemon::toString() const {
    std::ostringstream oss;
    oss << "ID: " << pokeId << ", Name: " << name << ", Life: " << life
        << ", Level: " << level << ", Attack: " << attack;
    return oss.str();
}