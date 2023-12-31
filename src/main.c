#include <genesis.h>

// Player position
int playerX = 160;
int playerY = 120;

// Player speed
int speed = 2;

// Animation variables
int frame = 0;
int frameCounter = 0;

void updatePlayer()
{
    // Read input
    u16 value = JOY_readJoypad(JOY_1);

    // Move player
    if (value & BUTTON_UP)
    {
        playerY -= speed;
    }
    if (value & BUTTON_DOWN)
    {
        playerY += speed;
    }
    if (value & BUTTON_LEFT)
    {
        playerX -= speed;
    }
    if (value & BUTTON_RIGHT)
    {
        playerX += speed;
    }

    // Update animation
    frameCounter++;
    if (frameCounter == 10)
    {
        frame++;
        if (frame > 2)
        {
            frame = 0;
        }
        frameCounter = 0;
    }
}

void drawPlayer()
{
    // Draw player character "@" without animation
    VDP_drawText("@", playerX, playerY);
}

int main()
{
    // Initialize SGDK
    VDP_init();
    JOY_init();

    // Main loop
    while (1)
    {
        // player debugging for missing sprite
        KDebug_Alert("Player X: %d, Y: %d", playerX, playerY);
        // Update and draw the player
        updatePlayer();
        drawPlayer();

        // Wait for VBlank before flipping the screen
        VDP_waitVSync();
        VDP_showFPS(FALSE);
    }

    return 0;
}
