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

void* WebViewEditorDelegate::OpenWindow(void* pParent)
{
  void* view = OpenWebView(pParent, 0, 0, 600, 600, 2.f);
  return view;
}
