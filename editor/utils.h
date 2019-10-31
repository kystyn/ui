#ifndef __UTILS_H_
#define __UTILS_H_

#include "editor.h"

void LineUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void LineDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void PageUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void PageDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd );
void invalidateScreen( HWND hWnd, TEXTRNDDATA *trd, TEXTMETRIC *tm );

#endif // __UTILS_H_
