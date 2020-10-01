Bird b; 
int wid = 400;
int rez = 20;
int score = 0; 
boolean jumping = false;
PVector gravity = new PVector(0, 0.5);
ArrayList<Pipe> pipes = new ArrayList<Pipe>(); // Declare an array object of the type pipes (Typically for the pipes being generated sequentially in the game)
PImage mountain; // Declare an image object for the background


void setup() {
  size(800, 800); // Create a canvas of width 400 pixels and height 800 pixels 
  b = new Bird(); // Intializing our bird object
  pipes.add(new Pipe()); // Add a Pipe object to the list of pipes
  mountain = loadImage("guillaume-galtier-3YrppYQPoCI-unsplash.jpg"); 
  
  
}

// This function runs multiple times
void draw() {
  background(0, 0, 0); // Setting the default background color to black
  image(mountain,0,0); // Now we put our background image
  if (frameCount % 55 == 0) /// this is the point in which wwe can set the level of conjustancy or relax path for bird... eg 25<=conjust ,vice versa
  {
    pipes.add(new Pipe());
  }

  if (keyPressed) // this can be done with space bar automatically
  {
    PVector up = new PVector(0, -5);  // The variable for displacement of bird object
    b.applyForce(up); // Displace the bird object up by 5 pixels
  }

  b.update();
  b.show();
  boolean safe = true; // A flag variable to indicate if our bird object collided with a pipe object

  for (int i = pipes.size() - 1; i >= 0; i--)
  {
    Pipe p = pipes.get(i);
    p.update();
    if (p.hits(b)) // If the bird collides with a pipe
    {
      p.show(true);
      safe = false;
    }
    else // Otherwise the bird passes safely
    {
      p.show(false);
    }

    if (p.x < -p.w)
    {
      pipes.remove(i);
    }
  }

  if(safe) // If there is no collision
  {
    score++; // Increment score by -1
  } 
  else // Otherwise in case of a collision
  {
    score -= 50; // Decrement score by a penalty of 50 (Note it is a good habit to declare the penalty has global variable)
  }

  fill(100, 0, 0); // Color of the text for displaying our score (Here:Bluishh)
  textSize(60); // Size of the text for displaying our score
  text(score, width/2, 50); // Display our score
  score = constrain(score, 0, score);
}
