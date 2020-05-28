 /*
 ==============================================================================
 
 This file is part of the iPlug 2 library. Copyright (C) the iPlug 2 developers.
 
 See LICENSE.txt for  more info.
 
 ==============================================================================
*/

#pragma once

#include "IPlugWebViewEditorDelegate.h"

#include "json11.cpp"

using namespace iplug;

WebViewEditorDelegate::WebViewEditorDelegate(int nParams)
  : IEditorDelegate(nParams)
  , IWebView()
{
}

WebViewEditorDelegate::~WebViewEditorDelegate()
{
  CloseWindow();
}

extern int GetScaleForHWND(HWND hWnd);

void* WebViewEditorDelegate::OpenWindow(void* pParent)
{
  RECT r;
  HWND hWnd = (HWND) pParent;
  GetClientRect(hWnd, &r);
  int scale = GetScaleForHWND(hWnd);

  void* pWebView = OpenWebView(pParent, r.left / scale, r.top / scale, (r.right - r.left) / scale, (r.bottom - r.top) / scale, scale);

  OnUIOpen();

  return pWebView;
}
