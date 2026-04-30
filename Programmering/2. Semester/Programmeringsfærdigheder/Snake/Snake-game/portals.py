# portals.py – Feature 4: Portal data structure, spawning, collision, cooldown

import random
from constants import COLS, ROWS


def _edge_cells():
    """Returns all wall-edge cells (border of the playing field)."""
    cells = set()
    for x in range(COLS):
        cells.add((x, 0))
        cells.add((x, ROWS - 1))
    for y in range(1, ROWS - 1):
        cells.add((0, y))
        cells.add((COLS - 1, y))
    return cells


class Portals:
    def __init__(self, snake_cells, apple_pos):
        # Portal data structure: two positions (A and B)
        self.portal_a = None
        self.portal_b = None
        self._cooldown_cell = None  # Exit cell – used to avoid teleport loops
        self.spawn(snake_cells, apple_pos)

    # Feature 4 – Spawn portals:
    # Two portals appear randomly on the edge of the playing field.
    # They must not spawn on the snake or food.
    def spawn(self, snake_cells, apple_pos):
        occupied = snake_cells | ({apple_pos} if apple_pos else set())
        edge = list(_edge_cells() - occupied)
        if len(edge) < 2:
            return
        random.shuffle(edge)
        self.portal_a = edge[0]
        self.portal_b = edge[1]
        self._cooldown_cell = None  # Reset cooldown on new portals

    def get_cells(self):
        """Returns the set of cells occupied by portals (used by other modules)."""
        cells = set()
        if self.portal_a:
            cells.add(self.portal_a)
        if self.portal_b:
            cells.add(self.portal_b)
        return cells

    # Feature 4 – Detect portal collision:
    # Returns the exit position if the snake's head enters a portal,
    # or None if no portal is entered.
    # Includes cooldown/exit-offset logic to avoid teleport loops (GAI suggestion).
    def check_teleport(self, snake_head, direction):
        if snake_head == self._cooldown_cell:
            # Snake is still on the exit cell – don't teleport again
            return None

        exit_pos = None
        if snake_head == self.portal_a:
            exit_pos = self.portal_b
        elif snake_head == self.portal_b:
            exit_pos = self.portal_a

        if exit_pos is not None:
            # Move the snake one step beyond the exit portal in its travel direction
            dx, dy = direction
            teleport_to = (exit_pos[0] + dx, exit_pos[1] + dy)
            self._cooldown_cell = teleport_to
            return teleport_to

        # Snake is not on a cooldown cell anymore – clear cooldown
        self._cooldown_cell = None
        return None
