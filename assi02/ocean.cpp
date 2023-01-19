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
    /*!
      \brief
        Prints the grid (ocean) to the screen.

      \param ocean
        The Ocean to print

      \param field_width
        How much space each position takes when printed.

      \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.

      \param showboats
        If true, the boats are shown in the output. (Debugging feature)
    */
    /**************************************************************************/
    Ocean *CreateOcean(int num_boats, int x_size, int y_size)
    {
      Ocean *ocean = new Ocean;
      ocean->grid = new int[x_size * y_size]();
      ocean->boats = new Boat[num_boats]; 
      for(int i=0;i<num_boats;i++){  
      ocean->boats[i].hits = 0;
      ocean->boats[i].ID = 0;
      }
      ocean->num_boats = num_boats;
      ocean->x_size = x_size;
      ocean->y_size = y_size;
      ocean->stats.hits = 0;
      ocean->stats.misses = 0;
      ocean->stats.duplicates = 0;
      ocean->stats.sunk = 0;
      return ocean;
    }

    void DestroyOcean(Ocean *theOcean)
    {
      delete[] theOcean->boats;
      delete[] theOcean->grid;
      delete theOcean;
      return;
    }

    BoatPlacement PlaceBoat(Ocean &ocean, Boat const &boat)
    {

      // Check if the boat placement is outside the bounds of the ocean
      if (boat.position.x < 0 || boat.position.x >= ocean.x_size || boat.position.y < 0 || boat.position.y >= ocean.y_size)
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

    ShotResult TakeShot(Ocean &ocean, Point const &coordinate)
    {
      if (coordinate.x > ocean.x_size || coordinate.x < 0 || coordinate.y > ocean.y_size || coordinate.y < 0)
      {
        return srILLEGAL; 
      }
      if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtOK)
      {
        ocean.stats.misses++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] = dtBLOWNUP;
        return srMISS;
      }
      else if ((ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == dtBLOWNUP) || (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 + HIT_OFFSET && ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99 + HIT_OFFSET))
      {
        ocean.stats.duplicates++;
        return srDUPLICATE;
      }
      else if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] >= 1 || ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99)
      {
        ocean.stats.hits++;
        ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x]].hits++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] += HIT_OFFSET;
        if (ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x]-HIT_OFFSET].hits == BOAT_LENGTH)
        {
          ocean.stats.sunk++;
          return srSUNK;
        }
      }
      return srHIT;
    }

    ShotStats GetShotStats(Ocean const &ocean)
    {
      return ocean.stats;
    }

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
