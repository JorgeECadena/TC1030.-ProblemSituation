#pragma once

#include ".\Video.h"
#include <iostream>
#include <string>

extern int voters;

class Movie : public Video{
    public:
        // Constructors
        Movie();    // Default constructor
        Movie(int id, std::string name, float length, std::string genre);    // Parameterized constructor

        //Destructor
        ~Movie();

        // Getters
        int getVotes(void);
        
        // Setters
        void setVotes(int votes);

        // Methods override
        void getRating(void) override;
        void addVote(unsigned short value) override;
    private:
        // Define class attributes
        int votes = 0;  // Initialize votes as 0
};