# apple.py – Feature 2: Food placement, eating, and score

import random
from constants import COLS, ROWS


class Apple:
    def __init__(self, snake_cells, portal_cells):
        self.position = None
        self.spawn(snake_cells, portal_cells)

    # Feature 2 – Spawn random apple:
    # Picks a random square that is NOT occupied by the snake or portals.
    def spawn(self, snake_cells, portal_cells):
        occupied = snake_cells | portal_cells
        available = [
            (x, y)
            for x in range(1, COLS - 1)   # Stay inside the walls
            for y in range(1, ROWS - 1)
            if (x, y) not in occupied
        ]
        if available:
            self.position = random.choice(available)

    # Feature 2 – Eating the apple:
    # Returns True if the snake's head is on the same square as the apple.
    def is_eaten_by(self, snake_head):
        return snake_head == self.position
