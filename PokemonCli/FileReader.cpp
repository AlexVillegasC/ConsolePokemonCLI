#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileReader::FileReader(const std::string& file) : filename(file) {}

std::vector<Pokemon> FileReader::readPokemonFromFile() {
    std::vector<Pokemon> pokemonList;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return pokemonList;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 5) {
            try {
                int id = std::stoi(tokens[0]);
                std::string name = tokens[1];
                int life = std::stoi(tokens[2]);
                int level = std::stoi(tokens[3]);
                int attack = std::stoi(tokens[4]);

                pokemonList.emplace_back(id, name, life, level, attack);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error parsing line: " << line << std::endl;
            }
        }
    }

    file.close();
    return pokemonList;
}

bool FileReader::writeAllPokemonToFile(const std::vector<Pokemon>& pokemonList) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing" << std::endl;
        return false;
    }

    for (const auto& pokemon : pokemonList) {
        file << pokemon.getPokeId() << ","
             << pokemon.getName() << ","
             << pokemon.getLife() << ","
             << pokemon.getLevel() << ","
             << pokemon.getAttack() << std::endl;
    }

    file.close();
    return true;
}