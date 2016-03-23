HOMEWORK 6: ROBO RALLY RECURSION


NAME:  Jacob Martin


TIME SPENT ON THIS ASSIGNMENT:  <26 of hours>


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassment, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

TA BEN
Alac Tutor whos name I forgot.
Coleridge

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)
My program had two recursive functions. One, recurs_possible which ran at the beginning of robots making a vector of every possible combination of moves but excluding repeats. 
This function was only called once and then saved to save efficiency. This was steps factorial aka O(steps!). 
I also had a robot copy method which copied a previous robot but took in new steps. This function DID NOT call or use the recursive permutation method and therefore was O(steps).
In my main class I had another recursive function. This combined the return of paths from recursive_possible for all robots. 
Both combined became O(steps!)^robots. This does not include the base case which was my Move Checker. 
For checking for collisions and bad moves in each basecase it was O(steps*robots + steps^3*robots). 
It started by making robot copies with the paths it needed to check which was O(steps*robots).  O(steps*robots*Collisions) which checked for collisions and out of bounds.
Collisions were (steps^2) due to the vector checking itself for copies. Inputs was O(steps*robots). Run was O(2*(robots*steps)).  The total was O( (steps!)^robots*(3*steps*robots + steps^3*robots) + steps*robots )

SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
Everything was ok for the most part but there was a lot of unnecessary copying of robots or combinations in my two recursive functions that were unnecessary because I could readd them later. 
If I had more time I definetly would have done this.


MISC. COMMENTS TO GRADER:  
This project killed me. I went to many TA office hours and ALAC nights but the problem was I wrote the program a bit differently from most people and 
I usually caught a TA who had to leave soon leading to me being stumped for long amounts of time.


