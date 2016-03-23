#include <iostream>
#include <cassert>
#include <cstdlib>
#include <algorithm>

#include "robot.h"
#include "board.h"

using namespace std;

// CONSTRUCTOR
Robot::Robot(char symbol_, Board *board_,
             const Position &start_position_, const std::string &start_direction_,
             const Position &goal_position_, const std::vector<std::string> &programs_) :
    symbol(symbol_), board(board_),
    start_position(start_position_), start_direction(start_direction_),
    goal_position(goal_position_), program(programs_)
{



    // ASSIGNMENT: EDIT AS NEEDED




    // initialize the current position & direction variables
    next_step = 0;
    current_position = start_position;
    current_direction = start_direction;
    next_direction = current_direction;

    allPossible = recurs_possible(program);

    nextOriginal();


}
// COPY INSTRUCTOR WITH A NEW PATH.
//does not permutate the path.
Robot::Robot(const Robot & previous,const std::vector<std::string> &commands_): symbol(previous.symbol), board(previous.board),
    start_position(previous.start_position), start_direction(previous.start_direction),
    goal_position(previous.goal_position), program(commands_)
{





    // initialize the current position & direction variables
    next_step = 0;
    current_position = start_position;
    current_direction = start_direction;
    next_direction = current_direction;
    next_position = current_position;
    //  allPossible = recurs_possible(program);

    nextOriginal();
}




// advance the robot one action forward in its program, updating the
// position, direction and step counter
void Robot::move() {

    assert (next_step > 0);

    current_position = next_position;
    current_direction = next_direction;
    if (next_step < (int)program.size()) {
        if (program[next_step] == "rotate_right") {
            if (next_direction == "north") {
                next_direction = "east";
            }
            else if (next_direction == "east") {
                next_direction = "south";
            }
            else if (next_direction == "south") {
                next_direction = "west";
            }
            else {
                assert (next_direction == "west");
                next_direction = "north";
            }
        }
        else if (program[next_step] == "rotate_left") {
            if (next_direction == "north") {
                next_direction = "west";
            }
            else if (next_direction == "east") {
                next_direction = "north";
            }
            else if (next_direction == "south") {
                next_direction = "east";
            }
            else {
                assert (next_direction == "west");
                next_direction = "south";
            }
        }
        else if (program[next_step] == "u_turn") {
            if (next_direction == "north") {
                next_direction = "south";
            }
            else if (next_direction == "east") {
                next_direction = "west";
            }
            else if (next_direction == "south") {
                next_direction = "north";
            }
            else {
                assert (next_direction == "west");
                next_direction = "east";
            }
        }
        else if (program[next_step] == "forward_1") {
            if (next_direction == "north") {
                next_position = Position(next_position.col,next_position.row+1);
            }
            else if (next_direction == "east") {
                next_position = Position(next_position.col+1,next_position.row);
            }
            else if (next_direction == "south") {
                next_position = Position(next_position.col,next_position.row-1);
            }
            else {
                assert (next_direction == "west");
                next_position = Position(next_position.col-1,next_position.row);
            }
        }
        else if (program[next_step] == "forward_2") {
            if (next_direction == "north") {
                next_position = Position(next_position.col,next_position.row+2);
            }
            else if (next_direction == "east") {
                next_position = Position(next_position.col+2,next_position.row);
            }
            else if (next_direction == "south") {
                next_position = Position(next_position.col,next_position.row-2);
            }
            else {
                assert (next_direction == "west");
                next_position = Position(next_position.col-2,next_position.row);
            }
        }
        else if (program[next_step] == "forward_3") {
            if (next_direction == "north") {
                next_position = Position(next_position.col,next_position.row+3);
            }
            else if (next_direction == "east") {
                next_position = Position(next_position.col+3,next_position.row);
            }
            else if (next_direction == "south") {
                next_position = Position(next_position.col,next_position.row-3);
            }
            else {
                assert (next_direction == "west");
                next_position = Position(next_position.col-3,next_position.row);
            }
        }
        else if(program[next_step] == "do_nothing") {
        }
        else if(program[next_step] == "backward_1") {
            if (next_direction == "north") {
                next_position = Position(next_position.col,next_position.row-1);
            }
            else if (next_direction == "east") {
                next_position = Position(next_position.col-1,next_position.row);
            }
            else if (next_direction == "south") {
                next_position = Position(next_position.col,next_position.row+1);
            }
            else {
                assert (next_direction == "west");
                next_position = Position(next_position.col+1,next_position.row);
            }
        }
        else {

            // ASSIGNMENT: Implement other movements
// push
            std::cerr << "unknown command " << program[next_step] << std::endl;
            exit(0);
        }

        next_step++;
    }
  
}

