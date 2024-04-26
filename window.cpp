void window()
{
    GLfloat window_width = 10;
    GLfloat window_height = 15;
    GLfloat window_length = 1;

    glPushMatrix();
    glTranslatef(10, 25, -40); // Letakkan jendela di dinding kiri
    glPushMatrix();
    glScalef(window_width, window_length, window_height);
    cube(0.8, 0.8, 0.8); // Warna jendela
    glPopMatrix();
    glPopMatrix();
}

void room()
{
    // Kode yang ada sebelumnya
    glPushMatrix(); // front wall
    glTranslatef(0, 0, 45);
    glRotatef(270, 1, 0, 0);

    // Tambahkan jendela di dinding kiri
    window();

    // Kode yang ada setelahnya
}
