#include ".\Series.h"

/*
* Default constructor, sets every attribute as a NULL value
*/
Series :: Series() : Video(), votes(NULL), episodes(NULL) {

}

/*
* Parameterized constructor, receives int id, string name, float length, 
* string genre to set the class attributes
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
* Returns class int id
*/
int Series :: getVotes(void) {
    return votes;
}

/*
* Returns class string name
*/
std::vector<Episode> Series :: getEpisodes(void) {
    return episodes;
}


/*
* Set the id attribute value to the given int value
*/
void Series :: setVotes(int votes) {
    this -> votes = votes;
}

/*
* Set the name attribute value to the given string value
*/
void Series :: setEpisodes(vector episodes) {
    this -> episodes = episodes;
}
