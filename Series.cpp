#include ".\Series.h"
#include ".\Episode.h"
#include <iostream>
#include <string>
#include <vector>

/*
* Default constructor, sets every attribute as a NULL value
*/
Series :: Series() : Video(), votes(NULL), episodes(NULL) {

}

/*
* Parameterized constructor, receives int id, string name, float length, 
* string genre, int votes, vector<Episode> episodes to set the class attributes
*/
Series :: Series(int id, std::string name, float length, std::string genre, int votes, std::vector<Episode> episodes) :
Video(id, name, length, genre), votes(votes), episodes(episodes) {

}

/*
* Series destructor
*/
Series :: ~Series() {

}

/*
* Returns class int votes
*/
int Series :: getVotes(void) {
    return votes;
}

/*
* Returns class vector<Episode> episodes
*/
std::vector<Episode> Series :: getEpisodes(void) {
    return episodes;
}


/*
* Set the votes attribute value to the given int value
*/
void Series :: setVotes(int votes) {
    this -> votes = votes;
}

/*
* Set the episodes attribute value to the given vector<Episode> value
*/
void Series :: setEpisodes(std::vector<Episode> episodes) {
    this -> episodes = episodes;
}
