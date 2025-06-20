//
// Created by paul_ on 07/06/2025.
//

#include "Chapters.h"

Chapters::Chapters(std::string id, std::string name, int len,std::string genre, std::vector<float> rate, std::string seriesName,int chapterNumber) : Videos(id, name, len, genre, rate), chapterNumber(chapterNumber), seriesName(seriesName) {}

std::string Chapters::show() {
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Length: " << getLen() << " minutes" << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Series Name: " << seriesName << std::endl;
    std::cout << "Chapter Number: " << chapterNumber << std::endl;
    std::cout << "Rating: ";
    if (getRate().empty()) {
        std::cout << "SC" << std::endl;
    }
    else {
        std::cout << getAverage() << std::endl;
    }
    return "";
}

Chapters::~Chapters() {}

int Chapters::getChapterNumber() {
    return chapterNumber;
}
std::string Chapters::getSeriesName() {
    return seriesName;
}
