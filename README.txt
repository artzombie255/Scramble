Scramble Forward Submission
By: Phoenix Ribiat (the_firebird13, my discord if there are any questions) & Ray Ward



Things that need added/fixed
Animations
- Score on death
- UFO
  - Movement
- Missile
  - Sprite
  - Falling
Pregame loading screens
- Animate screen 1
- Animate screen 4
- Make an actual scoreboard 
Background
- Color change
- Stars/sky
1Up score
- Make it flash
Flag on bottom right
- What does it do
- Why does it add more
Scoreboard
- Show updated scoreboard after game over
- Your score white
- Fuel bar and text blue and red when game over
Make missiles and bullets disappear when they hit the terrain
Level 5 not narrow enough


How it works
Entity is the base class for enemy and player. This manages things that are 
used by the player and enemy and all classes derived from the class enemy. 
The class player manages animations and movement for the player as well as
 interactions with other entities and terrain. The method “hit” deals with 
interactions of missiles or bullets and enemies. The method “crash” deals 
with when the player interacts with an enemy or the terrain. There is a 
vector of enemy pointers which contains all the enemies in the game. The 
classes for each enemy contains the info for that kind of enemy to function. 
The game terrain is contained in LevelArrVec, this is an array of vectors. 
When levels are loaded the levels get added on the back of the array of vectors.
When the player dies, the levels are reloaded with the pre-level at the beginning. 

Enemies Characters
Rocket = R
Ufo = U
Altar = A
Fuel Tower = F
Base = B




