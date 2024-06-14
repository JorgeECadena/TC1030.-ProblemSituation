#include <iostream>
#include <string>
#include <vector>
#include "main.h"
#include ".\Video.h"
#include ".\Movie.h"
#include ".\Series.h"
#include ".\Episode.h"

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

    // Create a video vector
    std::vector<Video> videoVector = {*firstMovie, *secondMovie, *thirdMovie, *firstSeries, *secondSeries};

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