//this is the same as the other and could actually be eliminated with some tweaking BUT WAS ORIGINALLY REQUIRED FOR MY ADDITION OF NEXT_MOVE.
void Robot::nextOriginal() {
    assert(next_step == 0);
    if (program[next_step] == "rotate_right") {
        if (current_direction == "north") {
            next_direction = "east";
        }
        else if (current_direction == "east") {
            next_direction = "south";
        }
        else if (current_direction == "south") {
            next_direction = "west";
        }
        else {
            assert (current_direction == "west");
            next_direction = "north";
        }
    }
    else if (program[next_step] == "rotate_left") {
        if (current_direction == "north") {
            next_direction = "west";
        }
        else if (current_direction == "east") {
            next_direction = "north";
        }
        else if (current_direction == "south") {
            next_direction = "east";
        }
        else {
            assert (current_direction == "west");
            next_direction = "south";
        }
    }
    else if (program[next_step] == "u_turn") {
        if (current_direction == "north") {
            next_direction = "south";
        }
        else if (current_direction == "east") {
            next_direction = "west";
        }
        else if (current_direction == "south") {
            next_direction = "north";
        }
        else {
            assert (current_direction == "west");
            next_direction = "east";
        }
    }
    else if (program[next_step] == "forward_1") {
        if (current_direction == "north") {
            next_position = Position(next_position.col,next_position.row+1);
        }
        else if (current_direction == "east") {
            next_position = Position(next_position.col+1,next_position.row);
        }
        else if (current_direction == "south") {
            next_position = Position(next_position.col,next_position.row-1);
        }
        else {
            assert (current_direction == "west");
            next_position = Position(next_position.col-1,next_position.row);
        }
    }
    else if (program[next_step] == "forward_2") {
        if (current_direction == "north") {
            next_position = Position(next_position.col,next_position.row+2);
        }
        else if (current_direction == "east") {
            next_position = Position(next_position.col+2,next_position.row);
        }
        else if (current_direction == "south") {
            next_position = Position(next_position.col,next_position.row-2);
        }
        else {
            assert (current_direction == "west");
            next_position = Position(next_position.col-2,next_position.row);
        }
    }
    else if (program[next_step] == "forward_3") {
        if (current_direction == "north") {
            next_position = Position(next_position.col,next_position.row+3);
        }
        else if (current_direction == "east") {
            next_position = Position(next_position.col+3,next_position.row);
        }
        else if (current_direction == "south") {
            next_position = Position(next_position.col,next_position.row-3);
        }
        else {
            assert (current_direction == "west");
            next_position = Position(next_position.col-3,next_position.row);
        }
    }
    else if(program[next_step] == "do_nothing") {
    }
    else if(program[next_step] == "backward_1") {
        if (next_direction == "north") {
            next_position = Position(next_position.col,next_position.row-1);
        }
        else if (next_direction == "east") {
            next_position = Position(next_position.col-1,next_position.row);
        }
        else if (next_direction == "south") {
            next_position = Position(next_position.col,next_position.row+1);
        }
        else {
            assert (next_direction == "west");
            next_position = Position(next_position.col+1,next_position.row);
        }
    }
    else {


        // ASSIGNMENT: Implement other movements
// push
        std::cerr << "unknown command " << program[next_step] << std::endl;
        exit(0);
    }

    next_step++;
}
//RECURSIVE FUNCTION to find all possible combinations of moves for a robot. 
std::vector<std::vector<std::string> > Robot::recurs_possible(const std::vector<std::string> & commandsavailable) {
    std::vector <std::vector<std::string> > new_sets;
	//basecase
    if (commandsavailable.size() == 1) {
        new_sets.push_back(commandsavailable);

        return new_sets;
    }
    std::vector <std::vector<std::string> > temp_sets;
    std::vector<std::string> previous;
    for (int i = 0; i < commandsavailable.size(); i++) {
        std::vector<std::string> new_set;
        bool check = true;
        for (int p = 0; p < previous.size(); p++) {
            if (previous[p] == commandsavailable[i]) {
                check = false;
                break;
            }
        }
        if (check) {
            previous.push_back(commandsavailable[i]);
            for (int a = 0; a < commandsavailable.size(); a++) {
                if (i != a)
                    new_set.push_back(commandsavailable[a]);
            }
            temp_sets = recurs_possible(new_set);
            for(int o = 0; o < temp_sets.size(); o++) {
                new_sets.push_back(temp_sets[o]);
                new_sets[new_sets.size() - 1].push_back(commandsavailable[i]);
            }

        }
    }

    return new_sets;

}


