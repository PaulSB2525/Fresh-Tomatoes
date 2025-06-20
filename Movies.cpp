//
// Created by paul_ on 07/06/2025.
//

#include "Movies.h"

Movies::Movies(std::string id, std::string name, int len,std::string genre, std::vector<float> rate) : Videos(id, name, len, genre, rate) {}

Movies::~Movies() {}

std::string Movies::show() {

    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Length: " << getLen() << " minutes" << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Rating: ";
    if (getRate().empty()) {
        std::cout << "SC" << std::endl;
    }
    else {
        std::cout << getAverage() << std::endl;
    }
    return "";
}
