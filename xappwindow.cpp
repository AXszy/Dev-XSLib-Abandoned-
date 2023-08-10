/**
 * @file xappwindow.cpp
 * @brief: 应用程序窗口的实现
 * @author: XSSunet
 * @date: 2023-07-09 10:32:35
 *
 **/

#include "xappwindow.h"
#include "xsgraphic.h"
#include "xsmovablepolygon.h"
#include "xspolygonbutton.h"
#include "xsanimatedpoint.h"
#include "xsmusic.h"
#include "xsscene.h"
#include "xsconfig.h"
#include <math.h>
#include <cstdio>

#define XS_MAIN_TIMER 1

XAppWindow::XAppWindow() : XSWindow() {

}

XAppWindow::XAppWindow(HINSTANCE hInst) : XSWindow(hInst) {

}

XAppWindow::~XAppWindow() {
	//释放资源
	
	
	//释放GDI资源
	
	this->release();
}

int XAppWindow::handle_message(HWND hwnd, UINT wm, WPARAM wp, LPARAM lp) {

	switch (wm) {
		case WM_CREATE: {
			this->on_create();
			
			
			
			SetTimer(hwnd, XS_MAIN_TIMER, 5, NULL);
			break;
		}
		case WM_PAINT: {
			XSGraphic *g = new XSGraphic(hwnd);
			
			

			delete g;
			break;
		}
		case WM_MOUSEMOVE: {
			POINT p_cur;
			this->get_cursor_pos(this->getHWND(), &p_cur);

			

			break;
		}
		case WM_LBUTTONDOWN: {
			POINT p_cur;
			this->get_cursor_pos(this->getHWND(), &p_cur);

		

			InvalidateRect(hwnd, NULL, FALSE);
			break;
		}
		case WM_LBUTTONUP: {
			POINT p_cur;
			this->get_cursor_pos(this->getHWND(), &p_cur);

			
			
			InvalidateRect(hwnd, NULL, FALSE);
			break;
		}
		case WM_TIMER: {
			switch (wp) {
				case XS_MAIN_TIMER: {
					InvalidateRect(hwnd, NULL, FALSE);
					POINT p_cur;
					this->get_cursor_pos(this->getHWND(), &p_cur);

					

					break;
				}
			}
			break;
		}
		case WM_KEYDOWN: {
			
			
			break;
		}
		case WM_KEYUP: {
			
			
			break;
		}
		default: {
			return 0;
			break;
		}
	}
	return 1;
}

void XAppWindow::get_cursor_pos(HWND hwnd, POINT *p) {
	GetCursorPos(p);
	ScreenToClient(hwnd, p);

	//获得客户区宽度和高度
	RECT rcClient;
	GetClientRect(hwnd, &rcClient);
	int client_w = rcClient.right - rcClient.left;
	int client_h = rcClient.bottom - rcClient.top;

	//计算实际坐标
	if (client_w > 0 && client_h > 0) {
		p->x = p->x * XSGRAPHIC_COMPATIBLEBMP_W / client_w;
		p->y = p->y * XSGRAPHIC_COMPATIBLEBMP_H / client_h;
	} else {
		p->x = p->y = 0;
	}
}

void XAppWindow::on_create() {
	
}
