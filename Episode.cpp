#include ".\Episode.h"

#include <iostream>
#include <string>

/*
* Default constructor, sets every attribute as a NULL value
*/
Episode :: Episode() : id(0), title(""), lenght(0.0),number(0), season(0)  {

}

/*
* Parameterized constructor, receives int id, string name, float length, 
* string genre to set the class attributes
*/
Episode :: Episode(int id, std::string title, float length, unsigned short number, unsigned short season) :
id (id), title(title), lenght(length),number(number), season(season)  {

}

/*
* Episode destructor
*/
Episode :: ~Episode() {

}


int Episode :: getId(void){
    return id;

}

std::string Episode :: getTitle(void){
    return title;

}

float Episode :: getLenght(void){
    return lenght;

}
/*
* Returns class int id
*/
unsigned short Episode :: getNumber(void) {
    return number;
}

/*
* Returns class string name
*/
unsigned short Episode :: getSeason(void) {
    return season;
}


void Episode:: setId(int id){
    this -> id = id;

}

void Episode :: setLenght(float lenght){
    this-> lenght = lenght;

}

void Episode :: setTitle(std::string title){
    this -> title = title;

}
/*
* Set the id attribute value to the given int value
*/
void Episode :: setNumber(unsigned short number) {
    this -> number = number;
}

/*
* Set the name attribute value to the given string value
*/
void Episode :: setSeason(unsigned short season) {
    this -> season = season;
}
