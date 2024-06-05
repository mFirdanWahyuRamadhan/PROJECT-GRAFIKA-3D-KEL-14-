
void room()
{
    glPushMatrix();//front wall
    glTranslatef(0,0,45);
    glRotatef(270,1,0,0);

    glPushMatrix();//light front side
    glTranslatef(3,2,36);
    glRotatef(90,1,0,0);
    glScalef(12,.8,0.8);
    glTranslatef(-1,-1,-1);
    glPopMatrix();

    glPushMatrix();  //blackboard
    glTranslatef(0,1,18);
    glScalef(30,0.5,8);
    glTranslatef(-1,-1,-1);
    cube(0.000, 0.000, 0.000); //ini adalah papan tulis dengan warna hitam
    glPopMatrix();

//kode yang ada setelahnya
}
