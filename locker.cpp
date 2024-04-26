
void almari()
{
    glPushMatrix();

    GLfloat almari_height =15, almari_width= 8, almari_length= 5;


    glPushMatrix();  //main_box
    glScalef(almari_width,almari_height, almari_length);
    glTranslatef(-1,-1,-1);
    cube(1,0,0);
    glPopMatrix();

    glPushMatrix(); // almari_line
    glTranslatef(0.4,0,4.1);
    glScalef(almari_width/45,(almari_height-.5), almari_length/5.5);
    glTranslatef(-1,-1,-1);
    cube(1.000, 0.000, 1.000);
    glPopMatrix();

    glPushMatrix(); // almari_handel_right
    glTranslatef(1.5,5,4.5);
    glScalef(almari_width/25,almari_height/15, almari_length/5.5);
    glTranslatef(-1,-1,-1);
    cube(0.957, 0.643, 0.376);
    glPopMatrix();

    glPushMatrix(); // almari_handel_left
    glTranslatef(-0.6,5,4.5);
    glScalef(almari_width/25,almari_height/15, almari_length/5.5);
    glTranslatef(-1,-1,-1);
    cube(0.957, 0.643, 0.376);
    glPopMatrix();

    glPopMatrix();

}