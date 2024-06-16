#include <iostream>
#include <string>
#include <vector>
#include ".\Video.h"
#include ".\Movie.h"
#include ".\Series.h"
#include ".\Episode.h"

bool movieOne = false;
bool movieTwo = false;
bool movieThree = false;

bool seriesOne = false;
bool seriesTwo = false;

int movieOneVoters = 0;
int movieTwoVoters = 0;
int movieThreeVoters = 0;

int seriesOneVoters = 0;
int seriesTwoVoters = 0;

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

    // Vector with the valid voting values
    std::vector<unsigned short> validVotingValues = {1, 2, 3, 4, 5};

    // User related variables
    std::string userSelection = "";
    bool isUserSelectionValid;

    // Selections for movies and series
    std::vector<std::string> moviesSelections = {"1", "2", "3"}; 
    std::vector<std::string> seriesSelections = {"1", "2"}; 

    // Options for voting for a movie
    std::vector<std::string> moviesVotingOptions = {"1", "2"};
    std::vector<std::string> seriesVotingOptions = {"1", "2", "3"};

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
                std::cout << "\t(" << (i + 1) << ") " << videoVector[0][i].getName() << std::endl;
            }
            isUserSelectionValid = false;
            counter = 0;
            do {
                isUserSelectionValid = false;
                counter++;
                // Ask user for the movie they want to watch
                std::cout << "\nSelect the number of the movie you want to watch: ";
                std::cin >> userSelection;
                // Iterate over the valid inputs to check if user entered a valid input
                for(int i = 0; i < moviesSelections.size(); i++) {
                    // If input is valid then get out of the loop
                    if(userSelection == moviesSelections[i]) {
                        isUserSelectionValid = true;
                        counter = 0;

                        switch (i) {
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
                                std::cout << "An error has occured!" << std::endl;
                                break;
                        }
                    }
                }
                // If input is not valid keep asking for it
                if(counter > 0) {
                    std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                }
            } while(isUserSelectionValid == false);

            // Show every movie depending on user's selection
            if(userSelection == "a") {
                /** FIRST MOVIE OPTIONS **/
                // Show movie information
                std::cout << "\n\n\tName: " << movieVector[0].getName() << "\n\tGenre: " << movieVector[0].getGenre() <<
                "\n\tLength (decimals): " << movieVector[0].getLength() << std::endl;
                // Create the local variable movieOneVotes to count the votes this movie gets
                unsigned short movieOneVotes = 0;

                // Show user the possible options
                std::cout << "\nOptions:\n(1) Vote\n(2) Get Rating" << std::endl;
                isUserSelectionValid = false;   // Set the user selection as not valid to avoid bugs
                counter = 0;    // Initialize counter as 0

                // Do while loop to verify the given options are valid
                do {
                    counter++;  // Add 1 to counter value

                    // Ask user for their input
                    std::cout << "\nSelect the number of option you want to do: ";
                    std::cin >> userSelection;

                    // Iterate inside the movies voting valid options
                    for(int i = 0; i < moviesVotingOptions.size(); i++) {
                        // If the user's input is in the movies voting valid options then go on
                        if(userSelection == moviesVotingOptions[i]) {
                            isUserSelectionValid = true;    // Set the user selection as valid
                            counter = 0;    // Reset counter to zero to avoid Error message

                            // Switch case to set the user input as something easier to work with
                            switch (i) {
                                case 0:
                                    userSelection = "a";
                                    break;
                                case 1:
                                    userSelection = "b";
                                    break;
                                default:
                                    std::cout << "An error has occured!" << std::endl;
                                    break;
                            }
                        }

                    }
                    // Check if there are any errors, if not just continue
                    if(counter > 0) {
                        std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                    }
                } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met

                // Will be done if user wants to vote
                if(userSelection == "a") {
                    isUserSelectionValid = false;   // Set user's condition as not valid
                    counter = 0;    // Set counter to zero
                    do {
                        counter++;  
                        
                        // Ask user to rate the movie
                        std::cout << "\nInsert the vote you'd give to this movie: ";
                        std::cin >> movieOneVotes;  // Keep the vote in the unsigned short variable done before

                        // Check if user's input is a valid voting value
                        for(int i = 0; i < validVotingValues.size(); i++) {
                            // Check if the given vote is a valid input
                            if(movieOneVotes == validVotingValues[i]) {
                                isUserSelectionValid = true; // if the given selection is valid put it in 
                                counter = 0;

                                // Switch case to check values from 1 to 5
                                switch (i) {
                                    case 0:
                                        movieOneVotes = 1;
                                        break;
                                    case 1:
                                        movieOneVotes = 2;
                                        break;
                                    case 2:
                                        movieOneVotes = 3;
                                        break;
                                    case 3:
                                        movieOneVotes = 4;
                                        break;
                                    case 4: 
                                        movieOneVotes = 5;
                                        break;
                                    default:
                                        std::cout << "An error has occured!" << std::endl;
                                        break;
                                }
                            }
                        }
                        // Check if there are any input errors, if not just continue
                        if(counter > 0) {
                            std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                        }
                    } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met
                    
                    // Use this variables to know which amount of voters to use as a denominator
                    movieOne = true;
                    movieTwo = false;
                    movieThree = false;
                    // Add the vote given to the vote attribute
                    (*firstMovie).addVote(movieOneVotes);
                    movieOneVoters++;   // Sum one to voters for the first movie
                } else if(userSelection == "b") {
                    (*firstMovie).getRating();  // In case user selects to do the getRating method it calls the pointer to the heap variable
                }

            } else if(userSelection == "b") {
                /** SECOND MOVIE OPTIONS **/
                std::cout << "\n\n\tName: " << movieVector[1].getName() << "\n\tGenre: " << movieVector[1].getGenre() <<
                "\n\tLength (decimals): " << movieVector[1].getLength() << std::endl;
                // Create the variable to store the votes for movie two
                unsigned short movieTwoVotes = 0;

                // Show user the possible options
                std::cout << "\nOptions:\n(1) Vote\n(2) Get Rating" << std::endl;

                isUserSelectionValid = false;   // Set the user selection as not valid to avoid bugs
                counter = 0;    // Initialize counter as 0

                // Do while loop to verify the given options are valid
                do {
                    counter++;  // Add 1 to counter value

                    // Ask user for their input
                    std::cout << "\nSelect the number of option you want to do: ";
                    std::cin >> userSelection;

                    // Iterate inside the movies voting valid options
                    for(int i = 0; i < moviesVotingOptions.size(); i++) {
                        // If the user's input is in the movies voting valid options then go on
                        if(userSelection == moviesVotingOptions[i]) {
                            isUserSelectionValid = true;    // Set the user selection as valid
                            counter = 0;    // Reset counter to zero to avoid Error message

                            // Switch case to set the user input as something easier to work with
                            switch (i) {
                                case 0:
                                    userSelection = "a";
                                    break;
                                case 1:
                                    userSelection = "b";
                                    break;
                                default:
                                    std::cout << "An error has occured!" << std::endl;
                                    break;
                            }
                        }

                    }
                    // Check if there are any errors, if not just continue
                    if(counter > 0) {
                        std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                    }
                } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met

                // Will be done if user wants to vote
                if(userSelection == "a") {
                    isUserSelectionValid = false;   // Set user's condition as not valid
                    counter = 0;    // Set counter to zero
                    do {
                        counter++;  
                        
                        // Ask user to rate the movie
                        std::cout << "\nInsert the vote you'd give to this movie: ";
                        std::cin >> movieTwoVotes;  // Keep the vote in the unsigned short variable done before

                        // Check if user's input is a valid voting value
                        for(int i = 0; i < validVotingValues.size(); i++) {
                            // Check if the given vote is a valid input
                            if(movieTwoVotes == validVotingValues[i]) {
                                isUserSelectionValid = true; // if the given selection is valid put it in 
                                counter = 0;

                                // Switch case to check values from 1 to 5
                                switch (i) {
                                    case 0:
                                        movieTwoVotes = 1;
                                        break;
                                    case 1:
                                        movieTwoVotes = 2;
                                        break;
                                    case 2:
                                        movieTwoVotes = 3;
                                        break;
                                    case 3:
                                        movieTwoVotes = 4;
                                        break;
                                    case 4: 
                                        movieTwoVotes = 5;
                                        break;
                                    default:
                                        std::cout << "An error has occured!" << std::endl;
                                        break;
                                }
                            }
                        }
                        // Check if there are any input errors, if not just continue
                        if(counter > 0) {
                            std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                        }
                    } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met

                    // Use this variables to know which amount of voters to use as a denominator
                    movieOne = false;
                    movieTwo = true;
                    movieThree = false;

                    // Add the vote given to the vote attribute
                    (*secondMovie).addVote(movieTwoVotes);
                    movieTwoVoters++;   // Sum one to voters for the second movie
                } else if(userSelection == "b") {
                    (*secondMovie).getRating();  // In case user selects to do the getRating method it calls the pointer to the heap variable
                }
            } else {
                std::cout << "\n\n\tName: " << movieVector[2].getName() << "\n\tGenre: " << movieVector[2].getGenre() <<
                "\n\tLength (decimals): " << movieVector[2].getLength() << std::endl;

                // Create the variable to store the votes for movie two
                unsigned short movieThreeVotes = 0;

                // Show user the possible options
                std::cout << "\nOptions:\n(1) Vote\n(2) Get Rating" << std::endl;

                isUserSelectionValid = false;   // Set the user selection as not valid to avoid bugs
                counter = 0;    // Initialize counter as 0

                // Do while loop to verify the given options are valid
                do {
                    counter++;  // Add 1 to counter value

                    // Ask user for their input
                    std::cout << "\nSelect the number of option you want to do: ";
                    std::cin >> userSelection;

                    // Iterate inside the movies voting valid options
                    for(int i = 0; i < moviesVotingOptions.size(); i++) {
                        // If the user's input is in the movies voting valid options then go on
                        if(userSelection == moviesVotingOptions[i]) {
                            isUserSelectionValid = true;    // Set the user selection as valid
                            counter = 0;    // Reset counter to zero to avoid Error message

                            // Switch case to set the user input as something easier to work with
                            switch (i) {
                                case 0:
                                    userSelection = "a";
                                    break;
                                case 1:
                                    userSelection = "b";
                                    break;
                                default:
                                    std::cout << "An error has occured!" << std::endl;
                                    break;
                            }
                        }
                    }
                    // Check if there are any errors, if not just continue
                    if(counter > 0) {
                        std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                    }
                } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met

                // Will be done if user wants to vote
                if(userSelection == "a") {
                    isUserSelectionValid = false;   // Set user's condition as not valid
                    counter = 0;    // Set counter to zero
                    do {
                        counter++;  
                        
                        // Ask user to rate the movie
                        std::cout << "\nInsert the vote you'd give to this movie: ";
                        std::cin >> movieThreeVotes;  // Keep the vote in the unsigned short variable done before

                        // Check if user's input is a valid voting value
                        for(int i = 0; i < validVotingValues.size(); i++) {
                            // Check if the given vote is a valid input
                            if(movieThreeVotes == validVotingValues[i]) {
                                isUserSelectionValid = true; // if the given selection is valid put it in 
                                counter = 0;

                                // Switch case to check values from 1 to 5
                                switch (i) {
                                    case 0:
                                        movieThreeVotes = 1;
                                        break;
                                    case 1:
                                        movieThreeVotes = 2;
                                        break;
                                    case 2:
                                        movieThreeVotes = 3;
                                        break;
                                    case 3:
                                        movieThreeVotes = 4;
                                        break;
                                    case 4: 
                                        movieThreeVotes = 5;
                                        break;
                                    default:
                                        std::cout << "An error has occured!" << std::endl;
                                        break;
                                }
                            }
                        }
                        // Check if there are any input errors, if not just continue
                        if(counter > 0) {
                            std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                        }
                    } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met

                    // Use this variables to know which amount of voters to use as a denominator
                    movieOne = false;
                    movieTwo = false;
                    movieThree = true;
                    
                    // Add the vote given to the vote attribute
                    (*thirdMovie).addVote(movieThreeVotes);
                    movieThreeVoters++;   // Sum one to voters for the third movie
                } else if(userSelection == "b") {
                    (*thirdMovie).getRating();  // In case user selects to do the getRating method it calls the pointer to the heap variable
                }
            }
   
        } else if(userSelection == "b") {
            // Show the available series
            std::cout << "\n\nAvailable series:\n" << std::endl;
            // iterate over the series vector to show them all
            for(int i = 0; i < videoVector[1].size(); i++) {
                // Show and format the series info
                std::cout << "\t(" << (i + 1) << ") " << videoVector[1][i].getName() << std::endl;
            }

            isUserSelectionValid = false;
            counter = 0;
            do {
                isUserSelectionValid = false;
                counter++;
                // Ask user for the series they want to watch
                std::cout << "\nSelect the number of the series you want to watch: ";
                std::cin >> userSelection;
                // Iterate over the valid inputs to check if user entered a valid input
                for(int i = 0; i < seriesSelections.size(); i++) {
                    // If input is valid then get out of the loop
                    if(userSelection == seriesSelections[i]) {
                        isUserSelectionValid = true;
                        counter = 0;

                        switch (i) {
                            case 0:
                                userSelection = "a";
                                break;
                            case 1:
                                userSelection = "b";
                                break;
                            default:
                                std::cout << "An error has occured!" << std::endl;
                                break;
                        }
                    }
                }
                // If input is not valid keep asking for it
                if(counter > 0) {
                    std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                }
            } while(isUserSelectionValid == false);

            // Show every series depending on user's selection
            if(userSelection == "a") {
                /** FIRST SERIES OPTIONS **/
                // Show movie information
                std::cout << "\n\n\tName: " << seriesVector[0].getName() << "\n\tGenre: " << seriesVector[0].getGenre() <<
                "\n\tLength (decimals): " << seriesVector[0].getLength() << std::endl;
                // Create the local variable movieOneVotes to count the votes this movie gets
                unsigned short seriesOneVotes = 0;

                // Show user the possible options
                std::cout << "\nOptions:\n(1) Vote\n(2) Get Rating\n(3) Episodes" << std::endl;
                isUserSelectionValid = false;   // Set the user selection as not valid to avoid bugs
                counter = 0;    // Initialize counter as 0

                // Do while loop to verify the given options are valid
                do {
                    counter++;  // Add 1 to counter value

                    // Ask user for their input
                    std::cout << "\nSelect the number of option you want to do: ";
                    std::cin >> userSelection;

                    // Iterate inside the movies voting valid options
                    for(int i = 0; i < seriesVotingOptions.size(); i++) {
                        // If the user's input is in the movies voting valid options then go on
                        if(userSelection == seriesVotingOptions[i]) {
                            isUserSelectionValid = true;    // Set the user selection as valid
                            counter = 0;    // Reset counter to zero to avoid Error message

                            // Switch case to set the user input as something easier to work with
                            switch (i) {
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
                                    std::cout << "An error has occured!" << std::endl;
                                    break;
                            }
                        }

                    }
                    // Check if there are any errors, if not just continue
                    if(counter > 0) {
                        std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                    }
                } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met
                
                // Will be done if user wants to vote
                if(userSelection == "a") {
                    isUserSelectionValid = false;   // Set user's condition as not valid
                    counter = 0;    // Set counter to zero
                    do {
                        counter++;  
                        
                        // Ask user to rate the movie
                        std::cout << "\nInsert the vote you'd give to this series: ";
                        std::cin >> seriesOneVotes;  // Keep the vote in the unsigned short variable done before

                        // Check if user's input is a valid voting value
                        for(int i = 0; i < validVotingValues.size(); i++) {
                            // Check if the given vote is a valid input
                            if(seriesOneVotes == validVotingValues[i]) {
                                isUserSelectionValid = true; // if the given selection is valid put it in 
                                counter = 0;

                                // Switch case to check values from 1 to 5
                                switch (i) {
                                    case 0:
                                        seriesOneVotes = 1;
                                        break;
                                    case 1:
                                        seriesOneVotes = 2;
                                        break;
                                    case 2:
                                        seriesOneVotes = 3;
                                        break;
                                    case 3:
                                        seriesOneVotes = 4;
                                        break;
                                    case 4: 
                                        seriesOneVotes = 5;
                                        break;
                                    default:
                                        std::cout << "An error has occured!" << std::endl;
                                        break;
                                }
                            }
                        }
                        // Check if there are any input errors, if not just continue
                        if(counter > 0) {
                            std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                        }
                    } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met
                    
                    // Use this variables to know which amount of voters to use as a denominator
                    seriesOne = true;
                    seriesTwo = false;
                    // Add the vote given to the vote attribute
                    (*firstSeries).addVote(seriesOneVotes);
                    seriesOneVoters++;   // Sum one to voters for the first movie
                } else if(userSelection == "b") {
                    (*firstSeries).getRating();  // In case user selects to do the getRating method it calls the pointer to the heap variable
                } else if(userSelection == "c") {
                    // Display series episodes
                    for(int i = 0; i < (*firstSeries).getEpisodes().size(); i++) {
                        std::cout << "\n\nTitle: " << (*firstSeries).getEpisodes()[i].getTitle() <<
                        "\nSeason: " << (*firstSeries).getEpisodes()[i].getSeason() << std::endl;
                    }
                }
            } else if(userSelection == "b") {
                /** SECOND SERIES OPTIONS **/
                // Show movie information
                std::cout << "\n\n\tName: " << seriesVector[1].getName() << "\n\tGenre: " << seriesVector[1].getGenre() <<
                "\n\tLength (decimals): " << seriesVector[1].getLength() << std::endl;
                // Create the local variable movieOneVotes to count the votes this movie gets
                unsigned short seriesTwoVotes = 0;

                // Show user the possible options
                std::cout << "\nOptions:\n(1) Vote\n(2) Get Rating\n(3) Episodes" << std::endl;
                isUserSelectionValid = false;   // Set the user selection as not valid to avoid bugs
                counter = 0;    // Initialize counter as 0

                // Do while loop to verify the given options are valid
                do {
                    counter++;  // Add 1 to counter value

                    // Ask user for their input
                    std::cout << "\nSelect the number of option you want to do: ";
                    std::cin >> userSelection;

                    // Iterate inside the movies voting valid options
                    for(int i = 0; i < seriesVotingOptions.size(); i++) {
                        // If the user's input is in the movies voting valid options then go on
                        if(userSelection == seriesVotingOptions[i]) {
                            isUserSelectionValid = true;    // Set the user selection as valid
                            counter = 0;    // Reset counter to zero to avoid Error message

                            // Switch case to set the user input as something easier to work with
                            switch (i) {
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
                                    std::cout << "An error has occured!" << std::endl;
                                    break;
                            }
                        }

                    }
                    // Check if there are any errors, if not just continue
                    if(counter > 0) {
                        std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                    }
                } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met
                
                // Will be done if user wants to vote
                if(userSelection == "a") {
                    isUserSelectionValid = false;   // Set user's condition as not valid
                    counter = 0;    // Set counter to zero
                    do {
                        counter++;  
                        
                        // Ask user to rate the movie
                        std::cout << "\nInsert the vote you'd give to this series: ";
                        std::cin >> seriesTwoVotes;  // Keep the vote in the unsigned short variable done before

                        // Check if user's input is a valid voting value
                        for(int i = 0; i < validVotingValues.size(); i++) {
                            // Check if the given vote is a valid input
                            if(seriesTwoVotes == validVotingValues[i]) {
                                isUserSelectionValid = true; // if the given selection is valid put it in 
                                counter = 0;

                                // Switch case to check values from 1 to 5
                                switch (i) {
                                    case 0:
                                        seriesTwoVotes = 1;
                                        break;
                                    case 1:
                                        seriesTwoVotes = 2;
                                        break;
                                    case 2:
                                        seriesTwoVotes = 3;
                                        break;
                                    case 3:
                                        seriesTwoVotes = 4;
                                        break;
                                    case 4: 
                                        seriesTwoVotes = 5;
                                        break;
                                    default:
                                        std::cout << "An error has occured!" << std::endl;
                                        break;
                                }
                            }
                        }
                        // Check if there are any input errors, if not just continue
                        if(counter > 0) {
                            std::cout << "ERROR: Input not valid, please try again!" << std::endl;
                        }
                    } while(isUserSelectionValid == false); // Keep on going the loop until the condition is met
                    
                    // Use this variables to know which amount of voters to use as a denominator
                    seriesOne = false;
                    seriesTwo = true;
                    // Add the vote given to the vote attribute
                    (*secondSeries).addVote(seriesTwoVotes);
                    seriesTwoVoters++;   // Sum one to voters for the first movie
                } else if(userSelection == "b") {
                    (*secondSeries).getRating();  // In case user selects to do the getRating method it calls the pointer to the heap variable
                } else if(userSelection == "c") {
                    // Display series episodes
                    for(int i = 0; i < (*secondSeries).getEpisodes().size(); i++) {
                        std::cout << "\n\nTitle: " << (*secondSeries).getEpisodes()[i].getTitle() <<
                        "\nSeason: " << (*secondSeries).getEpisodes()[i].getSeason() << std::endl;
                    }
                }
            }

        } else {
            // Print a thanks message
            std::cout << "\n\n\t\tThank you for watching, " << user << "!"<< std::endl;
            exitCondition = false;  // Exit the loop
            continue;   // Skip to the next iteration of the loop
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