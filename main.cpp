

#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>

#include <SDL2/SDL.h>


#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr int WIDTH = 800, HEIGHT = 600;

int main(int, char**)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    auto win = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(
                        "Окно нашего графического приложения",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        WIDTH, HEIGHT,
                        SDL_WINDOW_SHOWN),
            SDL_DestroyWindow);
    if (win == nullptr) {
        std::cerr << "При создании окна произошла ошибка: " <<
                SDL_GetError() << std::endl;
        return 1;
    }

    auto ren = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(win.get(), -1,
                    SDL_RENDERER_ACCELERATED |
                    SDL_RENDERER_PRESENTVSYNC),
            SDL_DestroyRenderer);
    if (ren == nullptr) {
        std::cerr << "При создании renderer-а произошла ошибка: " <<
                SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;

    while(1){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return 0;
        }

        SDL_SetRenderDrawColor(ren.get(), 255, 255, 255, 255);
        SDL_RenderClear(ren.get());

        SDL_SetRenderDrawColor(ren.get(), 0, 0, 0, 0);
        for(int i=-WIDTH/2; i<WIDTH/2;i++)
        {
            SDL_RenderDrawPoint(ren.get(), i+WIDTH/2, (100*sin(i*(6.284/360.0)*3.14)/(i*(6.284/360.0))*3.14)+HEIGHT/2);
        }


        SDL_RenderPresent(ren.get());
    }


    return 0;
}
