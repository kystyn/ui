#ifndef __UTILS_H_
#define __UTILS_H_

#include "editor.h"

void LineUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void LineDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void PageUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void PageDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );

int textWidthToHScroll( TEXTDATA *td, TEXTRNDDATA *trd, int minScroll, int maxScroll );
int textHeightToVScroll( TEXTDATA *td, TEXTRNDDATA *trd, int minScroll, int maxScroll );

int hScrollToTextWidth( TEXTDATA *td, TEXTRNDDATA *trd, int scrollPos, int minScroll, int maxScroll );
int vScrollToTextHeight( int endYLeftUp, int scrollPos, int minScroll, int maxScroll );

void invalidateScreen( HWND hWnd, TEXTRNDDATA *trd, TEXTMETRIC *tm );

#endif // __UTILS_H_
