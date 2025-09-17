#pragma once
#include <vector>
#include <string>
#include "Pokemon.h"

class FileReader {
private:
    std::string filename;

public:
    FileReader(const std::string& file);

    std::vector<Pokemon> readPokemonFromFile();
    bool writeAllPokemonToFile(const std::vector<Pokemon>& pokemonList);
};