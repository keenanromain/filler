# filler
The purpose of filler is to create a competitive AI that succeeds in placing a higher volume of random tetromino shapes against the stock AIs found in the resources directory. Each player is provided a starting location on a given map and must alternate between placing one piece per day. The game is complete when a player can no longer place a piece in accordance to the rules and the winner is determined why which program placed the most pieces. The rules of the game:

<ol>
  <li>Placement can only lie within the confines of the map.</li>
  <li>Each new piece must overlap with a single grid unit of the player's existing mass of tetrominos.</li>
  <li>There can be no overlapping with existing pieces placed on the board.</li>
</ol>

Example of a command to begin the game and the initial corresponding VM output:

![screenshot from 2017-12-04 16-59-06](https://user-images.githubusercontent.com/13093517/33584510-9b4d4b5e-d914-11e7-9348-7a9bb2fc1ab8.png)


## Key Details

The initial phase of this project was to become familiar with reading and parsing the filler virtual machine's output. As seen in the screenshot above, the filler_vm is executed with the -f flag to specificy the map for the game to be played on as well as the two different players via the -p1 and -p2 flags. After an initial message of credit to the VM's developers, the game begins.
<br />
<br />
In order of appearance, the VM outputs the map's dimensions, the map itself with coordinates along both the X-axis and Y-axis, the piece's dimenions, and the piece represented in this example as two asteriks: <br/>
`
* 
` <br/>
`
*
` <br/>
In order to place the game piece on the board, each player must write out it's preferred coordinates to the standard out which is then received by the VM. To determine said preferred coordinates, the project specifications were entirely open-ended to permit creativity. The solution I came up with used a dynamic heat map for creating a maximum-cost path algorithm in order to place each piece on prime real estate. The algorithm initially prioritized the middle of the board before drawing a cross to limit the mobility of the opponent. From there, the vertical pillar expands outward taking up all open space in cyclical fashion. Before diving into the code, a few screenshots will be displayed of the algorithm in action. Note ~ the opponent's sprawl is set by the O character while mine uses the X character:

<p align="center"><img width="328" alt="screen shot 2017-12-05 at 2 39 04 pm" src="https://user-images.githubusercontent.com/13093517/33747846-1a75e0c8-db7a-11e7-87b9-a74f9f13dcd7.png">
<br/>
<sub>This particular opponent's strategy uses a top-down flood-fill approach. The flood-fill approach is incorporated in my algorithm, but it first rushes to the middle, spans upwards and downwards, then left to right in an attempt to set boundaries against the opponent. The reasoning behind this is simple; by cutting off the enemy, I increase my own chances of winning.</sub>
<br/><br/>
<img width="319" alt="screen shot 2017-12-05 at 2 42 23 pm" src="https://user-images.githubusercontent.com/13093517/33747845-1a69a84e-db7a-11e7-85cb-31551ad792c5.png">
<br/>
<sub>The next step to my algorithm is to expand outward via the vertical column. The initial step of splitting the board into four separate quadrants to contain the enemy almost guarantees empty area at the end for my algorithm's own exploitation. Note ~ Pieces read from the VM can include periods to denote empty space. Only the asteriks in a piece matter.</sub>
<br/><br/>
<img width="319" alt="screen shot 2017-12-05 at 2 42 47 pm" src="https://user-images.githubusercontent.com/13093517/33747844-1a5905de-db7a-11e7-8500-4ffe2e1245f1.png">
<br/>
<sub>The opponent's algorithm and my own continue to trade turns flooding the board until the opponent runs into my barriers and fails to place it's piece in a valid manner as set by the rules. My algorithm wins.</sub>
<br/><br/></p>
With this visual demonstration now complete, a review of the code that made it possible is up next. To begin, a peek of main shows the overview functionality of the program. The initial parsing of the map and it's conversion to an integer-based heat-map is done in the function *setup_map*. The function, *update_map*, checks for the opponent's new move at every turn and the placing of each new piece occurs whenever the opponent completed a valid move. Finally, the map is freed before the program ends. <br/><br/>

<img width="305" alt="screen shot 2017-12-05 at 2 53 41 pm" src="https://user-images.githubusercontent.com/13093517/33782285-f5a8256a-dc0c-11e7-8ae7-0102c0ea28bb.png">

The call to *get_right_line*, a function that loops a custom version of <a href="http://man7.org/linux/man-pages/man3/getline.3.html">getline</a> until the parameter passed to it matches the read input, gives the correct line from the VM output to begin with. This line is passed to *setup_map* as it contains the information of which player is first and which is second.

<img width="386" alt="screen shot 2017-12-05 at 2 54 10 pm" src="https://user-images.githubusercontent.com/13093517/33782638-565abfc0-dc0e-11e7-8ca7-efebc153455b.png">

After determining the appropriate values for each player, *get_right_line* is called again to find the dimensions of the map. These values are broken into the numbers of rows and columns required before the rest of the struct for this project is initialized. After the initialization, the creation of the heat map occurs in three steps: 
<ol>
  <li>A border around the map is set and the interior of the map is filled with ones as a starting value</li>
  <li>The map is then split into quadrants to allow the algorithm to work as needed</li>
  <li>The algorithm runs for each quadrant, modifying the ones into the appropriate numbers for later evaluation</li>
</ol>

Step two is where things get interesting, so that is what will be discussed next. From obtaining the length and width of the map and then splitting those values in half, it's now possible to overlay the heat-map with four different sections. Each quadrant iterates towards the middle of the entire board so the functions responsible for each differ slightly. The first and fourth functions, for example, run in the opposite directions of each other as seen below:

top-left quadrant iterating towards the middle:

<img width="359" alt="screen shot 2017-12-05 at 2 55 10 pm" src="https://user-images.githubusercontent.com/13093517/33783403-7bcaf4ca-dc11-11e7-8359-d8197da88015.png">

bottom-right quadrant iterating towards the middle:

<img width="376" alt="screen shot 2017-12-05 at 2 58 04 pm" src="https://user-images.githubusercontent.com/13093517/33783408-830e69ba-dc11-11e7-8e70-fe871be18378.png">

Each coordinate of a quadrant calls a function responsible for computing the algorithmic value. *q1*, as seen in *top_left*, shows what the algorithm looks like.

<img width="563" alt="screen shot 2017-12-05 at 2 55 32 pm" src="https://user-images.githubusercontent.com/13093517/33783579-3341ec80-dc12-11e7-8dac-23a74ff3fda9.png">

Each cell of the matrix represents a cost, initially one, to traverse through that cell. The total cost of a path to reach the end of it's row is sum of all the costs on that path. To increase the weight towards the middle of the board (in this example, the bottom-right of the lop-left quadrant), the algorithm computes the cost in each cell against the maximum value of the adjacent cells that are further away from the middle and the algorithm incoporates a 10x multiplier for all elements in the exact middle row of the board.

## Implementation

To run this project, clone this repo into your terminal and generate the executable via the make command.
```
git clone https://github.com/keenanromain/filler.git
cd filler
rm -rf libft
git clone https://github.com/keenanromain/libft.git
make
```
A successful make command will create an executable called 'kromain.filler'. Navigate into the resouces directory to run the project in the following format:

```
./filler_vm -f maps/map02 -p1 players/hcao.filler -p2 ../kromain.filler
```

The executable for this project can be run either as first or second player and can fight any of the stock AIs found in the players directory on any of the maps.


## Acknowledgement

This project was developed at École 42 USA in Fremont, California.
