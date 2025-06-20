//
// Created by paul_ on 07/06/2025.
//

#include "Videos.h"

Videos::Videos(std::string id,std::string name, int len, std::string genre, std::vector<float> rate) : id(id), name(name), len(len), genre(genre), rate(rate){}

void Videos::addRating(float rating) {
    rate.push_back(rating);
}

float Videos::getAverage() {
    float sum = 0.0;

    for (float r : rate) {
        sum += r;
    }
    return sum / rate.size();
}

std::string Videos::show() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Length: " << len << " minutes" << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Rating: ";
    if (rate.empty()) {
        std::cout << "SC" << std::endl;
    }
    else {
        std::cout << getAverage() << std::endl;
    }
    return "";
}

/*
std::ostream& operator<<(std::ostream& os, Videos& v) {

    os << v.show();
    return os;
    }
*/


std::string Videos::getId() {
    return id;
}
std::string Videos::getName() {
    return name;
}
int Videos::getLen() {
    return len;
}
std::string Videos::getGenre() {
    return genre;
}
std::vector<float> Videos::getRate() {
    return rate;
}

Videos::~Videos() {}
