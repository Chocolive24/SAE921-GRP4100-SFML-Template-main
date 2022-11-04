# SAE921-GRP4100-SFML-Template-main  

This is a set of programming exercises from Sae Institute Geneva made with SFML.  
The exercises whose names begin with "00" are basic templates to help design the others.  
Exercises whose names begin with "0" and then continuous numbers are graded exercises. They are called Formative Exercices.    
Exercises with names beginning with "E00" are ungraded exercises.  

## 01-Formative Make Paintings.  

This is a SFML program which draw paintings with the mouse clicks.  

### Basics element requiered in the program :  

* Using SFML Frameworks, figure out an algorithm to make this picture from Vera Molnar.  
* Each click on a mouse button redraw a new picture following the same principles.  
* https://canvas.sae.edu/courses/13839/files/851583/preview  
* https://canvas.sae.edu/courses/13839/files/851582/preview  

### Learning Objectives:  

* Create algorithms for specific tasks.  

## 02-Formative Arkanoid.  

This is a breaker game inspired by arkanoid.  

### Basics element requiered in the program :  

* Using SFML Frameworks, create a breaker game.  
* Controls :  
    * Left/Right arrow keys move the bar  
    * Space key to throw the ball  
* Subparts :  
    * create a Player class
        * MoveLeft, MoveRight methods to move the bar (Bar subclass)
        * Launch method to launch the ball
    * create a Ball class
        * Vector2i Direction property
        * Move method to move automatically according to the direction
        * Bounce method (Vector wallNormal) to make the ball bounce (Which geometrical notions intervene?) and triggers a sound 
        * IsColliding(sf::Bounds bounds) bool method using the Contains method to determine if the ball collided
    * create a class Brick
        * Break() method 
    * create a GameController class to list all the Bricks, the ball, the bar
        * CheckInput functions to test the necessary keys
        * Update functions to update the ball position, test for collisions with the bar and bricks
        * Draw functions
        * init method to instantiate the Player, Ball, and Brick elements
        * Main SFML loop

### Learning Objectives:  

* Create algorithms for specific tasks.  
