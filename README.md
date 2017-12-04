# filler
The purpose of filler is to create a competitive AI that succeeds in placing a higher volume of random tetromino shapes against the stock AIs found in the resources directory. Each player is provided a starting location on a given map and must alternate between turns placing one piece at a time. The game is considered complete when a player can no longer place it's received piece in accordance to the rules and the winner is the AI that placed the most pieces. The rules of the game are very simple:

<li>
  <ol>Placement can only lie within the confines of the map.</ol>
  <ol>Each new piece must overlap with a single grid unit of the player's existing mass of tetrominos.</ol>
  <ol>There can be no overlapping with existing pieces placed on the board.</ol>
</li>

Example of terminal command and virtual machine output

![screenshot from 2017-12-04 14-52-28](https://user-images.githubusercontent.com/13093517/33580656-db83bc2e-d902-11e7-8f79-ac69380f312d.png)

## Key Details

## Implementation


Once inside the resources directory, the project can be run in the following format: 
```
./filler_vm -f maps/map02 -p1 players/carli.filler -p2 ../kromain.filler
```


## Acknowledgement

This project was developed at École 42 USA in Fremont, California.
