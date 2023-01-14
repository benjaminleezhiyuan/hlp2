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
      ocean->boats->hits = 0;
      ocean->boats->ID = 0;
      ocean->num_boats = num_boats;
      ocean->x_size = x_size;
      ocean->y_size = y_size;
      ocean->stats.hits = 0;
      ocean->stats.misses = 0;
      ocean->stats.duplicates = 0;
      ocean->stats.sunk = 0;
      return ocean;
    }

    /// @brief
    /// @param theOcean
    void DestroyOcean(Ocean *theOcean)
    {
      delete[] theOcean->boats;
      delete[] theOcean->grid;
      delete theOcean;
      return;
    }

    /// @brief
    /// @param ocean
    /// @param coordinate
    /// @return
    ShotResult TakeShot(Ocean &ocean, Point const &coordinate)
    {
      if (!((coordinate.x <= ocean.x_size && coordinate.x >= 0) && (coordinate.y <= ocean.y_size && coordinate.y >= 0)))
        return srILLEGAL;
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
        ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] - 1].hits++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] += HIT_OFFSET;
        if (ocean.boats[ocean.grid[coordinate.y * ocean.x_size + coordinate.x] - 101].hits == BOAT_LENGTH)
        {
          ocean.stats.sunk++;
          return srSUNK;
        }
      }
      return srHIT;
    }

    /// @brief
    /// @param ocean
    /// @param boat
    /// @return
    BoatPlacement PlaceBoat(Ocean &ocean, Boat const &boat)
    {
      if (ocean.boats->ID >= ocean.num_boats)
        return bpREJECTED;
      if (boat.orientation == oHORIZONTAL)
      {
        if ((boat.position.x <= ocean.x_size - BOAT_LENGTH || boat.position.x >= 0) && (boat.position.y <= ocean.y_size || boat.position.y >= 0))
        {
          for (int i = 0; i < BOAT_LENGTH; i++)
            if (ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] != 0)
              return bpREJECTED;
          ocean.boats->ID++;
          for (int i = 0; i < BOAT_LENGTH; i++)
            ocean.grid[boat.position.y * ocean.x_size + boat.position.x + i] = ocean.boats->ID;
        }
      }
      else if (boat.orientation == oVERTICAL)
      {
        if ((boat.position.y <= ocean.y_size - BOAT_LENGTH || boat.position.y >= 0) && (boat.position.x <= ocean.x_size || boat.position.x >= 0))
        {
          for (int i = 0; i < BOAT_LENGTH; i++)
            if (ocean.grid[(boat.position.y + i) * ocean.x_size + boat.position.x] != 0)
              return bpREJECTED;
          ocean.boats->ID++;
          for (int i = 0; i < BOAT_LENGTH; i++)
            ocean.grid[(boat.position.y + i) * ocean.x_size + boat.position.x] = ocean.boats->ID;
        }
      }
      return bpACCEPTED;
    }

    /// @brief
    /// @param ocean
    /// @return
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
