void chair() {
    
    glPushMatrix();
    glTranslatef(0, 5, 0); 
    glScalef(5, 1, 5); 
    cube(0.6, 0.3, 0.1); 
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 10, -2.5); 
    glScalef(5, 10, 1); 
    cube(0.6, 0.3, 0.1); 
    glPopMatrix();

   
    glPushMatrix();
    glTranslatef(-2.5, 2.5, 2.5); 
    glScalef(1, 5, 1); 
    cube(0.3, 0.2, 0.1); 
    glPopMatrix();

 
    glPushMatrix();
    glTranslatef(2.5, 2.5, 2.5); 
    glScalef(1, 5, 1); 
    cube(0.3, 0.2, 0.1); 
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(-2.5, 2.5, -2.5); 
    glScalef(1, 5, 1); 
    cube(0.3, 0.2, 0.1);
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(2.5, 2.5, -2.5); 
    glScalef(1, 5, 1);
    cube(0.3, 0.2, 0.1);
    glPopMatrix();
}
