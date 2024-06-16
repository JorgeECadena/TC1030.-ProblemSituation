#include ".\Movie.h"
#include ".\Video.h"

/**
 * @brief Movie default constructor
 * 
 * @return Movie 
 */
Movie :: Movie() : Video() {

}

/**
 * @brief Parameterized constructor changes attributes values into received parameters
 * 
 * @param id 
 * @param name 
 * @param length 
 * @param genre 
 * @return Movie 
 */
Movie :: Movie(int id, std::string name, float length, std::string genre) : Video(id, name, length, genre) {

}

/**
 * @brief Movie class destructor
 * 
 * @return Movie 
 */
Movie :: ~Movie() {
    
}

/**
 * @brief Get the votes attribute
 * 
 * @return int 
 */
int Movie :: getVotes(void) {
    return votes;
}

/**
 * @brief Set the votes attribute
 * 
 * @param votes 
 */
void Movie :: setVotes(int votes) {
    this -> votes = votes;
}

/**
 * @brief Print the rating of the movie
 * 
 */
void Movie :: getRating(void) {
    int actualVotes = this -> getVotes();
    float rating = actualVotes / movieOneVoters;

    std::cout << "Movie\'s " << this -> getName() << " Rating is: " << rating << std::endl;
}

/**
 * @brief Adds the value received to the votes attribute
 * 
 * @param value 
 */
void Movie :: addVote(unsigned short value) {
    std::cout << "Previous votes: " << this -> getVotes() << std::endl;
    int actualVotes = this -> getVotes();
    int votesSum = actualVotes + value;

    this -> setVotes(votesSum);

    std::cout << "New votes: " << this -> getVotes() << std::endl;
}