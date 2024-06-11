#pragma once

#include <iostream>
#include <string>

class Episode {
    public:
        // Constructors
        Episode();    // Default constructor
        Episode(int id, std::string title, float length, unsigned short number, unsigned short season);    // Parameterized constructor

        //Destructor
        ~Episode();

        // Getters
        int getId(void);
        std::string getTitle(void);
        float getLength(void);
        unsigned short getNumber(void);
        unsigned short getSeason(void);
        
        // Setters
        void setId(int id);
        void setTitle(std::string title);
        void setLength(float length);
        void setNumber(unsigned short number);
        void setSeason(unsigned short season);
                 
    private:
        // Define class attributes
        float length;
        std::string title;
        int id;
        unsigned short number;
        unsigned short season;
        
};