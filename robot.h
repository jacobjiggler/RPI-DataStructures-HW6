#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "position.h"


// "Prototype" for the Board class so a Robot can store a pointer to the shared Board
class Board;



// The Robot class stores information about a single robot.  This
// includes the start & end position, the actions that are available
// for that robot.  The robot also stores a specific ordering of those
// actions, and the current position, orientation, and timestep in
// simulation of that program.  The Robot stores a pointer to the
// shared Board class.
class Robot {

public:

    // CONSTRUCTOR
    Robot(char symbol_, Board *board_,
          const Position &start_position_, const std::string &start_direction_,
          const Position &goal_position_, const std::vector<std::string> &commands_);
    Robot(const Robot & previous,const std::vector<std::string> &commands_);

    // ACCESSORS
    char getSymbol() const {
        return symbol;
    }
    const Position& getCurrentPosition() const {
        return current_position;
    }
    const Position& getNextPosition() const {
        return next_position;
    }
    const Position& getGoalPosition() const {
        return goal_position;
    }
    const std::string& getCurrentDirection() const {
        return current_direction;
    }
    const std::vector<std::string>& getProgram() const {
        return program;
    }
    const  std::vector<std::vector<std::string> > &  getallpossible() const {
        return allPossible;
    }


    // MODIFIERS
    void move();
    void nextOriginal();


private:
    std::vector<std::vector<std::string> > recurs_possible(const std::vector<std::string> & commandsavailable);
    // REPRESENTATION
    char symbol;

    // a pointer to the Board object
    Board *board;

    // information on the 'game rules' for this robot
    Position start_position;

    std::string start_direction;
    Position goal_position;


    // the sequence of actions (current program) for this robot
    std::vector<std::string> program;


    std::vector<std::vector<std::string> > allPossible;
    // current state of the robot
    int next_step;
    Position current_position;
    Position next_position;
    std::string current_direction;
    std::string next_direction;
};


#endif
