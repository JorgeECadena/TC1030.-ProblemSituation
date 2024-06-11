#pragma once

#include "Video.h"
#include <iostream>
#include <string>

class Episode {
    public:
        // Constructors
        Episode();    // Default constructor
        Episode(int id, std::string title, float lenght, unsigned short number, unsigned short season);    // Parameterized constructor

        //Destructor
         ~Episode();

        // Getters
        int getId(void);
        std::string getTitle(void);
        float getLenght(void);
        unsigned short getNumber(void);
        unsigned short getSeason(void);
        
        // Setters
        void setId(int id);
        void setTitle(std::string title);
        void setLenght(float lenght);
        void setNumber(unsigned short number);
        void setSeason(unsigned short season);
         

        
    private:
        // Define class attributes
        float lenght;
        std::string title;
        int id;
        unsigned short number;
        unsigned short season;
        
};