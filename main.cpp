#include "TXLib.h"
#include "classes.h"
#include "physics.cpp"
#include "rendering.cpp"

int main ()
{
    txCreateWindow (WIDTH, HEIGHT);
    txTextCursor (false);

    Object objArray[] =
    {Object (Vector (0, 0, 350, 300), Vector (0, 0, 0, 0), 50, 1000, false, "Sun"  ),
     Object (Vector (0, 0, 350, 200), Vector (0, 0, 6, 0), 10,   10, false, "Earth"),
     Object (Vector (0, 0,   0,   0), Vector (0, 0, 0, 0),  0,    0, false,  "STOP")};

    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin ();
        txSetFillColor (TX_BLACK);
        txClear ();

        if (GetAsyncKeyState (VK_SPACE)) calculateEverything (objArray);

        renderEverything (objArray);

        txEnd ();
        txSleep (1000/3000);

    }


}

