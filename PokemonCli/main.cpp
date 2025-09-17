#include <iostream>
#include "Pokemon.h"
#include "FileReader.h"

int main() {
    FileReader fileReader("pokemon.txt");

    auto pokemonList = fileReader.readPokemonFromFile();

    std::cout << "Pokemon loaded from file:" << std::endl;
    for (const auto& pokemon : pokemonList) {
        std::cout << pokemon.toString() << std::endl;
    }

    return 0;
}