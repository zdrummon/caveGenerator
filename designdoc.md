
# CAVE GENERATOR
> ### v0.0.02

| Trevor Haggerty | Zachary Drummond |
| ------------- | ------------- |
| cesismalon@gmail.com | zdrummon@gmail.com | 

---
### Documentation
> Cave Generator is a simple and procedural roguelike puzzle-game that outputs a game world to the console window using C++ for a class project. Starring Trevor Haggerty and his co-host Zachary Drummond.

---
#### appendix
1. [documentation template](#section-anchor)
2. [array keys](#array-keys) - [(code)](main.cpp)
    1. [movement array key](designdoc.md#movement-array-key) - [(code)](main.cpp)
    2. [material array key](#material-array-key) - [(code)](main.cpp)
    3. [visibility array key](#visibility-array-key) - [(code)](main.cpp)
    4. [lighting array key](#lighting-array-key) - [(code)](main.cpp)
    5. [entity array key](#entity-array-key) - [(code)](main.cpp)
    6. [bool inventory array key](#bool-inventory-array-key) - [(code)](main.cpp)
    7. [fog of war key](#fog-of-war-key) - [(code)](main.cpp)
    8. [graphics output ascii array key](#graphics-output-ascii-array-key) - [(code)](main.cpp)
3. [documentation notes (unformmated)](#disordered-documentation)
4. [caveGenerator page on Github](https://github.com/zdrummon/caveGenerator)

---
documentation template:
### section anchor
Paragraph of explanation about the topic being discussed

value | meaning
|-----------|-----------|
1 | a
2 | b
3 | c
4 | d

[return to appendix](#appendix)

---
# array keys
### global array key
value | meaning
|-----------|-----------|
0 | void

---
### movement array key
value | meaning
|-----------|-----------|
1 | impassable
2 | door
3 | walkable
4 | crawlable
5 | climbable
6 | swimmable

[return to appendix](#appendix)

---
### material array key
value | meaning
|-----------|-----------|
1 | rough natural stone
2 | smooth natural stone
3 | rough constructed stone
4 | smooth constructed stone
5 | loose stone
6 | gravel
7 | sand
8 | dirt
9 | clay
10 | water
11 | wood

[return to appendix](#appendix)

---
### visibility array key
value | meaning
|-----------|-----------|
1 | opaque
2 | semi-transparent
3 | transparent
4 | reflective

[return to appendix](#appendix)

---
### lighting array key
value | meaning
|-----------|-----------|
1 | dark
2 | dim
3 | light
4 | bright
5 | blinding

[return to appendix](#appendix)

---
### entity array key
value | meaning
|-----------|-----------|
1 | player
2 | key
3 | badman
4 | glowing mushroom
5 | sword
6 | small rock
7 | trophy
8 | bait
9 | rope
10 | clock
11 | map

[return to appendix](#appendix)

---
### bool inventory array key
value | meaning
|-----------|-----------|
[0]|key
[1]|sword
[2]|small rock
[3]|trophy
[4]|bait
[5]|rope
[6]|map

[return to appendix](#appendix)

---
### fog of war array key
value | meaning
|-----------|-----------|
1 | unseen
2 | visible
3 | remembered
4 | partially remembered
5 | forgotten

[return to appendix](#appendix)

---
### graphics output ascii array key
value | meaning
|-----------|-----------|
†☻ | player
☹► | badman
██ | visible wall
▓▓ | remembered wall
▒▒ | visible floor
░░ | remembered floor
≋≋ | water
⛶⛶ | cloud
▦▦ | boxes
⚿⚿ | locked door
⌸⌸ | closed door
⍠⍠ | open door
▛▜ | tunnel
▅▅ | ledge
⍾⍾ | mushroom patch
⚶⚶ | plants
⌼█ | mirror
⍜█ | clock
⚷▒ | key 
⛹▒ | trophy
†▒ | sword
⛨▒ | bait
☸▒ | map

[return to appendix](#appendix)

---

# disordered documentation

#### generation order
 -fill arrays with a uniform int (use the auto for, 0 for all defaults)
 -define room count
 -difine room dimensions
 -define room locations
 -define tunnels
 -difine structured tiles (exempt from smoothing)
 -"smoothing" algorithms
 -define doorways
 -validate the map and respond


room structures
 - x location 
 - y location
 - width
 - height

buffer array
 - whatever you want, go crazy

biome array
 - pre-regional generation array
 - seeded perlin noise and cellular automata

region array
 - one value per sector (ie area 1, area 2, area 3 as a grid)

room array
 - List of room structures

graphics array
 - ascii shit will list later

save the array to a file
 - parse array state and output data stream

load that array from file
 - input data stream and parse to array state

game loop
  -objectives
  -adventure!

unordered unicode:
Δ   Λ   ∎   ⊕   ⊖   ⊗   ⊘   ⊙   ⊚   ⊛   ⊜   ⊝   ⊞   ⊟   ⊠   ⊡
⊢ 	⊣ 	⊤ 	⊥ 	⊦ 	⊧ 	⊨ 	⊩ 	⊪ 	⊫ 	⊬ 	⊭ 	⊮ 	⊯ ★ 	☆
∣ 	∤ 	∥ 	∦   ≏   ⋈   ⌧ ⁂ †   	•  	‡  	‗ ₪ ₾ ⇱ ⇲ ☠  	☢
⌲ 	⌳ 	⌴ 	⌵ 	⌶ 	⌷ 	⌸ 	⌹ 	⌺ 	⌻ 	⌼ 	⌽ 	⌾ 	⌿ ☀
⍀ 	⍁ 	⍂ 	⍃ 	⍄ 	⍅ 	⍆ 	⍇ 	⍈ 	⍉ 	⍊ 	⍋ 	⍌ 	⍍ 	⍎ 	⍏
⍐ 	⍑ 	⍒ 	⍓ 	⍔ 	⍕ 	⍖ 	⍗ 	⍘ 	⍙ 	⍚ 	⍛ 	⍜ 	⍝ 	⍞ 	⍟
⍠ 	⍡ 	⍢ 	⍣ 	⍤ 	⍥ 	⍦ 	⍧ 	⍨ 	⍩ 	⍪ 	⍫ 	⍬ 	⍭ 	⍮ 	⍯
☼ 	☽ 	☾   ☸ 	☹ 	☺ 	☻   ⛹ ⛨ ⚿ ⛶ ⛭ 	⛮ 	⛯

━ 	┃  	┅ 	┇ 	┉ 	┋ 	┏   ┓ 	┗ 	┛ 	┣ 	┫ 	┳ 	┻ 	╋ 	╍ 	╏   ╭ 	╮ 	╯   ╰  	╳ 	╹ 	╺ 	╻
═ 	║ 	╒ 	╓ 	╔ 	╕ 	╖ 	╗ 	╘ 	╙ 	╚ 	╛ 	╜ 	╝ 	╞ 	╟
╠ 	╡ 	╢ 	╣ 	╤ 	╥ 	╦ 	╧ 	╨ 	╩ 	╪ 	╫ 	╬ 	

﹏
╭━━━━━╮ 
┃-----┃
┃-----┃
┃-----┃
╰━━━━━╯


▀ 	▁ 	▂ 	▃ 	▄ 	▅ 	▆ 	▇ 	█ 	▉ 	▊ 	▋ 	▌ 	▍ 	▎ 	▏
▐ 	░ 	▒ 	▓ 	▔ 	▕ 	▖ 	▗ 	▘ 	▙ 	▚ 	▛ 	▜ 	▝ 	▞ 	▟ 
■   □   ▢   ▣   ▤   ▥   ▦  	▧ ▨ ▩ 	▪  	▫ ▬ ▭  	▮ ▯ ▰ ▱ 
 	▲ △ ▴ ▵  	▶ ▷ ▸ ▹ ► ▻ ▼ ▽ ▾ ▿ ◀ ◁◂◃◄◅◆◇◈◉◊○◌◍◎●◐◑◒◓
◔◕◖◗◙◚◛◜◝◞◟◠◡