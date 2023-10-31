#include <SD2/SDL.h>
#include <iostream>
#include <vector>

// Constants for the window size and block size
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BLOCK_SIZE = 20;

// Struct to represent memory blocks
struct MemoryBlock
{
    int size;
    bool allocated;
};

// Function to draw a memory block
void drawBlock(SDL_Renderer *renderer, int x, int y, int size, bool allocated)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = size;
    rect.h = BLOCK_SIZE;

    if (allocated)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for allocated
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for free
    }

    SDL_RenderFillRect(renderer, &rect);
}

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Memory Allocation Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::vector<MemoryBlock> memoryBlocks;

    // Initialize memory blocks (sample data)
    memoryBlocks.push_back({50, true});
    memoryBlocks.push_back({30, false});
    memoryBlocks.push_back({20, true});
    memoryBlocks.push_back({40, false});
    memoryBlocks.push_back({60, true});

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw memory blocks
        int x = 0;
        for (const MemoryBlock &block : memoryBlocks)
        {
            drawBlock(renderer, x, SCREEN_HEIGHT / 2 - BLOCK_SIZE / 2, block.size, block.allocated);
            x += block.size;
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
