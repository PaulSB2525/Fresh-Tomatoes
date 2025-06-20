//
// Created by paul_ on 07/06/2025.
//

#include "Videos.h"
#ifndef MOVIES_H
#define MOVIES_H



class Movies : public Videos {

public:
    Movies(std::string id, std::string name, int len,std::string genre, std::vector<float> rate);
    ~Movies() override;
    std::string show() override;

};



#endif //MOVIES_H
