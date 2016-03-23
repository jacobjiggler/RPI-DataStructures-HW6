//to do:
//check for crash :: check area :: test case right next to each other going into each other.
//readme file
//comment code
//allow pushing
//reindent
// rewrite with lists instead of vectors


#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <string>
#include "robot.h"
#include "board.h"

using namespace std;
// ======================================================================================
// helper functions
typedef vector <string> path;
void ReadInput(std::istream &istr, Board &board, std::vector<Robot> &robots);
void Run(const Board &board, std::vector<Robot> &robots);
void print_usage_message(std::string program_name) {
    std::cerr << "Usage:  " << program_name << " <input.txt> [ -find_all_solutions ] [ -verbose ] [ -allow_pushing ]" << std::endl;
}
//my recursive function which creates all combinations and checks them.
void Check_Valid(bool & find_all_solutions, bool & allow_pushing,const vector<Robot> & robots, vector<Robot> & robotsnew, vector<path> & paths, vector<vector<path> > & passed_paths, Board & board);

// ======================================================================================

int main(int argc, char* argv[]) {

    // print usage information
    if (argc < 2) {
        print_usage_message(argv[0]);
        exit(1);
    }

    bool find_all_solutions = false;
    bool allow_pushing = false;
    bool verbose = false;

    // process the command line arguments
    for (int i = 2; i < argc; i++) {
        if (std::string(argv[i]) == "-find_all_solutions") {
            find_all_solutions = true;
        } else if (std::string(argv[i]) == "-allow_pushing") {
            allow_pushing = true;
        } else if (std::string(argv[i]) == "-verbose") {
            verbose = true;
        } else {
            std::cerr << "Unknown command line argument: " << argv[i] << std::endl;
            print_usage_message(argv[0]);
            exit(1);
        }
    }

    // open the input file
    std::ifstream istr(argv[1]);
    if (!istr) {
        std::cerr << "Failed to open " << argv[1] << std::endl;
        exit(1);
    }

    // read the board & robot information
    Board board;
    vector<Robot> robots;

    if (find_all_solutions == false) {
        cout << "Searching for just one solution..." << endl;
    }
    else {
        cout << "Searching for all solutions..." << endl;
    }
    ReadInput(istr,board,robots);

    vector<Robot> robot2 = robots;


    // ASSIGNMENT: change as needed
    // for now, let's just run the commands in the order provided

    // Run(board,robots,used_commands);



//creation of passed by reference values for recursive function.
    vector<vector <string> >  paths;
    vector<vector<vector <string> > >  passed_paths;



    Check_Valid(find_all_solutions,allow_pushing,robots,robot2,paths,passed_paths,board);




//Running of paths that passed the test.
    for (int i = passed_paths.size() - 1; i >= 0; i--) {
        if (i == 0 || find_all_solutions == true) {
            vector<Robot> temprobots;

            for (int l = 0; l < robots.size(); l++) {
//copying of robots but not their paths and inserting indidivual path combinations.
                Robot temp(robots[l],passed_paths[i][l]);

                temprobots.push_back(temp);
            }

            Run(board,temprobots);
        }

    }

//nothing found check
    if (passed_paths.size() == 0) {
        cout << "Found no solutions" << endl;
    }
    else {
		//at least one found.
        if (passed_paths.size() != 0 && find_all_solutions == true) {
            cout << "Found "<< passed_paths.size() <<" solution(s)" << endl;
        }
    }
}
//recursive function finding combinations and then at basecase checking them to see if they are valid.
typedef vector<string>  path;
void Check_Valid(bool & find_all_solutions, bool & allow_pushing,const vector<Robot> & robots, vector<Robot> & robotsnew, vector<path> & paths, vector<vector<path> > & passed_paths, Board & board) {
//check to see if an early end is necessary after finding one function   
if (passed_paths.size() != 0 && find_all_solutions == false) {
        return;
		
    }
//basecase
// here is where the next move is checked to be valid and without collisions.
    if (robotsnew.size() == 0) {
        assert( paths.size() == robots.size());
        vector<Robot> temprobots;
		//robots paths are created to be tested.
        for (int l = 0; l < robots.size(); l++) {
            Robot temp(robots[l],paths[l]);
            temprobots.push_back(temp);
        }

        for (int f = 0; f < paths[0].size(); f++) {
            vector<Position> moved_across;
            for (int y = 0; y < paths.size(); y++) {


               //testing for out of boundaries.
                if (temprobots[y].getNextPosition().row < 0 ||  temprobots[y].getNextPosition().col < 0 || temprobots[y].getNextPosition().row >= board.numRows() || temprobots[y].getNextPosition().col >= board.numCols()) { //correct
                   
                    return;

                }
				//End test to see if at the finish
                if (f == paths[0].size() - 1 && (temprobots[y].getNextPosition().row != temprobots[y].getGoalPosition().row ||  temprobots[y].getNextPosition().col != temprobots[y].getGoalPosition().col)) {
                  
                    return;
                }
				//COLLISION CHECKS.
				//Positions traveled across or settled at are recorded.
                if (temprobots[y].getNextPosition().row == temprobots[y].getCurrentPosition().row && temprobots[y].getNextPosition().col == temprobots[y].getCurrentPosition().col) {
                    moved_across.push_back(Position(temprobots[y].getCurrentPosition().col,temprobots[y].getCurrentPosition().row));
                }
                else {
                    for (int i = 0; i < abs(temprobots[y].getNextPosition().row - temprobots[y].getCurrentPosition().row); i++) {
                        if	(temprobots[y].getNextPosition().row > temprobots[y].getCurrentPosition().row) {
                            moved_across.push_back(Position(temprobots[y].getCurrentPosition().col,temprobots[y].getCurrentPosition().row + i));
                        }
                        else {
                            moved_across.push_back(Position(temprobots[y].getCurrentPosition().col,temprobots[y].getCurrentPosition().row - i));
                        }
                    }
                    for (int i = 0; i < abs(temprobots[y].getNextPosition().col - temprobots[y].getCurrentPosition().col); i++) {
                        if (temprobots[y].getNextPosition().col > temprobots[y].getCurrentPosition().col) {
                            moved_across.push_back(Position(temprobots[y].getCurrentPosition().col + i,temprobots[y].getNextPosition().row));
                        }
                        else {
                            moved_across.push_back(Position(temprobots[y].getCurrentPosition().col - i,temprobots[y].getNextPosition().row));
                        }
                    }
                }
//move call to check next move.
               
                temprobots[y].move();
            }
//
            if (moved_across.size() > 0) {
               //check to see if any are repeating for that turn to see if there are collisions.
                for (int i = 0; i < moved_across.size() - 1; i++) {
                    for (int j = i + 1; j < moved_across.size(); j++) {
                        if (moved_across[i] == moved_across[j]) {
                            if (allow_pushing == false) {
                               
                                return;
                            }
                            else {
                                cout << "this is wrong" << endl;
                                return;
                            }

                        }
                    }
                }
            }

        }
//every check has passed. Add this to the list of passed.
        passed_paths.push_back(paths);



        return;

    }

//non base case
	//pops off a robot temporarily while calling the recursive function to combine the possible path combinations of different robots.

    Robot r = robotsnew[robotsnew.size() - 1];
    robotsnew.pop_back();
    for(int e = 0; e < r.getallpossible().size(); e++) {
        paths.push_back(r.getallpossible()[e]);
        Check_Valid(find_all_solutions,allow_pushing,robots,robotsnew,paths,passed_paths,board);
        paths.pop_back();
    }
    robotsnew.push_back(r);
    return;








}


