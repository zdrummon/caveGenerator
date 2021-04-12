

//top row 128 char wide, 8 char tall
//left column 32 char wide, 32 char tall
//board array 64 char wide, 32 char tall
//right column 32 char wide, 32 char tall
//bottow row 128 char wide, 24 char tall

/*
╭━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━╥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╥━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━╮
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
╞═══════════════##═══════════════╬════════════════════════════════##══════════════════════════════╬═══════════════##═══════════════╡
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxq|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#
#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
╞═══════════════##═══════════════╬════════════════════════════════##══════════════════════════════╬═══════════════##═══════════════╡
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|
╰━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━╨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╨━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━╯

╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╥━━━━━━━##━━━━━━━╮
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
╞════════════════════════════════##══════════════════════════════╬═══════##═══════╡
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#xxxxxxxxxxxxxxxx#
#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#xxxxxxxxxxxxxxxx#
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
╞════════════════════════════════##══════════════════════════════╬═══════##═══════╡
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx║xxxxxxxxxxxxxxxx|
╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━##━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╨━━━━━━━##━━━━━━━╯
*/


void generateScreenArray() {

  string screen[];
  string bufferStr = "";

  enum screenShape {compact, wide};

  int rowBar1, rowBar2, colBar1, colBar2;
  int region1, region2, region3, region4, region5, region6, region7, region8, region9;

  for (int i = 0; i < 128; i++) {
    for(int j = 0; j < 43; j++) {

    }
  }


    if(j < topScreen){
      // the title area or whatever
    }
    
    else if(j < (maxY + topScreen) && j > topScreen){
      // the screen and side bars
    }
    
    else if(j > (maxX + topScreen) ){
      // promptland
    }
    
    else{
      //there is a thing thing
    }
    bufferStr = "";
    screen[j] = bufferStr;
  }
}