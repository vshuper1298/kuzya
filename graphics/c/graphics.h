#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#if !defined(__COLORS)
#define __COLORS
enum COLORS 
{
    BLACK,          /*dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /*light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

enum PATERN
{
  EMPTY_FILL,      	///  0   Background color
  SOLID_FILL,      	///  1   Solid fill
  LINE_FILL,       	///  2   ---
  LTSLASH_FILL,    	///  3   ///
  SLASH_FILL,      	///  4   ///, thick lines
  BKSLASH_FILL,    	///  5   \\\, thick lines
  LTBKSLASH_FILL,  	///  6   \\\/
  HATCH_FILL,      	///  7   Light hatch
  XHATCH_FILL,     	///  8   Heavy crosshatch
  INTERLEAVE_FILL, 	///  9   Interleaving lines
  WIDE_DOT_FILL,   	/// 10   Widely spaced dots
  CLOSE_DOT_FILL,  	/// 11   Closely spaced dots
  USER_FILL       	/// 12   User-defined fill pattern
};

enum DIRECTION
{
	HORIZ_DIR	,	/*left to right */
	VERT_DIR		/*bottom to top*/  
};

enum LINESTYLE
{
	SOLID_LINE,
	DOTTED_LINE,
	CENTER_LINE,
	DASHED_LINE,
	USERBIT_LINE
};

namespace KGNS
{
  struct RGB
  {
    int r;
    int g;
    int b;
  };

  FILE *kuzyaGraphFile;
  char  command[100];
  char text[100];
 
  COLORS curentColor = WHITE;
  int isCOLOR = 1;        ///0 colors 1 int 2 RGB for color
  int curentIntColor = 0;
  RGB currentRGBcolor;
  
  COLORS curentFillColor  = BLACK;
  int isFillCOLOR = 1;        ///0 colors 1 int 2 RGB for fill color
  int curentFillIntColor = 0;
  RGB currentFillRGBcolor;
  void setPreviouslySetedColor(void);
}

int width =  640;
int height = 480;

