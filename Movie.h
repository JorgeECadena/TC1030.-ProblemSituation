#pragma once

#include ".\Video.h"
#include <iostream>
#include <string>

class Movie : public Video{
    public:
        // Constructors
        Movie();    // Default constructor
        Movie(int id, std::string name, float length, std::string genre, int votes);    // Parameterized constructor

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
        int votes;
};