
void renderEverything (Object objArray[]);

void renderEverything (Object objArray[])
{
    assert (objArray);

    for (int i = 0; objArray[i].getName () != "STOP"; i++)
    {
        objArray[i].render ();
    }

    assert (objArray);
}