///*******************Declaration of the functions***************
void arc(int x, int y, int stAngel, int endAngle, int radius);
void arc(int x, int y, int stAngel, int endAngle, int radius, COLORS color);
void arc(int x, int y, int stAngel, int endAngle, int radius, int color);
void bar(int x, int y, int x1, int y1);
void bar(int x, int y, int x1, int y1, COLORS color);
void bar(int x, int y, int x1, int y1, int color);
void bar3d(int x, int y, int x1, int y1, int z, bool top);
void circle(int x, int y, int radius);
void circle(int x, int y, int radius, COLORS color);
void circle(int x, int y, int radius, int color);
void cleardevice();
void close();
void closegraph();
void drawfunc(int numOfPoints, double *arrayX, double *arrayY);
void drawpoly(int numOfPoints, int* array);
void drawpoly(int numOfPoints, int* arrayX, int* arrayY);
void drawpoly(int numOfPoints, int** arrayXY);
void ellipse(int x, int y, int rWidth, int rHeight);
void ellipse(int x, int y, int rWidth, int rHeight, COLORS color);
void ellipse(int x, int y, int rWidth, int rHeight, int color);
void fillellipse(int x, int y, int rWidth, int rHeight);
void fillellipse(int x, int y, int rWidth, int rHeight, int color);
void fillellipse(int x, int y, int rWidth, int rHeight, COLORS color);
int getmaxx();
int getmaxy();
void image(int x, int y, char* path);
void initgraph();
void initgraph(int drv, int drm, char *text);
void initgraph(int setWidth, int setHeight);
void line(int x, int y, int x1, int color);
void line(int x, int y, int x1, COLORS color);
void line(int x, int y, int x1, int color);
void lineto(int x, int y);
void lineto(int x, int y, int color);
void lineto(int x, int y, COLORS color);
void moveto(int x, int y);
void outtext(const char* text);
void outtext(const char* text, int color);
void outtext(const char* text, COLORS color);
void outtextxy(int x, int y, const char* text);
void outtextxy(int x, int y, const char* text, int color);
void outtextxy(int x, int y, const char* text, COLORS color);
void pieslice(int x, int y, int stAngle, int endAngle, int radius);
void pieslice(int x, int y, int stAngle, int endAngle, int radius, int color);
void pieslice(int x, int y, int stAngle, int endAngle, int radius, COLORS color);
void putpixel(int x, int y);
void putpixel(int x, int y, COLORS color);
void putpixel(int x, int y, int color);
void rectangle(int x, int y,int x1,int  y1);
void rectangle(int x, int y,int x1,int y1, COLORS color);
void rectangle(int x, int y,int x1,int y1, int color);
void save(const char* path);
void setbkcolor(COLORS color);
void setbkcolor(int color);
void setbkcolor(int red, int green, int blue);
void setcolor(COLORS color);
void setcolor(int color);
void setcolor(int red, int green, int blue);
void setfillcolor(int color);
void setfillcolor(COLORS color);
void setfillcolor(int red, int green, int blue);
void setfillstyle(PATERN patern, COLORS color);
void setfillstyle(int patern, COLORS color);
void setfillstyle(PATERN patern, int color);
void setfillstyle(int patern, int color);
void setlinestyle(int linestyle, unsigned upattern, int thickness);
void setlinestyle(LINESTYLE linestyle, unsigned upattern, int thickness);
void settextstyle(char* font, int direction, int size);
///****************-Turtle graphics functions-******************************************
void hideturtle(void);
void showturtle(void);
void turtlepaint(void);
void turtlepaintnot(void);
void goforward(int step);
void goback(int step);
void eright(int angle);
void left(int angle);
//*********************************************************************
///***************arc********************************
void arc(int x, int y, int stAngel, int endAngle, int radius)
{
	sprintf(KGNS::command, "arc(%i,%i,%i,%i,%i);\n",x , y, stAngel, endAngle, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
///***************arc__color********************************
void arc(int x, int y, int stAngel, int endAngle, int radius, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "arc(%i,%i,%i,%i,%i);\n",x , y, stAngel, endAngle, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	KGNS::setPreviouslySetedColor();
}
///***************arc__number********************************
void arc(int x, int y, int stAngel, int endAngle, int radius, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "arc(%i,%i,%i,%i,%i);\n",x , y, stAngel, endAngle, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	KGNS::setPreviouslySetedColor();
}
///*****************Draws bar filled in with th help of fillcolor*****************
void bar(int x, int y, int x1, int y1)
{
 	sprintf(KGNS::command, "bar(%i,%i,%i,%i);\n",x , y, x1, y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
void bar(int x, int y, int x1, int y1,COLORS color)
{
 	sprintf(KGNS::command, "setfillcolor(%i);\n", color);  /// color to fill bar
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
  
	sprintf(KGNS::command, "bar(%i,%i,%i,%i);\n",x , y, x1, y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
void bar(int x, int y, int x1, int y1, int color)
 {
	sprintf(KGNS::command, "setfillcolor(%i);\n", color);  /// color to fill bar
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
  
	sprintf(KGNS::command, "bar(%i,%i,%i,%i);\n",x , y, x1, y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
 }
///***************3 demention rectangle**********************************
void bar3d(int x, int y, int x1, int y1, int z, bool top)
{
	char* topStr;
	if(top == true)
	{
		bar(x, y, x1, y1);
	}
	else
	{
		rectangle(x, y, x1, y1);
	}
	sprintf(KGNS::command, "bar3d(%i,%i,%i,%i,%i);\n",x , y, x1, y1, z);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///**********circle**************************************************** 
void circle(int x, int y, int radius)
{
	sprintf(KGNS::command, "circle(%i,%i,%i);\n",x , y, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);		
}
///**********circle___color**************************************************** 
void circle(int x, int y, int radius, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "circle(%i,%i,%i);\n",x , y, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);		
	
	KGNS::setPreviouslySetedColor();
}
///**********circle___number**************************************************** 
void circle(int x, int y, int radius, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "circle(%i,%i,%i);\n",x , y, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);		
	
	KGNS::setPreviouslySetedColor();
}
///**********clearDevise********************************************
void cleardevice()
{
	sprintf(KGNS::command, "cleardevice();\n");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///**************this function close kuzyagraph window**************
void close()
{
  	sprintf(KGNS::command, "close();\n");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///*********closeGraph***********************
void closegraph()
{
	sprintf(KGNS::command, "closegraph();");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	fflush(KGNS::kuzyaGraphFile);
	pclose(KGNS::kuzyaGraphFile);
}
///********drawFunction****************************
void drawfunc(int numOfPoints,double *arrayX, double *arrayY )
{
	char *command = new char [numOfPoints * sizeof(double) * 2  + sizeof(int) + numOfPoints]; 
	char newText[20];
	
	sprintf(newText, "drawfunc(%i,", numOfPoints);
	strcat(command, newText);
	
	for (int i = 0; i <= numOfPoints - 2; ++i)
	{
		sprintf(newText, "%f,", arrayX[i]);
		strcat(command, newText);
		sprintf(newText, "%f,", arrayY[i]);
		strcat(command, newText);
	}
	
	sprintf(newText, "%f,", arrayX[numOfPoints - 1]);
	strcat(command, newText);
	sprintf(newText, "%f", arrayY[numOfPoints - 1]);
	strcat(command, newText);
	strcat(command, ");\n");
	fprintf(KGNS::kuzyaGraphFile, command);	
	
	//delete [] command;
}
///********draw polygon were 0 element is x and 1 is y and soon**********************
void drawpoly(int numOfPoints,int* array)
{
	char *command = new char [numOfPoints * 2 * sizeof(double) * 2 + 12 + sizeof(int)]; 
	char newText[20];
	
	sprintf(newText, "drawpoly(%i,", numOfPoints * 2);
	strcat(command, newText);
	
	for (int i = 0; i <= (numOfPoints * 2) - 3; i += 2)
	{
		sprintf(newText, "%i,", array[i]);
		strcat(command, newText);
		sprintf(newText, "%i,", array[i + 1]);
		strcat(command, newText);
	}
	sprintf(newText, "%i,", array[(numOfPoints * 2) - 2]);
	strcat(command, newText);
	sprintf(newText, "%i", array[(numOfPoints * 2) - 1]);
	strcat(command, newText);
	strcat(command, ");\n");
	fprintf(KGNS::kuzyaGraphFile, command);	
	
	//delete [] command;
}

//********draw polygon were 0 element is x and 1 is y and so on**********************
void drawpoly(int numOfPoints,int *arrayX,int* arrayY)
{
	char *command = new char [numOfPoints * 2 * sizeof(double) * 2 + 12 + sizeof(int)]; 
	char newText[20];
	
	sprintf(newText, "drawpoly(%i,", (numOfPoints * 2));
	strcat(command, newText);
	
	for (int i = 0; i <= numOfPoints - 2; ++i)
	{
		sprintf(newText, "%i,", arrayX[i]);
		strcat(command, newText);
		sprintf(newText, "%i,", arrayY[i]);
		strcat(command, newText);
	}
	sprintf(newText, "%i,", arrayX[numOfPoints - 1]);
	strcat(command, newText);
	sprintf(newText, "%i", arrayY[numOfPoints - 1]);
	strcat(command, newText);
	strcat(command, ");\n");
	fprintf(KGNS::kuzyaGraphFile, command);	
	
	//delete [] command;
}

//********draw polygon were 0 element is x and 1 is y and so on**********************
void drawpoly(int numOfPoints, int (*arrayXY)[2])
{
	char *command = new char [numOfPoints * 2 * sizeof(double) * 2 + 12 + sizeof(int)]; 
	char newText[20];
	
	sprintf(newText, "drawpoly(%i,", (numOfPoints * 2));
	strcat(command, newText);
	
	for (int i = 0; i <= numOfPoints - 2; ++i)
	{
		sprintf(newText, "%i,", arrayXY[i][0]);
		strcat(command, newText);
		sprintf(newText, "%i,", arrayXY[i][1]);
		strcat(command, newText);
	}
	sprintf(newText, "%i,", arrayXY[numOfPoints - 1][0]);
	strcat(command, newText);
	sprintf(newText, "%i", arrayXY[numOfPoints - 1][1]);
	strcat(command, newText);
	strcat(command, ");\n");
	fprintf(KGNS::kuzyaGraphFile, command);	
	
	//delete [] command;
}

///******ellipse************************************
void ellipse(int x, int y, int rWidth, int rHeight)
{
	sprintf(KGNS::command, "ellipse(%i,%i,%i,%i);\n",x , y, rWidth, rHeight);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///******ellipse  number************************************
void ellipse(int x, int y, int rWidth, int rHeight, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);  /// color to fill ellipse
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	sprintf(KGNS::command, "ellipse(%i,%i,%i,%i);\n",x , y, rWidth, rHeight);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	KGNS::setPreviouslySetedColor();
}
///******ellipse  color************************************
void ellipse(int x, int y, int rWidth, int rHeight, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);  /// color to fill ellipse
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	sprintf(KGNS::command, "ellipse(%i,%i,%i,%i);\n",x , y, rWidth, rHeight);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	KGNS::setPreviouslySetedColor();
}
///******fillEllipse  with curent fillcolor**********************************
void fillellipse(int x, int y, int rWidth, int rHeight)
{
  	sprintf(KGNS::command, "fillellipse(%i,%i,%i,%i);\n",x , y, rWidth, rHeight);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///******fillEllipse  number************************************
void fillellipse(int x, int y, int rWidth, int rHeight, int color)
{
	sprintf(KGNS::command, "setfillcolor(%i);\n", color);  /// color to fill ellipse
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	sprintf(KGNS::command, "fillellipse(%i,%i,%i,%i);\n",x , y, rWidth, rHeight);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	KGNS::setPreviouslySetedColor();
}
///******fillEllipse  color************************************
void fillellipse(int x, int y, int rWidth, int rHeight, COLORS color)
{
	sprintf(KGNS::command, "setfillcolor(%i);\n", color);  /// color to fill ellipse
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	sprintf(KGNS::command, "fillellipse(%i,%i,%i,%i);\n",x , y, rWidth, rHeight);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

	KGNS::setPreviouslySetedColor();
}
///*************getMaxX****************************
int getmaxx()
{
	return width;
}
///*************getMaxY****************************
int getmaxy()
{
	return height;
}
///********* draw image ******************************
void image(int x, int y, const char* path)
{
	sprintf(KGNS::command, "image(%i,%i,\"%s\");\n",x , y, path);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///********initGraph*************************
void initgraph()
{
	static char *command= "kuzyagraph";
	KGNS::kuzyaGraphFile = popen(command, "w");
	sprintf(KGNS::command, "initgraph(%i,%i);\n",width, height);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);

}
//********initGraph*************************
void initgraph(int *drv, int *drm, char *text)
{
	initgraph();
}
//*********initGraph******************************
void initgraph(int setWidth, int setHeight)
{
	width = setWidth;
	height = setHeight;
	initgraph();
}
///*******line**************************************
void line(int x, int y, int x1, int y1)
{
	sprintf(KGNS::command, "line(%i,%i,%i,%i);\n",x , y,x1,y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
//**********line***********************************
void line(int x, int y, int x1, int y1, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color); ///color to draw line
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "line(%i,%i,%i,%i);\n",x , y,x1,y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}

//**********line***********************************
void line(int x, int y, int x1, int y1, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);  /// color to draw line
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
  
	sprintf(KGNS::command, "line(%i,%i,%i,%i);\n",x , y,x1,y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///*********lineto*************************************
void lineto(int x, int y)
{
  	sprintf(KGNS::command, "lineto(%i, %i);\n", x, y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///*********lineto with int color*****************************
void lineto(int x, int y, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color); ///color to draw line
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
  	sprintf(KGNS::command, "lineto(%i, %i);\n", x, y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///*********lineto with COLORS color*****************************
void lineto(int x, int y, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color); ///color to draw line
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
  	sprintf(KGNS::command, "lineto(%i, %i);\n", x, y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///*********moveto*************************************
void moveto(int x, int y)
{
  	sprintf(KGNS::command, "moveto(%i,%i);\n",x , y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///********outTextXY***********************************
void outtextxy(int x, int y, const char* text)
{
	sprintf(KGNS::command, "outtextxy(%i,%i,\"%s\");\n",x , y, text);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
///********outTextXY color***********************************
void outtextxy(int x, int y, const char* text, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);     ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "outtextxy(%i,%i,\"%s\");\n",x , y, text);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///********outTextXY number***********************************
void outtextxy(int x, int y, const char* text, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);     ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "outtextxy(%i,%i,\"%s\");\n",x , y, text);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///************outText*****************************************
void outtext(const char* text)
{
	sprintf(KGNS::command, "outtext(\"%s\");\n", text);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
///************outText with COLORS color*****************************************
void outtext(const char* text, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);     ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "outtext(\"%s\");\n", text);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	
	KGNS::setPreviouslySetedColor();
}
///************outText with int color*****************************************
void outtext(const char* text, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);     ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "outtext(\"%s\");\n", text);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	
	KGNS::setPreviouslySetedColor();
}
///********piesLice*********************************
void pieslice(int x, int y, int stAngle, int endAngle, int radius)
{
	sprintf(KGNS::command, "pieslice(%i,%i,%i,%i,%i);\n",x , y, stAngle, endAngle, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);		
}
///********piesLice number*********************************
void pieslice(int x, int y, int stAngle, int endAngle, int radius, int color)
{
  	sprintf(KGNS::command, "setfillcolor(%i);\n", color);  /// color to fill ellipse
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "pieslice(%i,%i,%i,%i,%i);\n",x , y, stAngle, endAngle, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	
	KGNS::setPreviouslySetedColor();
}
///********piesLice color*********************************
void pieslice(int x, int y, int stAngle, int endAngle, int radius, COLORS color)
{
	sprintf(KGNS::command, "setfillcolor(%i);\n", color);  /// color to fill ellipse
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "pieslice(%i,%i,%i,%i,%i);\n",x , y, stAngle, endAngle, radius);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	
	KGNS::setPreviouslySetedColor();	
}
///*******putPixel*********************************
void putpixel(int x, int y)
{	
	sprintf(KGNS::command, "putpixel(%i,%i);\n",x , y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}
//*******putPixel___ With color*********************************
void putpixel(int x, int y, COLORS color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);     ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
  
	sprintf(KGNS::command, "putpixel(%i,%i);\n",x , y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
//********putPixel_with_color_named_by_number******************
void putpixel(int x, int y, int color)
{
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "putpixel(%i,%i);\n",x , y);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///********rectangle***********************************
void rectangle(int x, int y,int x1,int y1)
{	
	sprintf(KGNS::command, "rectangle(%i,%i,%i,%i);\n",x , y, x1, y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
}

//********rectangle with setting color*******************************
void rectangle(int x, int y,int x1,int y1, COLORS color)
{	
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "rectangle(%i,%i,%i,%i);\n",x , y, x1, y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}

//********rectangle with setting int color*******************************
void rectangle(int x, int y,int x1,int y1, int color)
{	
	sprintf(KGNS::command, "setcolor(%i);\n", color);      ///color to draw dot
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	sprintf(KGNS::command, "rectangle(%i,%i,%i,%i);\n",x , y, x1, y1);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
	KGNS::setPreviouslySetedColor();
}
///*******************save image in the given path with given name*****
void save(const char* path)
{
  	sprintf(KGNS::command, "save(\"%s\");\n", path);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
///***********setBGColor___COLORS************************************
void setbkcolor(COLORS color)
{
	sprintf(KGNS::command, "setbkcolor(%i);\n", color);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
//***********setBGColor___NUMBERS************************************
void setbkcolor(int color)
{
	sprintf(KGNS::command, "setbkcolor(%i);\n", color);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
//***********setBGColor___RGB***********************************
void setbkcolor(int red, int green, int blue)
{
	sprintf(KGNS::command, "setbkrgbcolor(%i, %i,%i);\n", red, green, blue);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
///***********setColor___COLORS************************************
void setcolor(COLORS color)
{
	KGNS::curentColor = color;
	sprintf(KGNS::command, "setcolor(%i);\n", color);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	KGNS::isCOLOR = 0;
}
//***********setColor___NUMBERS************************************
void setcolor(int color)
{
	KGNS::curentIntColor = color;
	sprintf(KGNS::command, "setcolor(%i);\n", color);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	KGNS::isCOLOR = 1;
}
//**************set rgb color/****************************
void setcolor(int red, int green, int blue)
{
	KGNS::currentRGBcolor.r = red;
	KGNS::currentRGBcolor.g = green;
	KGNS::currentRGBcolor.b = blue;
	sprintf(KGNS::command, "setrgbcolor(%i,%i,%i);\n", red, green, blue);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	KGNS::isCOLOR = 2;
}
///***********setFillColor___COLORS************************************
void setfillcolor(COLORS color)
{
	KGNS::curentFillColor = color;
	sprintf(KGNS::command, "setfillcolor(%i);\n", color);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	KGNS::isFillCOLOR = 0;
}
//***************set color to fill polygon*********************************
void setfillcolor(int color)
{
	KGNS::curentFillIntColor = color;
	sprintf(KGNS::command, "setfillcolor(%i);\n", color);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	KGNS::isFillCOLOR = 1;
}
//***************set color to fill polygon*********************************
void setfillcolor(int red, int green, int blue)
{
	KGNS::currentFillRGBcolor.r = red;
	KGNS::currentFillRGBcolor.g = green;
	KGNS::currentFillRGBcolor.b = blue;
	sprintf(KGNS::command, "setfillrgbcolor(%i,%i,%i);\n", red, green, blue);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
	KGNS::isFillCOLOR = 2;
}
///**************set PATERN patern and COLORS color to fill some polygon*********
void setfillstyle(PATERN patern, COLORS color)
{
	setfillcolor(color);
	sprintf(KGNS::command, "setfillstyle(%i);\n", patern);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
}
//**************set int patern and COLORS color to fill some polygon*********
void setfillstyle(int patern, COLORS color)
{
	setfillcolor(color);
	sprintf(KGNS::command, "setfillstyle(%i);\n", patern);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
}
//**************set int PATERN patern and int color to fill some polygon*********
void setfillstyle(PATERN patern, int color)
{
	setfillcolor(color);
	sprintf(KGNS::command, "setfillstyle(%i);\n", patern);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
}
//**************set int patern and int color to fill some polygon*********
void setfillstyle(int patern, int color)
{
	setfillcolor(color);
	sprintf(KGNS::command, "setfillstyle(%i);\n", patern);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);
	
}
///***********setLineStyle**********************************
void setlinestyle(int linestyle, unsigned upattern, int thickness)
{
	sprintf(KGNS::command, "setlinestyle(%i,%i);\n", linestyle, thickness);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
//***********setLineStyle**********************************
void setlinestyle(LINESTYLE linestyle, unsigned upattern, int thickness)
{
  	sprintf(KGNS::command, "setlinestyle(%i,%i);\n", linestyle, thickness);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
///***********setTetxtStyle*******************************
void settextstyle(char *font, int direction, int size)
{
	sprintf(KGNS::command, "settextstyle(%s,%i,%i);\n", font, direction, size);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	
}
///************-This function hide turtle-******************
void hideturtle(void)
{
	sprintf(KGNS::command, "hideturtle();\n");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function show turtle-******************
void showturtle(void)
{
	sprintf(KGNS::command, "showturtle();\n");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function move turtle back for seted steps-******************
void goback(int step)
{
	sprintf(KGNS::command, "turtlegoback(%i);\n", step);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function move turtle forward for seted steps-******************
void goforward(int step)
{
	sprintf(KGNS::command, "turtlegoforward(%i);\n", step);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function turn turtle left for seted angle-******************
void left(int angle)
{
	sprintf(KGNS::command, "turtleleft(%i);\n", angle);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function let your turtle paint-******************
void turtlepaint(void)
{
	sprintf(KGNS::command, "turtlepaint();\n");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function let your turtle paint not-******************
void turtlepaintnot(void)
{
	sprintf(KGNS::command, "turtlepaintnot();\n");
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}
///************-This function turn turtle right for seted angle-******************
void right(int angle)
{
	sprintf(KGNS::command, "turtleright(%i);\n", angle);
	fprintf(KGNS::kuzyaGraphFile, KGNS::command);	  
}

///***************
///**************************************
///**************
void KGNS::setPreviouslySetedColor(void)
{
    if (0 == KGNS::isCOLOR)				      ///previously seted color to draw figurs
    {
      setcolor(KGNS::curentColor);
    }
    else if (1 == KGNS::isCOLOR)
    {
      setcolor(KGNS::curentIntColor);
    }
    else if (2 == KGNS::isCOLOR)
    {
      setcolor(KGNS::currentRGBcolor.r, KGNS::currentRGBcolor.g, KGNS::currentRGBcolor.b);
    }
} 
