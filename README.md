        This project focuses on the development of a Brick Breaker game using C++ within a graphical programming environment. The primary objective is to apply object-oriented programming (OOP) principles through the creation of distinct classes representing various game elements, including the paddle, ball, and bricks. The game mechanics involve controlling the paddle to bounce the ball, with the goal of breaking all the bricks on the screen while preventing the ball from falling.

Key technical challenges are addressed throughout the development process. These include implementing collision detection algorithms for interactions between the ball, paddle, and bricks, as well as optimizing the visual experience by effectively managing graphical output and user input. The game features dynamic scoring, where players earn points for each brick destroyed, along with clear feedback during gameplay. Additionally, the game states, such as 'Start' and 'Game Over', provide a structured experience for users.

By integrating theoretical knowledge with practical application, this project serves as a valuable exercise in C++ programming, resulting in a fully functional Brick Breaker game that delivers engaging gameplay and reinforces core programming concepts.

**OOPS WITH C++ CONCEPTS INVOLVED IN IMPLEMENTATION**

**Object-Oriented Programming (OOP) concepts involves:**

**1. Classes and Objects:**

The game defines multiple classes:

•	Game Element: A base class representing generic game elements with common properties (position) and a virtual draw () method.
•	Paddle, Ball, and Brick: These classes inherit from game Element and implement specific attributes and behaviors (like drawing themselves and responding to interactions).

**2. Inheritance**:

•	Paddle, Ball, and Brick classes inherit from the game Element class. They can use the set Position() and getX()/getY() methods from GameElement, avoiding code duplication.

•	Each derived class also has its own specific implementations of the draw() method to display its unique representation.

**3. Polymorphism**:

•	The draw() method in the GameElement class is declared as a virtual function, allowing derived classes (Paddle, Ball, Brick) to provide their implementations.
•	When the draw() method is called on an object of type GameElement, the program dynamically determines which draw() method to execute based on the actual object type (e.g., it calls Ball::draw() if the object is of the Ball type).

**4. Encapsulation:**

•	The attributes x and y in the GameElement class are protected, meaning they can only be accessed by derived classes and not from outside the class hierarchy. This encapsulation ensures that only the intended classes can modify the position.
•	The methods setPosition(), getX(), and getY() provide controlled access to these attributes, enabling interaction with the object's data while maintaining data integrity.

**5. Abstraction:**

•	The GameElement class defines a draw() method as a pure virtual function (abstract method), requiring derived classes to implement their version of draw().
•	This abstraction means that the main game logic doesn’t need to know the specifics of how each game element is drawn; it only needs to call draw() on each object, allowing for cleaner and more manageable code.

**NOTE:RUN IN TURBO COMPILER**
