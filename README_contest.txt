HOMEWORK 6 CONTEST: ROBO RALLY RECURSION CONTEST


NAME:  Jacob Martin


DESCRIPTION OF PERFORMANCE IMPROVEMENTS/OPTIMIZATIONS:
My program had two recursive functions. One, recurs_possible which ran at the beginning of robots making a vector of every possible combination of moves but excluding repeats. 
This function was only called once and then saved to save efficiency. This was steps factorial aka O(steps!). 
I also had a robot copy method which copied a previous robot but took in new steps. This function DID NOT call or use the recursive permutation method and therefore was O(steps).
In my main class I had another recursive function. This combined the return of paths from recursive_possible for all robots. 
Both combined became O(steps!)^robots. This does not include the base case which was my Move Checker. 
For checking for collisions and bad moves in each basecase it was O(steps*robots + steps^3*robots). 
It started by making robot copies with the paths it needed to check which was O(steps*robots).  O(steps*robots*Collisions) which checked for collisions and out of bounds.
Collisions were (steps^2) due to the vector checking itself for copies. Inputs was O(steps*robots). Run was O(2*(robots*steps)).  The total was O( (steps!)^robots*(3*steps*robots + steps^3*robots) + steps*robots )



DESCRIBE INTERESTING NEW PUZZLES YOU CREATED:
None unfortunately.


SUMMARY OF YOUR PERFORMANCE ON ALL PUZZLES:
Average but especially slow finding all solutions on 3. There is some unnecessary copying in t he robot function.


