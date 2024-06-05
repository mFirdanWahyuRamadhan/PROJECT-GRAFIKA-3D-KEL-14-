
void door()
{
    glPushMatrix(); // door_lock

    glTranslatef(44,2,13);
    glRotatef(90,0,1,0);
    glTranslatef(-0.6,5,4.5);
    glScalef(0.40,1.5, 0.5/5.5);
    glTranslatef(-1,-1,-1);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();  //door
    glTranslatef(49,6,20);
    glRotatef(90,0,1,0);
    glScalef(8,15,.5);
    glTranslatef(-1,-1,-1);
    cube(0,0,1);
    glPopMatrix();

}