// ======================================================================================








// Parse the input file
void ReadInput(std::istream &istr, Board &board, std::vector<Robot> &robots) {

    // read in the board dimensions
    std::string token;
    int cols, rows;
    istr >> token >> cols >> rows;
    assert (token == "board");
    assert (cols >= 1 && rows >= 1);
    int num_steps;
    istr >> token >> num_steps;
    assert (token == "num_steps");
    assert (num_steps >= 1);

    // create the board
    board = Board(cols,rows,num_steps);

    // read in the number of robots & number of program steps
    int num_robots;
    istr >> token >> num_robots;
    assert (token == "num_robots");
    assert (num_robots >= 1);

    for (int i = 0; i < num_robots; i++) {

        // read in each robot
        char symbol;
        istr >> token >> symbol;
        assert (token == "robot");
        int start_col, start_row;
        std::string direction;
        istr >> token >> start_col >> start_row >> direction;
        assert (token == "start");
        assert (start_col >= 0 && start_col < cols);
        assert (start_row >= 0 && start_row < rows);
        int goal_col, goal_row;
        istr >> token >> goal_col >> goal_row;
        assert (token == "goal");
        assert (goal_col >= 0 && goal_col < cols);
        assert (goal_row >= 0 && goal_row < rows);

        // read the commands into a list structure
        std::vector<std::string> programs;
        for (int j = 0; j < num_steps; j++) {
            istr >> token;
            programs.push_back(token);
        }
        assert (board.numSteps() == programs.size());
        // create a new robot and add to the rowlection
        Robot robot(symbol,&board,Position(start_col,start_row),direction,Position(goal_col,goal_row),programs);
        robots.push_back(robot);
    }
}

// ======================================================================================

// This function runs the programs stored in each robot on the shared board

// ASSIGNMENT: This function shows you how to use the provided code,
// but you'll need to change / rewrite this in order to rearrange the
// commands in each robot to find all solutions to the problem

void Run(const Board &board, std::vector<Robot> & robots) {
//printing out of the solutions and the paths taken.
    cout << "Solution:" << endl;
    for (unsigned int j = 0; j < robots.size(); j++) {
        cout << "Robot " << robots[j].getSymbol() << ": ";
        for (int h = 0; h < board.numSteps(); h++) {
            cout << (robots[j].getProgram())[h];
			if (h < board.numSteps() - 1)
		cout << ", ";
        }

        cout << endl;
    }


    // store all the ascii boards in a vector so we can print them out in a neat row
    std::vector< std::vector<std::string> > boards;

    // the starting point
    boards.push_back(board.print(robots));


// if (verbose == false){

//begin pringint boards
    // loop through each step
    for (int i = 0; i < board.numSteps(); i++) {
        // move each robot
        // cout << "aa" << endl;
        for (unsigned int j = 0; j < robots.size(); j++) {
            robots[j].move();
        }

        // add the current state to the vector
        boards.push_back(board.print(robots));
        // cout << "bb" << endl;
    }

    // print out a row of all the boards in a row
    for (unsigned int j = 0; j < boards[0].size(); j++) {
        for (unsigned int i = 0; i < boards.size(); i++) {
            std::cout << boards[i][j] << "   ";
        }
        std::cout << std::endl;
    }
//}




}

// ======================================================================================



