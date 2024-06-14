#pragma once

#include <iostream>
#include <vector>
#include ".\Episode.h"

/**
 * @brief Returns the sum of the length of every episode 
 * 
 * @param episodes 
 * @return float 
 */
float getSeriesLength(std::vector<Episode>* episodes);