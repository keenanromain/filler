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
In order of appearance, the VM outputs the map's dimensions, the map itself with coordinates along both the X-axis and Y-axis, the piece's dimenions, and the piece represented in this example as two asteriks:

`
* 
` <br/>
`
*
`

## Implementation


Once inside the resources directory, the project can be run in the following format: 
```
./filler_vm -f maps/map02 -p1 players/carli.filler -p2 ../kromain.filler
```


## Acknowledgement

This project was developed at École 42 USA in Fremont, California.
