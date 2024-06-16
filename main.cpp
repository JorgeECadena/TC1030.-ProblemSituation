#include <iostream>
#include <string>
#include <vector>
#include ".\Video.h"
#include ".\Movie.h"
#include ".\Series.h"
#include ".\Episode.h"

/**
 * @brief Returns the sum of the length of every episode 
 * 
 * @param episodes 
 * @return float 
 */
float getSeriesLength(std::vector<Episode>* episodes) {
    // Create the sum local variable
    float sum = 0.0;

    // Iterate in the vector
    for(int i = 0; i < episodes->size(); i++) {
        sum += (*episodes)[i].getLength();
    }
    return sum;
}

int main() {
    std::string user;
    // Create three different movies
    Movie* firstMovie = new Movie(0, "Baby Driver", 1.92, "Action");
    Movie* secondMovie = new Movie(1, "Sing", 1.83, "Animated");
    Movie* thirdMovie = new Movie(2, "Smile", 1.92, "Horror");

    // First series episodes
    Episode* firstSeriesEpisodeOne = new Episode(0, "Pilot", 0.38, 1, 1);
    Episode* firstSeriesEpisodeTwo = new Episode(1, "Episode 2", 0.43, 2, 1);

    // Second series episodes
    Episode* secondSeriesEpisodeOne = new Episode(0, "Pilot", 1.12, 1, 1);
    Episode* secondSeriesEpisodeTwo = new Episode(1, "Episode 2", 1.20, 1, 1);

    // Keep the episodes on a vector
    std::vector<Episode> firstSeriesEpisodes = {*firstSeriesEpisodeOne, *firstSeriesEpisodeTwo};
    std::vector<Episode> secondSeriesEpisodes = {*secondSeriesEpisodeOne, *secondSeriesEpisodeTwo};

    // Create two different series
    Series* firstSeries = new Series(0, "Brooklyn 99", getSeriesLength(&firstSeriesEpisodes), "Comedy", firstSeriesEpisodes);
    Series* secondSeries = new Series(1, "Stranger Things", getSeriesLength(&secondSeriesEpisodes), "Suspense", secondSeriesEpisodes);

    // Create a movie vector
    std::vector<Video> movieVector = {*firstMovie, *secondMovie, *thirdMovie};
    std::vector<Video> seriesVector = {*firstSeries, *secondSeries};

    // Create a video vector
    std::vector<std::vector<Video>> videoVector = {movieVector, seriesVector};

    // Send a welcome message to the user
    std::cout << "\nWelcome to the newest streaming service!" << std::endl;
    
    // Ask user for their name
    std::cout << "\nWhat's your name? ";
    std::cin >> user;

    // Greet user
    std::cout << "\nWelcome, " << user << std::endl;

    // Declare vectors with valid inputs
    std::vector<std::string> validMovieInputs = {"a", "A", "Movie", "movie", "1"};
    std::vector<std::string> validSeriesInputs = {"b", "B", "Series", "series", "2"};
    std::vector<std::string> validExitInputs = {"c", "C", "exit", "Exit", "3"};

    // Declare a vector of vectors with the valid inputs
    std::vector<std::vector<std::string>> validInputs = {validMovieInputs, validSeriesInputs, validExitInputs};

    // User related variables
    std::string userSelection = "";
    bool isUserSelectionValid;

    // Get the types of the Movie and Series classes
    // Auto is used because we don't know the exact type of typeid().name()
    auto movieType = typeid(*firstMovie).name();
    auto seriesType = typeid(*firstSeries).name();

    // While loop condition
    bool exitCondition = true;
    unsigned short counter = 0; // Create counter
    while(exitCondition) {
        // Ask for user's selection
        do {
            isUserSelectionValid = false;
            counter++;  // Add 1 to counter

            // Print options
            std::cout << "\n\nWhat would you like to watch today? (select the option\'s letter)\
            \n\t(a) Movie\n\t(b) Series\n\t(c) Exit" << std::endl;
            
            // Ask user for their selection
            std::cout << "Your selection: ";
            std::cin >> userSelection;

            // Iterate inside the valid selections array
            for(int i = 0; i < validInputs.size(); i++) {
                for(int j = 0; j < validInputs[i].size(); j++) {
                    // Check if the input is valid 
                    if(userSelection == validInputs[i][j]) {
                        isUserSelectionValid = true;
                        counter = 0;
                        
                        // Set the input to a, b or c
                        switch(i) {
                            case 0:
                                userSelection = "a";
                                break;
                            case 1:
                                userSelection = "b";
                                break;
                            case 2:
                                userSelection = "c";
                                break;
                            default:
                                std::cout << "Error occured!" << std::endl;
                        }
                    }
                }
            }
            // Let the user know if their input is unvalid
            if(counter > 0) {
                std::cout << "\n\nERROR: Input not valid, please try again!" << std::endl;            
            }
        } while (isUserSelectionValid == false);    // Repeat until the input is valid

        // What to do when user selects to watch a movie
        if(userSelection == "a") {
            // Show the available movies
            std::cout << "\n\nAvailable movies:\n" << std::endl;
            // Iterate over the movies vector to show them all
            for(int i = 0; i < videoVector[0].size(); i++) {
                // Show and format the movies info
                std::cout << "\t(" << (i + 1) << ") " <<videoVector[0][i].getName() << std::endl;
            }
        } else if(userSelection == "b") {
            for(int i = 0; i < videoVector[1].size(); i++) {
                std::cout << videoVector[1][i].getName() << std::endl;
            }
        } else {
            std::cout << "\n\n\t\tThank you for watching, " << user << "!"<< std::endl,
            exitCondition = false;
        }

    }


    // Free the allocated memory
    delete firstMovie;
    delete secondMovie;
    delete thirdMovie;

    delete firstSeriesEpisodeOne;
    delete firstSeriesEpisodeTwo;

    delete secondSeriesEpisodeOne;
    delete secondSeriesEpisodeTwo;

    delete firstSeries;
    delete secondSeries;

    return 0;
}