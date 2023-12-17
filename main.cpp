#include "raylib.h" // external library not part of c++ std library 

int main(){

    // float root_beer = 1.99; // to avoid variable getting a start off with garbage value do declaring and initializing on same line  
    // // brazed initialization
    // //double cheese_burger = 5.99;
    // double cheese_burger{5.99};
    // //bool ShouldHaveLunch = true;
    // bool ShouldHaveLunch{};

    // visible screen dimensionsa
    int width{500};
    int height{500};
    InitWindow(width, height, "First ;)");

    // circle coordinated
    int circle_x{175};
    int circle_y{250};
    int circle_radius{25};

    // circle edge collisions
    
    int r_circle_edge = circle_x + circle_radius;
    int l_circle_edge = circle_x - circle_radius;
    int u_circle_edge = circle_y - circle_radius;
    int b_circle_edge = circle_y + circle_radius;


    // rectangle/ axe edge coordinates
    int pos_x{175};
    int pos_y{0};
    int pos_len{50};
    //int rec_wt{50};
    //int rec_ht{50};

    // axe/ rect collisions (collision detection includes checking if edges of box collide)

    int r_pos_x = pos_x + pos_len;
    int l_pos_x = pos_x;
    int u_pos_y = pos_y;
    int b_pos_y = pos_y + pos_len;


    //kinda speed with which axe moves
    int direction{5};

    bool collision_with_axe = (b_pos_y >= u_circle_edge) && 
                              (u_pos_y <= b_circle_edge) &&
                              (r_pos_x >= l_circle_edge) && 
                              (l_pos_x <= r_circle_edge);

    SetTargetFPS(60);

    while(WindowShouldClose() == false) // this entire expression is true, WindowShouldClose returns true if we press esc or close, WindowShouldClose != true, keep the window open if WindowShouldClose returns false
    {
        BeginDrawing(); // setup and tear down of canvas, double buffering is used, frame buffer
        ClearBackground(BLUE); //used to clear the canvas to specific color, use to avoid flickering(switching b/w white-black), imp to clearBG

        if(collision_with_axe){
            DrawText("GameOver", 100, 50, 25, PINK);
        }

        else{
            // game logic begins

            // update edges

            r_circle_edge = circle_x + circle_radius;
            l_circle_edge = circle_x - circle_radius;
            u_circle_edge = circle_y - circle_radius;
            b_circle_edge = circle_y + circle_radius;

            r_pos_x = pos_x + pos_len;
            l_pos_x = pos_x;
            u_pos_y = pos_y;
            b_pos_y = pos_y + pos_len;

            // update collison with axe

            collision_with_axe = (b_pos_y >= u_circle_edge) && 
                              (u_pos_y <= b_circle_edge) &&
                              (r_pos_x >= l_circle_edge) && 
                              (l_pos_x <= r_circle_edge);

        DrawCircle(circle_x, circle_y, circle_radius, RED);
        DrawRectangle(pos_x, pos_y, pos_len, pos_len, BLACK);

        pos_y += direction;

        if(pos_y > height || pos_y < 0){
            direction = -direction; // flip flopping between negative and positive number this enables the up and down movement
        }

        // for moving circle left and right
        if(IsKeyDown(KEY_D) && circle_x < width) // coordinate of right side of window
        {
            circle_x = circle_x + 5;
        }

        if(IsKeyDown(KEY_A) && circle_x > 0) // coordinate of left side of window
        {
            circle_x = circle_x - 5;
        }

        // game logic ends
        }
        EndDrawing();    
    }
}
