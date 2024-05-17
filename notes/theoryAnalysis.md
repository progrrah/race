

1. Регистрируе функции обработки "нормальных" и "специальных" нажатий клавиатуры: glutKeyboardFunc GLUT и glutSpecialFunc. Вызов этих функции может быть выполнен в любом месте, что означает, что мы можем изменить **функции обработки клавиатуры для обработки событий в любое время.**
2. initialise a normal render station
    ```cpp
    void renderScene(void) {
	// очистить буфер цвета и глубины.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// обнулить трансформацию
	glLoadIdentity();
	// установить камеру
	gluLookAt(	0.0f, 0.0f, 10.0f,
			0.0f, 0.0f,  0.0f,
			0.0f, 1.0f,  0.0f);
        //поворот на заданную величину
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
 
        // установить цвет модели
	glColor3f(red,green,blue);
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-2.0f, 0.0f);
		glVertex3f( 0.0f, 2.0f, 0.0);
		glVertex3f( 2.0f,-2.0f, 0.0);
	glEnd();
	angle+=0.1f;
 
	glutSwapBuffers();
    }
    ```
3. Иногда требуется знать, какая клавиша модификатор, т.е. CTRL, ALT или SHIFT нажата. GLUT предоставляет функцию, которая обнаруживает нажатие данных клавиш. Эта функция должна вызываться только внутри обработки процессов клавиатуры или мыши. Синтаксис для этой функции:
int glutGetModifiers(void);
4. example
    ```cpp
   void processSpecialKeys(int key, int x, int y) {
	int mod;
	switch(key) {
		case GLUT_KEY_F1 :
		   mod = glutGetModifiers();
		   if (mod == (GLUT_ACTIVE_CTRL|GLUT_ACTIVE_ALT)) {
		   	red = 1.0; green = 0.0; blue = 0.0;
		   }
		   break;
		case GLUT_KEY_F2 :
		   red = 0.0;
		   green = 1.0;
		   blue = 0.0; break;
		case GLUT_KEY_F3 :
		   red = 0.0;
		   green = 0.0;
		   blue = 1.0; break;
	    }   
    }
    ```
5. understanding this function
    ```cpp
    void changeSize(int w, int h) {
	// предотвращение деления на ноль
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);
    }
    ```
5. 
 

