#pragma once

#include "Video.h"
#include "Episode.h"
#include <iostream>
#include <string>
#include <vector>

class Series : public Video {
    public:
        // Constructors
        Series();    // Default constructor
        Series(int id, std::string name, float length, std::string genre, int votes, std::vector<Episode> episodes);    // Parameterized constructor

        //Destructor
        ~Series();

        // Getters
        int getVotes(void);
        std::vector<Episode> getEpisodes(void);
        
        // Setters
        void setVotes(int votes);
        void setEpisodes(std::vector<Episode> episodes);

        // Methods override
        void getRating(void) override;
        void addVote(unsigned short value) override;
        void addEpisode(Episode episode);


    private:
        // Define class attributes
        int votes;
        std::vector<Episode> episodes; 
};