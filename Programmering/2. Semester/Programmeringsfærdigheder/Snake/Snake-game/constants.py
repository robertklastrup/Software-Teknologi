# constants.py – Shared settings for the Snake game

CELL_SIZE = 24
COLS = 25
ROWS = 25

SCREEN_WIDTH = COLS * CELL_SIZE
SCREEN_HEIGHT = ROWS * CELL_SIZE + 50  # +50 for scoreboard on top

FPS = 10  # Snake speed (frames per second)

# Colors
BLACK       = (0,   0,   0)
WHITE       = (255, 255, 255)
GREEN       = (60,  200, 60)
DARK_GREEN  = (30,  140, 30)
RED         = (220, 50,  50)
GRAY        = (40,  40,  40)
DARK_GRAY   = (20,  20,  20)
LIGHT_GRAY  = (80,  80,  80)
PORTAL_A    = (80,  80,  255)   # Blue portal
PORTAL_B    = (255, 120, 30)    # Orange portal
SCORE_COLOR = (200, 200, 200)

# Directions
UP    = (0, -1)
DOWN  = (0,  1)
LEFT  = (-1, 0)
RIGHT = (1,  0)
