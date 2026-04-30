# renderer.py – Draws all game elements on screen

import pygame
from constants import (
    CELL_SIZE, COLS, ROWS, SCREEN_WIDTH, SCREEN_HEIGHT,
    BLACK, GRAY, DARK_GRAY, LIGHT_GRAY,
    GREEN, DARK_GREEN, RED, WHITE,
    PORTAL_A, PORTAL_B,
)


def _cell_rect(x, y):
    """Converts grid coords to pixel Rect (offset by 50px for scoreboard)."""
    return pygame.Rect(x * CELL_SIZE, y * CELL_SIZE + 50, CELL_SIZE, CELL_SIZE)


def draw_board(surface):
    """Draws the grid background."""
    surface.fill(BLACK)
    for x in range(COLS):
        for y in range(ROWS):
            rect = _cell_rect(x, y)
            pygame.draw.rect(surface, DARK_GRAY, rect)
            pygame.draw.rect(surface, GRAY, rect, 1)  # Grid line


def draw_walls(surface, portal_cells):
    """
    Feature 3 – Walls:
    Draws wall cells around the border. Portals are shown instead of walls
    on their positions (walls are passable where a portal exists).
    """
    for x in range(COLS):
        for y in [0, ROWS - 1]:
            if (x, y) not in portal_cells:
                pygame.draw.rect(surface, LIGHT_GRAY, _cell_rect(x, y))
    for y in range(1, ROWS - 1):
        for x in [0, COLS - 1]:
            if (x, y) not in portal_cells:
                pygame.draw.rect(surface, LIGHT_GRAY, _cell_rect(x, y))


def draw_portals(surface, portal_a, portal_b):
    """
    Feature 4 – Render portals visually:
    Portal A is drawn in blue, portal B in orange.
    """
    font = pygame.font.SysFont("monospace", 14, bold=True)
    if portal_a:
        rect = _cell_rect(*portal_a)
        pygame.draw.rect(surface, PORTAL_A, rect)
        label = font.render("A", True, WHITE)
        surface.blit(label, (rect.x + 5, rect.y + 4))
    if portal_b:
        rect = _cell_rect(*portal_b)
        pygame.draw.rect(surface, PORTAL_B, rect)
        label = font.render("B", True, WHITE)
        surface.blit(label, (rect.x + 5, rect.y + 4))


def draw_snake(surface, body):
    """Draws the snake. Head is brighter than the body."""
    for i, (x, y) in enumerate(body):
        color = GREEN if i == 0 else DARK_GREEN
        rect = _cell_rect(x, y)
        pygame.draw.rect(surface, color, rect)
        pygame.draw.rect(surface, BLACK, rect, 1)


def draw_apple(surface, position):
    """Draws the apple as a red circle inside its cell."""
    if position:
        rect = _cell_rect(*position)
        center = rect.center
        pygame.draw.circle(surface, RED, center, CELL_SIZE // 2 - 2)


def draw_game_over(surface, score):
    """
    Feature 3 / Feature 6 – Game-over screen:
    Shows score and instructions to restart or quit.
    """
    overlay = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 170))
    surface.blit(overlay, (0, 0))

    font_big = pygame.font.SysFont("monospace", 40, bold=True)
    font_small = pygame.font.SysFont("monospace", 22)

    lines = [
        font_big.render("GAME OVER", True, RED),
        font_small.render(f"Score: {score}", True, WHITE),
        font_small.render("Press R to restart", True, WHITE),
        font_small.render("Press Q to quit", True, LIGHT_GRAY),
    ]
    total_h = sum(l.get_height() + 10 for l in lines)
    y = (SCREEN_HEIGHT - total_h) // 2
    for line in lines:
        x = (SCREEN_WIDTH - line.get_width()) // 2
        surface.blit(line, (x, y))
        y += line.get_height() + 10
