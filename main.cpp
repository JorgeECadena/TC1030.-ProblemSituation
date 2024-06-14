#include <iostream>
#include <string>
#include <vector>
#include ".\Video.h"
#include ".\Movie.h"
#include ".\Series.h"
#include ".\Episode.h"

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
    Series* firstSeries = new Series(0, "Brooklyn 99", 0.57, "Comedy", firstSeriesEpisodes);
    Series* secondSeries = new Series(1, "Stranger Things", 0.60, "Suspense", secondSeriesEpisodes);

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