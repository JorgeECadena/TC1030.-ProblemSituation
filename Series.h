#pragma once

#include "Video.h"
#include "Episode.h"
#include <iostream>
#include <string>
#include <vector>

extern bool seriesOne;
extern bool seriesTwo;

extern int seriesOneVoters;
extern int seriesTwoVoters;

class Series : virtual public Video {
    public:
        // Constructors
        Series();    // Default constructor
        Series(int id, std::string name, float length, std::string genre, std::vector<Episode> episodes);    // Parameterized constructor

        //Destructor
        ~Series();

        // Getters
        int getVotes(void);
        std::vector<Episode> getEpisodes(void);
        
        // Setters
        void setVotes(int votes);
        void setEpisodes(std::vector<Episode> episodes);

        // Series methods
        void addEpisode(Episode episode);

        // Methods override
        void getRating(void) override;
        void addVote(unsigned short value) override;


    private:
        // Define class attributes
        int votes = 0;  // Initialize votes as 0
        std::vector<Episode> episodes; 
};