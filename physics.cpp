
void calculateEverything (Object objArray[]);

void calculateEverything (Object objArray[])
{
    assert (objArray);

    for (int i = 0; objArray[i].getName () != "STOP"; i++)
    {
        objArray[i].move ();

        for (int j = 0; objArray[j].getName () != "STOP"; j++)
        {
            if (j != i)
            {
                objArray[i].gravitateTo (objArray[j]);
            }
        }

    }

    assert (objArray);
}
