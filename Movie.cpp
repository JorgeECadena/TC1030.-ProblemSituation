#include ".\Movie.h"
#include ".\Video.h"

/*
* Default constructor, sets every attribute as a NULL value
*/
Movie :: Movie() : Video(), votes(NULL) {

}

/*
* Parameterized constructor, receives int id, string name, float length, 
* string genre, int votes to set the class attributes
*/
Movie :: Movie(int id, std::string name, float length, std::string genre, int votes) :
Video(id, name, length, genre), votes(votes) {

}

/*
* Movie class destructor
*/
Movie :: ~Movie() {
    
}

/*
* Returns class int votes
*/
int Movie :: getVotes(void) {
    return votes;
}

/*
* Set the votes attribute value to the given int value
*/
void Movie :: setVotes(int votes) {
    this -> votes = votes;
}

/*
* Overrided method doesn't do anything yet on the son class
*/
void Movie :: getRating(void) {
    // TODO: Set method logic
}

/*
* Overrided method doesn't do anything yet on the son class
*/
void Movie :: addVote(unsigned short value) {
    // TODO: Set method logic
}