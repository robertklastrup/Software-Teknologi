# main.py – Main game loop tying all features together

import sys
import pygame

from constants import SCREEN_WIDTH, SCREEN_HEIGHT, FPS, COLS, ROWS, BLACK
from snake import Snake
from apple import Apple
from portals import Portals
from scoreboard import Scoreboard
from renderer import (
    draw_board, draw_walls, draw_snake,
    draw_apple, draw_portals, draw_game_over,
)


def new_game():
    """Creates and returns fresh instances of all game objects."""
    snake = Snake()
    portals = Portals(snake.get_occupied_cells(), None)
    apple = Apple(snake.get_occupied_cells(), portals.get_cells())
    scoreboard = Scoreboard()
    return snake, apple, portals, scoreboard


def is_wall(x, y):
    """Feature 3 – Wall collision: returns True if position is a wall cell."""
    return x <= 0 or x >= COLS - 1 or y <= 0 or y >= ROWS - 1


def run():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Snake – with Portals")
    clock = pygame.time.Clock()

    snake, apple, portals, scoreboard = new_game()
    game_over = False

    while True:
        # ── Event handling ──────────────────────────────────────────────────
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            if game_over:
                # Feature 6 – Restart game
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_r:
                        snake, apple, portals, scoreboard = new_game()
                        game_over = False
                    elif event.key == pygame.K_q:
                        pygame.quit()
                        sys.exit()
            else:
                # Feature 1 – Controls: pass events to the snake
                snake.controls(event)

        if not game_over:
            # ── Update ──────────────────────────────────────────────────────

            # Feature 5 – Continuous snake movement
            snake.move()
            head = snake.get_head()

            # Feature 4 – Detect portal collision & teleport
            teleport_to = portals.check_teleport(head, snake.direction)
            if teleport_to is not None:
                # Move snake head to exit position
                snake.body[0] = teleport_to
                head = teleport_to
                # Spawn new pair of portals (old ones disappear per spec)
                portals.spawn(snake.get_occupied_cells(), apple.position)

            # Feature 3 – Wall collision (walls are impassable unless portal)
            hx, hy = head
            if is_wall(hx, hy) and head not in portals.get_cells():
                game_over = True

            # Feature 3 – Self-collision detection
            if snake.hits_self():
                game_over = True

            if not game_over:
                # Feature 2 – Eating the apple
                if apple.is_eaten_by(head):
                    snake.grow()
                    scoreboard.add_point()
                    # Spawn a new apple (not on snake or portals)
                    apple.spawn(snake.get_occupied_cells(), portals.get_cells())

        # ── Render ──────────────────────────────────────────────────────────
        draw_board(screen)
        draw_walls(screen, portals.get_cells())
        draw_portals(screen, portals.portal_a, portals.portal_b)
        draw_apple(screen, apple.position)
        draw_snake(screen, snake.body)
        scoreboard.draw(screen)

        if game_over:
            draw_game_over(screen, scoreboard.score)

        pygame.display.flip()
        clock.tick(FPS)


if __name__ == "__main__":
    run()
