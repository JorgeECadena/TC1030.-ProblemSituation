#include ".\Video.h"

/*
* Default constructor, sets every attribute as a NULL value
*/
Video :: Video() : id(NULL), name(NULL), length(NULL), genre(NULL) {

}

/*
* Parameterized constructor, receives int id, string name, float length, 
* string genre to set the class attributes
*/
Video :: Video(int id, std::string name, float length, std::string genre) :
id(id), name(name), length(length), genre(genre) {

}

/**
 * Class destructor
 */

Video :: ~Video() {

}

/*
* Returns class int id
*/
int Video :: getId(void) {
    return id;
}

/*
* Returns class string name
*/
std::string Video :: getName(void) {
    return name;
}

/*
* Returns class float length
*/
float Video :: getLength(void) {
    return length;
}

/*
* Returns class string genre
*/
std::string Video :: getGenre(void) {
    return genre;
}

/*
* Set the id attribute value to the given int value
*/
void Video :: setId(int id) {
    this -> id = id;
}

/*
* Set the name attribute value to the given string value
*/
void Video :: setName(std::string name) {
    this -> name = name;
}

/*
* Set the length attribute value to the given float value 
*/
void Video :: setLength(float length) {
    this -> length = length;
}

/*
* Set the genre attribute value to the given string value
*/
void Video :: setGenre(std::string genre) {
    this -> genre = genre;
}

/*
* Virtual method doesn't do anything on the father class
*/
void Video :: getRating(void) {

}