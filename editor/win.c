#include <stdio.h>
#include "win.h"

HWND initWnd(
             HINSTANCE hInst, LPSTR lpszArgument,
             int nCmdShow, WNDPROC wndProc )
{
    HWND hWnd;               /* This is the handle for our window */
    WNDCLASSEX wincl;// = {0};        /* Data structure for the windowclass */
    LPCSTR szClassName = "Kystyn";

    /* The Window structure */
    wincl.hInstance = hInst;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = wndProc;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = NULL;//LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = NULL;//LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = strlen(lpszArgument) + 1;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return NULL;

    /* The class is registered, let's create the program*/
    hWnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Kystyn vim",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           CW_USEDEFAULT,                 /* The programs width */
           CW_USEDEFAULT,                 /* and height in pixels */
           NULL,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hInst,               /* Program Instance handler */
           lpszArgument         /* No Window Creation data */
           );

    if (hWnd == NULL)
        return NULL;

    /* Make the window visible on the screen */
    UpdateWindow(hWnd);
    ShowWindow(hWnd, nCmdShow);

    return hWnd;
}

int runMsgLoop( void )
{
    MSG msg;
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&msg, NULL, 0, 0))
    {
        /* Translate virtual-key msg into character msg */
        TranslateMessage(&msg);
        /* Send message to WindowProcedure */
        DispatchMessage(&msg);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return msg.wParam;
}
