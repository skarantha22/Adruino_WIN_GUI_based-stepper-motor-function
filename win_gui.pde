import controlP5.*; //import ControlP5 library
import processing.serial.*;

Serial port;

ControlP5 cp5; //create ControlP5 object

void setup(){ //Same as setup in arduino
  
  size(300, 300);                          //Window size, (width, height)
  port = new Serial(this, "COM11", 9600);   //Change this to your port
  
  cp5 = new ControlP5(this);
  
  cp5.addButton("UP")  //The button
    .setPosition(100, 100)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
  ;     
  
  cp5.addButton("DOWN")  //The button
    .setPosition(100, 200)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
  ;     
cp5.addButton("RIGHT")  //The button
    .setPosition(10, 150)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
  ;     
cp5.addButton("LEFT")  //The button
    .setPosition(190, 150)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
  ;  

}

void draw(){  //Same as loop in arduino

  background(150, 0 , 150); //Background colour of window (r, g, b) or (0 to 255)
    
}

void UP(){
  
  port.write('U');
  
}
void DOWN(){
  
  port.write('D');
  
}
void RIGHT(){
  
  port.write('R');
  
}
void LEFT(){
  
  port.write('L');
  
}
