/******************************************************************************
\file    ocean.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 04
\date    14-02-23

\brief
Contains definitions for constructor, destructor and member functions needed
to simulate a game of battleship.
********************************************************************************/
#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw
using namespace std;

namespace HLP2
{
  namespace WarBoats
  {

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE
     */

    /**************************************************************************/

    /******************************************************************
     * @brief Construct a new Ocean:: Ocean object
     *
     * @param num_boats
     * number of boats
     * @param x_size
     * width of grid
     * @param y_size
     * height of grid
     *********************************************************************/
    Ocean::Ocean(int num_boats, int x_size, int y_size)
    {
      this->grid = new int[x_size * y_size]{};
      this->boats = new Boat[num_boats]{};
      this->num_boats = num_boats;
      this->x_size = x_size;
      this->y_size = y_size;
      this->stats.hits = 0;
      this->stats.misses = 0;
      this->stats.duplicates = 0;
      this->stats.sunk = 0;
    }
    /******************************************************************
     * @brief Destructor definition for class Ocean. Frees dynamically allocated
     * memory for grid and boats.
     *********************************************************************/
    Ocean::~Ocean()
    {
      delete[] grid;
      delete[] boats;
    }

    /******************************************************************
     * @brief
     * Obtain stats 
     * @return ShotStats
     *********************************************************************/
    ShotStats Ocean::GetShotStats() const
    {
      return stats;
    }

    /******************************************************************
     * @brief
     * Chooses point on the grid to take a shot 
     * @param coordinate
     * Coordinate to take shot
     * @return ShotResult
     * Result of the shot taken
     *********************************************************************/
    ShotResult Ocean::TakeShot(Point const &coordinate)
    {
      if (coordinate.x >= x_size || coordinate.x < 0 || coordinate.y >= y_size || coordinate.y < 0)
      {
        return srILLEGAL;
      }
      if (grid[coordinate.y * x_size + coordinate.x] == dtOK)
      {
        stats.misses++;
        grid[coordinate.y * x_size + coordinate.x] = dtBLOWNUP;
        return srMISS;
      }
      else if ((grid[coordinate.y * x_size + coordinate.x] == dtBLOWNUP) || (grid[coordinate.y * x_size + coordinate.x] >= 1 + HIT_OFFSET && grid[coordinate.y * x_size + coordinate.x] <= 99 + HIT_OFFSET))
      {
        stats.duplicates++;
        return srDUPLICATE;
      }
      else if (grid[coordinate.y * x_size + coordinate.x] >= 1 || grid[coordinate.y * x_size + coordinate.x] <= 99)
      {
        stats.hits++;
        boats[grid[coordinate.y * x_size + coordinate.x] - 1].hits++;
        grid[coordinate.y * x_size + coordinate.x] += HIT_OFFSET;
        if (boats[grid[coordinate.y * x_size + coordinate.x] - 1 - HIT_OFFSET].hits == BOAT_LENGTH)
        {
          stats.sunk++;
          return srSUNK;
        }
      }
      return srHIT;
    }

    /******************************************************************
     * @brief
     * Places boat onto the created grid.
     * @param boat
     * Boat to be placed onto grid
     * @return BoatPlacement
     *********************************************************************/
    BoatPlacement Ocean::PlaceBoat(Boat const &boat) const
    {

      // Check if the boat placement is outside the bounds of the ocean
      if (boat.position.x < 0 || boat.position.x > x_size || boat.position.y < 0 || boat.position.y > y_size)
      {
        return bpREJECTED;
      }

      int boat_x_end = boat.position.x, boat_y_end = boat.position.y; // Initialize the end position of the boat

      // Check the orientation of the boat, and calculate the end position based on the orientation and boat length
      if (boat.orientation == oHORIZONTAL)
      {
        boat_x_end += BOAT_LENGTH - 1;
      }
      else
      {
        boat_y_end += BOAT_LENGTH - 1;
      }

      // Check if the calculated end position is outside the bounds of the ocean
      if (boat_x_end >= x_size || boat_y_end >= y_size)
      {
        return bpREJECTED;
      }

      // Check if the positions occupied by the boat are already occupied by other boats by checking the elements in the grid array.
      for (int x = boat.position.x; x <= boat_x_end; x++)
      {
        for (int y = boat.position.y; y <= boat_y_end; y++)
        {

          if (grid[y * x_size + x] != dtOK)
          {
            return bpREJECTED;
          }
        }
      }

      // iterate through grid, record boat placement id
      for (int x = boat.position.x; x <= boat_x_end; x++)
      {
        for (int y = boat.position.y; y <= boat_y_end; y++)
        {
          grid[y * x_size + x] = boat.ID; // record the boat placement id
        }
      }
      return bpACCEPTED;
    }

    /******************************************************************
     * @brief
     * Obtains x or y value
     * @return Ocean::Dimensions
     *********************************************************************/
    Ocean::Dimensions Ocean::GetDimensions() const
    {
      return {x_size, y_size};
    }

    /******************************************************************
     * @brief
     * Obtains pointer to grid.
     * @return int*
     *********************************************************************/
    int *Ocean::GetGrid() const
    {
      return grid;
    }
  } // namespace WarBoats
} // namespace HLP2
