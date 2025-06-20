#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include<chrono>
#include<thread>
#include "Videos.h"
#include "Movies.h"
#include "Chapters.h"

int main() {


    //A friend called Victor Velazquez, helped me with the file reading part
    std::vector<Videos*> v;

    std::ifstream file("C:/Users/paul_/OneDrive/Documentos/1. TEC/Segundo Semestre/POO/FINAL/videos.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string currentLine;
    while (std::getline(file, currentLine)) {
        std::stringstream ss(currentLine);

        char type;
        std::string id, name, genre, seriesName;
        int len, chapterNumber;

        ss >> type;
        ss.ignore();

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        ss >> len;
        ss.ignore();
        std::getline(ss, genre, ',');

        if (type == 'p') {
            v.push_back(new Movies(id, name, len, genre, {}));
        }
        else if (type == 'c') {
            std::getline(ss, seriesName, ',');
            ss >> chapterNumber;

            v.push_back(new Chapters(id, name, len, genre, {}, seriesName, chapterNumber));
        }
    }

    file.close();

    int option = 0;

    while (option != 5) {

        std::cout << "----------------------------------" << std::endl;
        std::cout << "          Fresh Tomatoes          " << std::endl; // Inspired by Diego Dominguez(classmate) Logo
        std::cout << "----------------------------------\n" << std::endl;

        std::cout << "Welcome to Fresh Tomatoes...\n" << std::endl;

        std::cout << "1. Show all the catalog" <<std::endl;
        std::cout << "2. Rate a video" <<std::endl;
        std::cout << "3. Show movies and chapters with a minimum grade" <<std::endl;
        std::cout << "4. Show movies and chapters from a certain genre" <<std::endl;
        std::cout << "5. Exit program\n" <<std::endl;

        std::cout << "Choose an option:";
        std::cin >> option;

        if (option == 1) {
            for (auto video : v) {
                std::cout << video->show() << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(10)); // https://stackoverflow.com/a/25808322

        }
        else if (option == 2) {
            std::string id;
            float rating;
            bool found = false;

            std::cout << "===================================" << std::endl;
            std::cout << "Enter the ID of the video you want to rate: ";
            std::cin >> id;
            std::cout << std::endl;
            std::cout << "Enter the rating (0-5): ";
            std::cin >> rating;

            for (auto video : v) {
                if (video->getId() == id) {
                    video->addRating(rating);
                    std::cout << "Rating added successfully!" << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "ID not found in videos" << std::endl;
            }
            std::cout << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(2)); // https://stackoverflow.com/a/25808322

        }
        else if (option == 3) {
            int type;
            float minRating;

            std::cout << "===================================" << std::endl;
            std::cout << std::endl;
            std::cout << "Types of videos:" << std::endl;
            std::cout << "1. Movies" << std::endl;
            std::cout << "2. Chapters" << std::endl;
            std::cout << "3. Both" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter the type of video you want (1-3): ";
            std::cin >> type;

            std::cout << "Enter the minimum rating: ";
            std::cin >> minRating;

            for (auto video : v) {
                bool typeCheck = (type == 1 && dynamic_cast<Movies*>(video)) ||       //Made with the help of copilot
                                 (type == 2 && dynamic_cast<Chapters*>(video)) ||
                                 (type == 3);
                if (video->getAverage() >= minRating && typeCheck && !video->getRate().empty()) {
                    std::cout << "===================================" << std::endl;
                    std::cout << std::endl;
                    std::cout << "ID: " << video->getId() << std::endl;
                    std::cout << "Name: " << video->getName() << std::endl;
                    std::cout << "Rating: " << video->getAverage() << std::endl;
                }
                else {
                    std::cout << "===================================" << std::endl;
                    std::cout << std::endl;
                    std::cout << "No videos found with the specified criteria." << std::endl;
                    std::cout << std::endl;
                    std::cout << "===================================" << std::endl;
                    std::cout << std::endl;
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(5)); // https://stackoverflow.com/a/25808322

        }
        else if (option == 4) {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //https://stackoverflow.com/a/57238338

            int type;
            std::string genre;

            std::cout << "===================================" << std::endl;
            std::cout << std::endl;
            std::cout << "Types of videos:" << std::endl;
            std::cout << "1. Movies" << std::endl;
            std::cout << "2. Chapters" << std::endl;
            std::cout << "3. Both" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter the type of video you want (1-3): ";
            std::cin >> type;

            std::cout << "Enter the genre(Accion, Drama, Comedia, Romance, Ciencia Ficcion, Aventura, Animacion, Biografia): ";
            std::cin.ignore();
            std::getline(std::cin, genre);

            for (auto video : v) {
                bool typeCheck = (type == 1 && dynamic_cast<Movies*>(video)) ||       //Made with the help of copilot and victor
                                 (type == 2 && dynamic_cast<Chapters*>(video)) ||
                                 (type == 3);
                if (typeCheck && video->getGenre() == genre) {
                    std::cout << "===================================" << std::endl;
                    std::cout << std::endl;
                    std::cout << "ID: " << video->getId() << std::endl;
                    std::cout << "Name: " << video->getName() << std::endl;
                    std::cout << "Genre: " << video->getGenre() << std::endl;
                    if (video->getRate().empty()) {
                        std::cout << "Rating: SC" << std::endl;
                    }
                    else {
                        std::cout << "Rating: " << video->getAverage() << std::endl;
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(5)); // https://stackoverflow.com/a/25808322

        }
        else if (option == 5) {
            std::cout << "Exiting program..." << std::endl;
        }
        else {
            std::cout << "Invalid option, please try again." << std::endl;
        }

    }

    for (auto video : v) {
        delete video;
    }

    return 0;
}


