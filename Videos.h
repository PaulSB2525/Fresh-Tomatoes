//
// Created by paul_ on 07/06/2025.
//

#ifndef VIDEOS_H
#define VIDEOS_H
#include <string>
#include <vector>
#include <iostream>


class Videos {

    std::string id;
    std::string name;
    int len;
    std::string genre;
    std::vector<float> rate;

public:

    Videos(std::string id, std::string name, int len,std::string genre, std::vector<float> rate);
    virtual ~Videos();

    void addRating(float rating);
    float getAverage();
    virtual std::string show() = 0;
    //virtual std::ostream& operator<<(std::ostream& os,const Videos& v);


    std::string getId();
    std::string getName();
    int getLen();
    std::string getGenre();
    std::vector<float> getRate();

};



#endif //VIDEOS_H
