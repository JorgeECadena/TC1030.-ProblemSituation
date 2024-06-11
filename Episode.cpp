#include ".\Episode.h"

#include <iostream>
#include <string>

/**
 * @brief Default constructor initialized parameters as empty values
 * 
 * @return Episode 
 */
Episode :: Episode() : id(0), title(""), lenght(0.0),number(0), season(0)  {

}

/**
 * @brief Parameterized constructor changes the attributes values into the given parameters
 * 
 * @param id 
 * @param title 
 * @param length 
 * @param number 
 * @param season 
 * @return Episode 
 */
Episode :: Episode(int id, std::string title, float length, unsigned short number, unsigned short season) :
id (id), title(title), lenght(length),number(number), season(season)  {

}

/**
 * @brief Class destructor
 * 
 * @return Episode 
 */
Episode :: ~Episode() {

}

/**
 * @brief Get the id attribute
 * 
 * @return int 
 */
int Episode :: getId(void){
    return id;

}

/**
 * @brief Get the title attribute
 * 
 * @return std::string 
 */
std::string Episode :: getTitle(void){
    return title;

}

/**
 * @brief Get the length attribute
 * 
 * @return float 
 */
float Episode :: getLenght(void){
    return lenght;

}

/**
 * @brief Get the number attribute
 * 
 * @return unsigned short 
 */
unsigned short Episode :: getNumber(void) {
    return number;
}

/**
 * @brief Get the season attribute
 * 
 * @return unsigned short 
 */
unsigned short Episode :: getSeason(void) {
    return season;
}

/**
 * @brief Set the id attribute
 * 
 * @param id 
 */
void Episode:: setId(int id){
    this -> id = id;

}

/**
 * @brief Set the length attribute
 * 
 * @param lenght 
 */
void Episode :: setLenght(float lenght){
    this-> lenght = lenght;

}

/**
 * @brief Set the title attribute
 * 
 * @param title 
 */
void Episode :: setTitle(std::string title){
    this -> title = title;

}

/**
 * @brief Set the number attribute
 * 
 * @param number 
 */
void Episode :: setNumber(unsigned short number) {
    this -> number = number;
}

/**
 * @brief Set the season attribute
 * 
 * @param season 
 */
void Episode :: setSeason(unsigned short season) {
    this -> season = season;
}
