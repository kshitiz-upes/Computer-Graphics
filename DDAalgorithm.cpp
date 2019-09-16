#include<iostream>
#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>
#include<cstdlib>

using namespace std;

int x1,yr,x2,y2;

void DDA(void){
    float step,k,x,y,Xinc,Yinc,m;
    int dx,dy;
    
    // Calculating the change in Dx aand Dy
    dx = x2-x1;
    dy = y2-yr;
    
    // Calculating the step value
    if(abs(dx)>= abs(dy)){
        step = abs(dx);
    }
    else
        step = abs(dy);
    
    //initialising the initial point and plot
    x = x1;
    y = yr;
    
    //checking the slope value
    if(m < 1){
        Xinc = x + 1;
        Yinc = y + (dy/step);
    }
    else{
        Xinc = x + (dx/step);
        Yinc = y + 1;
    }
    
    //ploting the points
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    
    // obtaining the pixel values on the line and plot
    for(k=0;k<=step;k++){
        x = x + Xinc;
        y = y + Yinc;
        
        
        x = round(x);
        y = round(y);
        
        glBegin(GL_POINTS);
        glVertex2d(x,y);
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
    cout<<("Enter the value of x1 : ");
    cin>>x1;
    cout<<("Enter the value of y1 : ");
    cin>>yr;
    cout<<("Enter the value of x2 : ");
    cin>>x2;
    cout<<("Enter the value of y2 : ");
    cin>>y2;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("DDA Line Algo");
    init();
    glutDisplayFunc(DDA);
    glutMainLoop();
    
    return 0;
}


