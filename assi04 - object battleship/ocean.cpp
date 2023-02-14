/******************************************************************************
\file    ocean.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 02
\date    19-01-23

\brief
Creates the game of battleship and simulates shots taken using functions
  -CreateOcean
    Dynamically allocates the grid and boats for the game of battleship.

  -DestroyOcean
    Clears the memory allocated in function CreateOcean.

  -PlaceBoat
    Places a boat into the grid. It checks whether the boat is within the bounds
    of the grid before doing so.

  -TakeShot
    Takes a shot on the grid. It checks whether the shot is in bounds before doing
    so. It returns different values based on whether the shot missed, hits a previously
    shot location, hits a ship. If it hits a ship, it checks whether the ship is sunk.

  -GetShotStats
    Returns the statistics from the free store object referenced by ocean.
  
  -DumpOcean
    Displays ocean
********************************************************************************/
#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw
using namespace std;

namespace HLP2
{
  namespace WarBoats
  {
    int const BOAT_LENGTH{4};  //!< Length of a boat
    int const HIT_OFFSET{100}; //!< Add this to the boat ID

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE
     */

    /**************************************************************************/
 
/******************************************************************
 * @brief 
 * Create a Ocean object
 * Dynamically allocates array for Ocean with grid array of ints with 
 * hor_size * ver_size number of elements. Sets each position within the 
 * grid with value constant DamageType::dtOK
 * Dynamically allocates array for Boats with size num_boats with value of 0
 * Sets value of data member of ocean.stats to 0.
 * 
 * @param num_boats 
 * number of boats 
 * 
 * @param x_size
 * width of ocean
 *  
 * @param y_size 
 * height of ocean
 * 
 * @return 
 * Pointer to dynamically allocated Ocean object.
 *********************************************************************/
    Ocean *CreateOcean(int num_boats, int x_size, int y_size)
    {
      Ocean *ocean = new Ocean;
      ocean->grid = new int[y_size * x_size]{DamageType::dtOK};
      ocean->boats = new Boat[num_boats]{};
      ocean->num_boats = num_boats;
      ocean->x_size = x_size;
      ocean->y_size = y_size;
      ocean->stats.hits = 0;
      ocean->stats.misses = 0;
      ocean->stats.duplicates = 0;
      ocean->stats.sunk = 0;
      return ocean;
    }
/******************************************************************
 * @brief 
 * Deletes dynamically allocated memory for arrays created in CreateOcean.
 * 
 * @param theOcean 
 * Pointer to ocean to delete allocated memory.
 *********************************************************************/
    void DestroyOcean(Ocean *theOcean)
    {
      delete[] theOcean->boats;
      delete[] theOcean->grid;
      delete theOcean;
      return;
    }
/******************************************************************
 * @brief 
 * Places boat onto the grid created by CreateOcean
 * 
 * @param ocean 
 * pointer to the ocean
 * 
 * @param boat 
 * pointer to boat struct
 * 
 * @return 
 * Return value indicates whether boat can be placed on the chosen
 * location
 *********************************************************************/
    BoatPlacement PlaceBoat(Ocean &ocean, Boat const &boat)
    {

      // Check if the boat placement is outside the bounds of the ocean
      if (boat.position.x < 0 || boat.position.x > ocean.x_size || boat.position.y < 0 || boat.position.y > ocean.y_size)
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
      if (boat_x_end >= ocean.x_size || boat_y_end >= ocean.y_size)
      {
        return bpREJECTED;
      }

      // Check if the positions occupied by the boat are already occupied by other boats by checking the elements in the grid array.
      for (int x = boat.position.x; x <= boat_x_end; x++)
      {
        for (int y = boat.position.y; y <= boat_y_end; y++)
        {

          if (ocean.grid[y * ocean.x_size + x] != dtOK)
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
          ocean.grid[y * ocean.x_size + x] = boat.ID; // record the boat placement id
        }
      }
      return bpACCEPTED;
    }
/******************************************************************
 * @brief 
 * Chooses a point on the grid to shoot based on coordinate input.
 * 
 * @param ocean 
 * pointer to ocean
 * 
 * @param coordinate 
 * Pointer to Point struct that contains x and y position of the shot.
 * 
 * @return 
 * Returns shot results depending on location chosen.
 * Possible values are:
 * -srILLEGAL   (Coordinate of shot is outside the grid)
 * -srMISS      (Coordinate of shot landed in empty position)
 * -srDUPLICATE (Coordinate of shot landed on previously shot position)
 * -srSUNK      (Coordinate of shot sunk boat)
 * -srHIT       (Coordinate of shot hit a boat)
 *********************************************************************/
    ShotResult TakeShot(Ocean &ocean, Point const &coordinate)
    {
      if (coordinate.x >= ocean.x_size || coordinate.x < 0 || coordinate.y >= ocean.y_size || coordinate.y < 0) //check if shot coordinate lands outside the grid
      {
        return srILLEGAL;
      }
      if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtOK)//check if shot coordinate is empty
      {
        ocean.stats.misses++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] = dtBLOWNUP;//changes empty coordinate to reflect that it has been blown up.
        return srMISS;
      }
      //checks if shot coordinate lands on previously blow up coordinate
      else if ((ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtBLOWNUP) || (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 + HIT_OFFSET && ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99 + HIT_OFFSET))
      {
        ocean.stats.duplicates++;
        return srDUPLICATE;
      }
      //checks if shot coordinate lands on a boat
      else if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 || ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99)
      {
        ocean.stats.hits++;
        ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x]-1].hits++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] += HIT_OFFSET;//change coordinate to reflect that boat has been hit
        if (ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] -1 - HIT_OFFSET].hits == BOAT_LENGTH)//checks if 4 coordinates of the same boat id has been struck.
        {
          ocean.stats.sunk++;
          return srSUNK;
        }
      }
      return srHIT;
    }
   
/******************************************************************
 * @brief 
 * Get the Shot Stats object
 * 
 * @param ocean 
 * pointer to ocean
 * 
 * @return 
 * ocean.stats
 *********************************************************************/
    ShotStats GetShotStats(Ocean const &ocean)
    {
      return ocean.stats;
    }
/******************************************************************
 * @brief Funtion to display the ocean.
 * 
 * @param ocean 
 * Ocean to print
 * 
 * @param field_width 
 * Space each position requires
 * 
 * @param extraline
 * extraline to be printed or not
 *  
 * @param showboats 
 * Shows boats in output if true.
 *********************************************************************/
    void DumpOcean(const HLP2::WarBoats::Ocean &ocean, int field_width, bool extraline, bool showboats)
    {
      for (int y = 0; y < ocean.y_size; y++)
      { // For each row
        for (int x = 0; x < ocean.x_size; x++)
        { // For each column
          // Get value at x/y position
          int value = ocean.grid[y * ocean.x_size + x];
          // Is it a boat that we need to keep hidden?
          value = ((value > 0) && (value < HIT_OFFSET) && (showboats == false)) ? 0 : value;
          std::cout << std::setw(field_width) << value;
        }
        std::cout << "\n";
        if (extraline)
        {
          std::cout << "\n";
        }
      }
    }
  } // namespace WarBoats
} // namespace HLP2
