class Pipe
{
//-----------------Data members of our Pipe Class--------------
  float x;
  float top; 
  float bottom;
  float w = 40;
  float pipe_speed = 3;
//------------------Functions of our Pipe Class-----------------
// Constructor to Intialize our Pipe object
  Pipe() 
  {
    x = wid + w;
    top = random(100, height/2); // height of the top pipe
    bottom = random(100, height/2); // height of the bottom pipe
    // 100 is the minimum height of the pipes while the maximum height is 200
  }
// Check if there is any collision between the bird and the pipes 
  boolean hits(Bird b) 
  {
    if ((b.pos.x > x) && (b.pos.x < (x + w))) // if the bird lies within the width of the pipe
    {
      if ((b.pos.y < (top + b.r)) || (b.pos.y > (height - bottom - b.r))) 
      // If the bird is either below the upper pipe or above the lower pipe
      {
        return true; // There is a collision
      }
    }
    return false; // There is no collision
  }
// Progress the pipes
  void update()
  {
    x -= pipe_speed;
  }

// Show the pipes
  void show(boolean hit)
  {
    stroke(0,0,0); // Color of the outline of our pipes (Black)
    strokeWeight(2); // thickness of the outline 
    if (hit) // If the Pipe hits the bird
    {      
      fill(217, 74, 30,127); // Change color to reddish
    } 
    else // If the pipe does not hit the bird
    {
      fill(65,224,129,127); // Change the color to greenish
    }
    // create the pipes
    rect(x, 0, w, top);  // Upper Rectangular Pipe
    rect(x, height - bottom, w, bottom); // Lower Rectangular Pipe
  }
}
