#include ".\Video.h"

/**
 * @brief Default Video constructor sets every parameter as an empty value
 * 
 * @return Video 
 */
Video :: Video() : id(0), name(""), length(0.0), genre("") {

}

/**
 * @brief Parameterized constructor sets every attribute value into the given parameter
 * 
 * @param id 
 * @param name 
 * @param length 
 * @param genre 
 * @return Video 
 */
Video :: Video(int id, std::string name, float length, std::string genre) :
id(id), name(name), length(length), genre(genre) {

}

/**
 * @brief Video class destructor
 * 
 * @return Video 
 */
Video :: ~Video() {

}

/**
 * @brief Get the id attribute
 * 
 * @return int 
 */
int Video :: getId(void) {
    return id;
}

/**
 * @brief Get the name attribute
 * 
 * @return std::string 
 */
std::string Video :: getName(void) {
    return name;
}

/**
 * @brief Get the length attribute
 * 
 * @return float 
 */
float Video :: getLength(void) {
    return length;
}

/**
 * @brief Get the genre attribute
 * 
 * @return std::string 
 */
std::string Video :: getGenre(void) {
    return genre;
}

/**
 * @brief Set the id attribute
 * 
 * @param id 
 */
void Video :: setId(int id) {
    this -> id = id;
}

/**
 * @brief Set the name attribute
 * 
 * @param name 
 */
void Video :: setName(std::string name) {
    this -> name = name;
}

/**
 * @brief Set the length attribute
 * 
 * @param length 
 */
void Video :: setLength(float length) {
    this -> length = length;
}

/**
 * @brief Set the genre attribute
 * 
 * @param genre 
 */
void Video :: setGenre(std::string genre) {
    this -> genre = genre;
}

/**
 * @brief Doesn't do anything on the base class
 * 
 */
void Video :: getRating(void) {

}

/**
 * @brief Doesn't do anything on the derived class
 * 
 * @param value 
 */
void Video :: addVote(unsigned short value) {
    
}