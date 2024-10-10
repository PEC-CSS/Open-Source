# Classic Pong Game

This is a classic Pong game implemented in Python using the Turtle module. The game features two paddles controlled by players, a ball that bounces off the paddles and walls, and a scoring system. The first player to score 5 points wins the game.

## Features

- **Two-player game**: Control the left paddle with 'W' and 'S' keys, and the right paddle with the 'Up' and 'Down' arrow keys.
- **Ball mechanics**: The ball bounces off the paddles and the walls, changing direction accordingly.
- **Score tracking**: Each time a player misses the ball, the opposing player scores a point.
- **Winning condition**: The game ends when a player scores 5 points.

## Getting Started

### Prerequisites

- Python 3.x installed on your machine.

### Installation

1. Clone the repository to your local machine.
   ```bash
   git clone https://github.com/your-username/classic-pong-game.git
   ```
2. Navigate to the project directory.
   ```bash
   cd classic-pong-game
   ```

### Running the Game

To run the game, execute the following command in your terminal:

```bash
python main.py
```

## Code Overview

### `main.py`

This is the main script that initializes the game screen, creates the game objects (paddles, ball, scoreboard), and contains the game loop.

### `paddle.py`

This module defines the `Paddle` class, which handles paddle creation, movement, and collision detection.

### `ball.py`

This module defines the `Ball` class, which manages the ball's movement and bouncing mechanics.

### `scoreboard.py`

This module defines the `Scoreboard` class, which keeps track of the scores and displays them on the screen.

## How to Play

1. Run the game using the instructions above.
2. Use the following keys to control the paddles:
   - **Left Paddle**: 'W' to move up, 'S' to move down.
   - **Right Paddle**: 'Up Arrow' to move up, 'Down Arrow' to move down.
3. The ball will start moving automatically. Try to hit the ball with your paddle to prevent the opponent from scoring.
4. The first player to score 5 points wins the game.

## Acknowledgements

- This game was created using the [Turtle Graphics module](https://docs.python.org/3/library/turtle.html) in Python.

---
