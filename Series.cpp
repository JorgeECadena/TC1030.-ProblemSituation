#include ".\Series.h"
#include ".\Episode.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Default constructor sets every attribute to empty values
 * 
 * @return Series 
 */
Series :: Series() : Video() {

}

/**
 * @brief Parameterized constructor turns attributes values into the received parameters 
 * 
 * @param id 
 * @param name 
 * @param length 
 * @param genre 
 * @param episodes 
 * @return Series 
 */
Series :: Series(int id, std::string name, float length, std::string genre, std::vector<Episode> episodes) :
Video(id, name, length, genre), episodes(episodes) {

}

/**
 * @brief Series destructor
 * 
 * @return Series 
 */
Series :: ~Series() {

}

/**
 * @brief Get the votes attribute
 * 
 * @return int 
 */
int Series :: getVotes(void) {
    return votes;
}

/**
 * @brief Get the Episodes vector
 * 
 * @return std::vector<Episode> 
 */
std::vector<Episode> Series :: getEpisodes(void) {
    return episodes;
}


/**
 * @brief Set the votes attribute
 * 
 * @param votes 
 */
void Series :: setVotes(int votes) {
    this -> votes = votes;
}

/**
 * @brief Set the Episodes vector
 * 
 * @param episodes 
 */
void Series :: setEpisodes(std::vector<Episode> episodes) {
    this -> episodes = episodes;
}

/**
 * @brief Add episodes to the episodes vector
 * 
 * @param episode 
 */
void Series :: addEpisode(Episode episode) {
    this -> episodes.push_back(episode);
}

/**
 * @brief Overrided method doesn't do anything yet on the son class
 * 
 */
void Series :: getRating(void) {
    int actualVotes = this -> getVotes();
    float rating;
    if(seriesOne == true) {
        rating = actualVotes / seriesOneVoters;
    } else if(seriesTwo == true) {
        rating = actualVotes / seriesTwoVoters;
    }

    std::cout << "Series " << this -> getName() << " Rating is: " << rating << std::endl;
}

/**
 * @brief Overrided method doesn't do anything yet on the son class
 * 
 * @param value 
 */
void Series :: addVote(unsigned short value) {
    int actualVotes = this -> getVotes();
    int votesSum = actualVotes + value;

    this -> setVotes(votesSum);
}