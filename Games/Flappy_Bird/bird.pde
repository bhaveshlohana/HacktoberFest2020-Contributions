class Bird
{
  //-----------------Data members of our Bird Class--------------
  PVector pos;
  PVector vel;
  PVector acc;
  float r = 16;
  //------------------Functions of our Bird Class-----------------
  // Constructor to Intialize our Bird object
  Bird() {
    pos = new PVector(50, height/2); // Initial position of the bird
    vel = new PVector(0, 0);  // Initial velocity of the bird
    acc = new PVector(); // Initial accleration of the bird
  }

  void applyForce(PVector force)
  {
    acc.add(force); // Increment the acceleration by the parameter force
  }

  void update() 
  {
    // For every frame
    applyForce(gravity); // The bird object is acted upon by a gravitational force that pulls it down 
    pos.add(vel); // The position of the bird is incremented by the distance travelled per unit time
    vel.add(acc); // The velocity of the bird is incremented by the change of speed per unit tiime
    vel.limit(4); // The maximum speed of the bird is given a threshold of 4 ( Note here it is related to the pixels)  
    acc.mult(0);

    if (pos.y > height) // If the bird tends to escape our screen
    {
      pos.y = height; // Stop it at the edge
      vel.mult(0); // Make the velocity zero
    }
  }

  void show() {
    stroke(0,0,0); // Color of the outline of our bird object (Black)
    strokeWeight(2); // Thickness of the outline 
    fill(224, 218, 34); // Color of the interior of our bird object
    ellipse(pos.x, pos.y, r*2, r*2);// Shape of the bird object
  }
}
