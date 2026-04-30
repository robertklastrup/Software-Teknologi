# scoreboard.py – Feature 2: Scoreboard display

import pygame
from constants import SCREEN_WIDTH, SCORE_COLOR, DARK_GRAY, WHITE, CELL_SIZE


class Scoreboard:
    def __init__(self):
        self.score = 0
        pygame.font.init()
        self.font = pygame.font.SysFont("monospace", 22, bold=True)
        self.title_font = pygame.font.SysFont("monospace", 22, bold=True)

    def add_point(self):
        """Called each time the snake eats an apple."""
        self.score += 1

    def reset(self):
        self.score = 0

    # Feature 2 – Scoreboard:
    # Appears at the top of the screen, starts at 0, counts up on each apple.
    def draw(self, surface):
        # Background bar
        bar_rect = pygame.Rect(0, 0, SCREEN_WIDTH, 50)
        pygame.draw.rect(surface, DARK_GRAY, bar_rect)

        text = self.font.render(f"SCORE: {self.score}", True, SCORE_COLOR)
        surface.blit(text, (14, 13))
