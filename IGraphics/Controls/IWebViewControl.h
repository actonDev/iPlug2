/*
 ==============================================================================

 This file is part of the iPlug 2 library. Copyright (C) the iPlug 2 developers.

 See LICENSE.txt for  more info.

 ==============================================================================
*/

#pragma once

/**
 * @file
 * @ingroup Controls
 * @copydoc IWebViewControl
 */

#include "IControl.h"
#include "IPlugWebView.h"

BEGIN_IPLUG_NAMESPACE
BEGIN_IGRAPHICS_NAMESPACE

class IWebViewControl;

using OnReadyFunc = std::function<void(IWebViewControl* pWebView)>;

/** @ingroup IControls */
class IWebViewControl : public IControl, public IWebView
{
public:
  IWebViewControl(const IRECT& bounds, bool opaque = true, OnReadyFunc func = nullptr)
  : IControl(bounds)
  , IWebView(opaque)
  , mOnReadyFunc(func)
  {
  }
  
  void OnAttached() override
  {
    GetUI()->AddPlatformView(mRECT, OpenWebView(GetUI()->GetWindow(), mRECT.L, mRECT.T, mRECT.W(), mRECT.H(), GetUI()->GetTotalScale()));
  }
  
  void Draw(IGraphics& g) override
  {
     /* NO-OP */
  }

  void OnWebViewReady() override
  {
    if(mOnReadyFunc)
      mOnReadyFunc(this);
  }

  void OnRescale() override
  {
    SetWebViewBounds(mRECT.L, mRECT.T, mRECT.W(), mRECT.H(), GetUI()->GetTotalScale());
  }

  void OnResize() override
  {
    SetWebViewBounds(mRECT.L, mRECT.T, mRECT.W(), mRECT.H(), GetUI()->GetTotalScale());
  }
  
private:
  OnReadyFunc mOnReadyFunc;
};

END_IGRAPHICS_NAMESPACE
END_IPLUG_NAMESPACE

