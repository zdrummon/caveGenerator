v0.0.01
---
https://github.com/zdrummon/caveGenerator

Created by 
2021 Daikon Environments
---
Trevor Haggerty - cesismalon@gmail.com
Zachary Drummond - zdrummon@gmail.com

---
DESIGN DOCUMENT
---

steps to generation
 -fill arrays with a uniform int (use the auto for, 0 for all defaults)
 -define room count
 -difine room dimensions
 -define room locations
 -define tunnels
 -difine structured tiles (exempt from smoothing)
 -"smoothing" algorithms
 -define doorways
 -validate the map and respond


ARRAY KEYS
 - 0 - void

buffer array
 - whatever you want, go crazy

biome array
 - pre-regional generation array
 - seeded perlin noise and cellular automata

region array
 - one value per sector (ie area 1, area 2, area 3 as a grid)

region center array
 - list of room centers

movement array
 - 1 - impassable
 - 2 - door
 - 3 - walkable
 - 4 - crawlable
 - 5 - climbable
 - 6 - swimmable

material array
  - 1 - rough natural stone
  - 2 - smooth natural stone
  - 3 - rough constructed stone
  - 4 - smooth constructed stone
  - 5 - loose stone
  - 6 - gravel
  - 7 - sand
  - 8 - dirt
  - 9 - clay
  - 10 - water
  - 11 - wood

visibility array
 - 1 - opaque
 - 2 - semi-transparent
 - 3 - transparent
 - 4 - reflective

lighting array
 - 1 - dark
 - 2 - dim
 - 3 - light
 - 4 - bright
 - 5 - blinding

entity array
  - 1 - player
  - 2 - key
  - 3 - badman
  - 4 - glowing mushroom
  - 5 - sword
  - 6 - small rock
  - 7 - trophy
  - 8 - bait
  - 9 - rope
  - 10 - clock
  - 11 - map

bool inventory array
 - [0] - key
 - [1] - sword
 - [2] - small rock
 - [3] - trophy
 - [4] - bait
 - [5] - rope
 - [6] - map

fog of war array
 - 1 - unseen
 - 2 - visible
 - 3 - remembered
 - 4 - partially remembered
 - 5 - forgotten

graphics array
 - ascii shit will list later

save the array to a file
 - parse array state and output data stream

load that array from file
 - input data stream and parse to array state

game loop
  -objectives
  -adventure!