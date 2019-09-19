#include<stdio.h>
	#include<GLUT/glut.h>
	#include<math.h>
	#include<stdlib.h>

	int x1,yr,r;

	void Mid_Point_Circle()
	{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+3;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+5;
		}
		glBegin(GL_POINTS);
		glVertex2d(x+x1,y+yr);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(-x+x1,y+yr);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(x+x1,-y+yr);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(-x+x1,-y+yr);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(y+yr,x+x1);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(-y+yr,x+x1);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(y+yr,-x+x1);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2d(-y+yr,-x+x1);
		glEnd();
	}
	
	glFlush();
	}

	void init(void)
	{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	}

	int main(int argc, char** argv) {
	printf("Enter the value of x1: ");
	scanf("%d",&x1);
	printf("Enter the value of y1: ");
	scanf("%d",&yr);
	printf("Enter the value of radius of circle: ");
	scanf("%d",&r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Circle Using Mid Point Theorem");
	init();
	glutDisplayFunc(Mid_Point_Circle);
	glutMainLoop();

	return 0;
	}
