# snake.py – Feature 1 & 5: Snake movement and keyboard controls

import pygame
from constants import UP, DOWN, LEFT, RIGHT, COLS, ROWS


class Snake:
    def __init__(self):
        # Start in the middle of the board, length 3, moving right
        start_x, start_y = COLS // 2, ROWS // 2
        self.body = [
            (start_x,     start_y),
            (start_x - 1, start_y),
            (start_x - 2, start_y),
        ]
        self.direction = RIGHT
        self.next_direction = RIGHT  # Buffered direction from key press
        self.grew = False            # Flag: did we just eat an apple?

    # Feature 1 – Controls:
    # Takes an arrow key press and converts it into a direction for the snake.
    # The snake can only change direction if it is NOT the opposite direction.
    def controls(self, event):
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP and self.direction != DOWN:
                self.next_direction = UP
            elif event.key == pygame.K_DOWN and self.direction != UP:
                self.next_direction = DOWN
            elif event.key == pygame.K_LEFT and self.direction != RIGHT:
                self.next_direction = LEFT
            elif event.key == pygame.K_RIGHT and self.direction != LEFT:
                self.next_direction = RIGHT

    # Feature 5 – Continuous movement:
    # Moves the snake one step in the current direction every tick.
    # If the snake just ate an apple (grew=True), the tail is not removed.
    def move(self):
        self.direction = self.next_direction
        head_x, head_y = self.body[0]
        dx, dy = self.direction
        new_head = (head_x + dx, head_y + dy)
        self.body.insert(0, new_head)
        if self.grew:
            self.grew = False  # Keep tail – snake grows by 1 square
        else:
            self.body.pop()    # Remove tail – normal movement

    def grow(self):
        """Called when the snake eats an apple. Expands by 1 square."""
        self.grew = True

    def get_head(self):
        return self.body[0]

    def get_occupied_cells(self):
        """Returns all cells the snake occupies (used by other features)."""
        return set(self.body)

    # Feature 3 – Self-collision detection:
    # Returns True if the snake's head hits its own tail.
    def hits_self(self):
        head = self.body[0]
        return head in self.body[1:]
