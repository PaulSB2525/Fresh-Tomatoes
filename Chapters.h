//
// Created by paul_ on 07/06/2025.
//

#pragma once
#include "Videos.h"
#ifndef CHAPTERS_H
#define CHAPTERS_H
#include <string>
#include <vector>



class Chapters : public Videos {

    std::string seriesName;
    int chapterNumber;

public:
    Chapters(std::string id, std::string name, int len,std::string genre, std::vector<float> rate, std::string seriesName,int chapterNumber);
    ~Chapters() override;
    std::string show() override;

    int getChapterNumber();
    std::string getSeriesName();
};



#endif //CHAPTERS_H
