#pragma once
#include <string>

class Pokemon {
private:
    int pokeId;
    std::string name;
    int life;
    int level;
    int attack;

public:
    Pokemon(int id, const std::string& pokeName, int lifePoints, int pokemonLevel, int attackPoints);

    int getPokeId() const;
    std::string getName() const;
    int getLife() const;
    int getLevel() const;
    int getAttack() const;

    std::string toString() const;
};