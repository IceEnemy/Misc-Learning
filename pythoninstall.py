import pygame
import random

# Initialize pygame
pygame.init()

# Colors
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Create the screen and clock
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Dodge the Blocks!")
clock = pygame.time.Clock()

class Player:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.x = SCREEN_WIDTH / 2 - self.width / 2
        self.y = SCREEN_HEIGHT - self.height - 10
        self.velocity = 5

    def draw(self):
        pygame.draw.rect(screen, BLUE, (self.x, self.y, self.width, self.height))

    def move(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and self.x - self.velocity > 0:
            self.x -= self.velocity
        if keys[pygame.K_RIGHT] and self.x + self.velocity < SCREEN_WIDTH - self.width:
            self.x += self.velocity

class Block:
    def __init__(self, width, height, speed):
        self.width = width
        self.height = height
        self.x = random.randint(0, SCREEN_WIDTH - self.width)
        self.y = 0 - self.height
        self.speed = speed

    def draw(self):
        pygame.draw.rect(screen, RED, (self.x, self.y, self.width, self.height))

    def update(self):
        self.y += self.speed

def game_loop():
    player = Player(50, 30)
    blocks = []
    speed = 5
    score = 0

    running = True
    while running:
        clock.tick(60)
        screen.fill(WHITE)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        player.move()
        player.draw()

        if random.randint(0, 30) == 0:
            blocks.append(Block(random.randint(50, 100), random.randint(10, 30), speed))

        for block in blocks[:]:
            block.update()
            block.draw()
            if block.y > SCREEN_HEIGHT:
                blocks.remove(block)
                score += 1
            if block.y < player.y + player.height and block.y + block.height > player.y and block.x + block.width > player.x and block.x < player.x + player.width:
                running = False

        if score > 0 and score % 10 == 0:
            speed += 0.5
            score += 1

        pygame.display.flip()

    pygame.quit()
    quit()

game_loop()