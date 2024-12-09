#include <genesis.h>
#include <resources.h>

//User Input, this will change what track is playing
void myJoyHandler(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1)
    {
        if(changed & state & BUTTON_START)
        {
            //stuff happens when you press start
        }  
    }
}

//main program goes here
int main(u16 hard)
{
    int splashResult = splashScreen();
    JOY_init();
    JOY_setEventHandler(&myJoyHandler);

    //this stuff loads and plays music
    //XGM_setLoopNumber(-1);
    //XGM_startPlay(&track1);
    //current_track=1;

    //this loads and displays a picture (320x244)
    //PAL_setPalette(PAL0, meow.palette->data, DMA);
    //VDP_drawImageEx(BG_B, &meow, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USER_INDEX), 0, 0, FALSE, TRUE);
    
    //writes text to the screen
    VDP_drawText("HAHA GET TIM FOLLIN'D!!!!", 10,22);
    while(1)
    {
        
        //stuff goes here :3
        //game loop and stuff 
        //updates every frame
        //SPR_update();
        SYS_doVBlankProcess();
    }
    return(0);
}

int splashScreen()
{
    XGM_startPlay(&track1);
    VDP_setScreenWidth320();
    VDP_setScreenHeight224();
    PAL_setPalette(PAL0, meow.palette->data, DMA);
    VDP_drawImageEx(BG_B, &meow, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USER_INDEX), 0, 0, FALSE, TRUE);
    return(0);
}