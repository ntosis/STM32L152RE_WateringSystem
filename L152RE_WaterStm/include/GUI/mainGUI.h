#ifndef MAINGUI_H
#define MAINGUI_H

#include "GUI.h"
#include "DIALOG.h"
#include "RtrEncdBtn.h"
 #define GUI_MAKE_COLOR(ABGR) (((((U32)ABGR) & 0xFF000000ul) ^ 0xFF000000ul) | ((((U32)ABGR) & 0x00FF0000ul) >> 16) | (((U32)ABGR) & 0x0000FF00ul) | ((((U32)ABGR) & 0x000000FFul) << 16))
void GUITask(void);
WM_HWIN CreateWindow(void);
#endif
