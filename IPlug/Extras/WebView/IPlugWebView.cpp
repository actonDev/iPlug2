 /*
 ==============================================================================
 
 This file is part of the iPlug 2 library. Copyright (C) the iPlug 2 developers.
 
 See LICENSE.txt for  more info.
 
 ==============================================================================
*/

#include "IPlugWebView.h"
#include "IPlugPaths.h"

using namespace iplug;
using namespace Microsoft::WRL;

IWebView::IWebView(bool opaque)
{
}

IWebView::~IWebView()
{
  CloseWebView();
}

void* IWebView::OpenWebView(void* pParent, float x, float y, float w, float h, float scale)
{
  HWND hWnd = (HWND) pParent;

  x *= scale;
  y *= scale;
  w *= scale;
  h *= scale;

  CreateCoreWebView2EnvironmentWithDetails(nullptr, nullptr, nullptr,
    Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
      [&, hWnd, x, y, w, h](HRESULT result, ICoreWebView2Environment* env) -> HRESULT {
        env->CreateCoreWebView2Controller(hWnd, Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
          [&, hWnd, x, y, w, h](HRESULT result, ICoreWebView2Controller* controller) -> HRESULT {
            if (controller != nullptr) {
              mWebViewCtrlr = controller;
              mWebViewCtrlr->get_CoreWebView2(&mWebViewWnd);
            }

            ICoreWebView2Settings* Settings;
            mWebViewWnd->get_Settings(&Settings);
            Settings->put_IsScriptEnabled(TRUE);
            Settings->put_AreDefaultScriptDialogsEnabled(TRUE);
            Settings->put_IsWebMessageEnabled(TRUE);

            mWebViewCtrlr->put_Bounds({ (LONG) x, (LONG) y, (LONG) (x + w), (LONG) (y + h) });

            OnWebViewReady();

            return S_OK;
          }).Get());
        return S_OK;
      }).Get());


  return nullptr;
}

void IWebView::CloseWebView()
{
  mWebViewCtrlr = nullptr;
  mWebViewWnd = nullptr;
}

void IWebView::LoadHTML(const char* html)
{
  if (mWebViewWnd)
  {
    WCHAR htmlWide[IPLUG_WIN_MAX_WIDE_PATH]; // TODO: error check/size
    UTF8ToUTF16(htmlWide, html, IPLUG_WIN_MAX_WIDE_PATH); // TODO: error check/size
    mWebViewWnd->NavigateToString(htmlWide);
  }
}

void IWebView::LoadURL(const char* url)
{
  if (mWebViewWnd)
  {
    WCHAR urlWide[IPLUG_WIN_MAX_WIDE_PATH]; // TODO: error check/size
    UTF8ToUTF16(urlWide, url, IPLUG_WIN_MAX_WIDE_PATH); // TODO: error check/size
    mWebViewWnd->Navigate(urlWide);
  }
}

void IWebView::LoadFile(const char* fileName, const char* bundleID)
{

}

void IWebView::EvaluateJavaScript(const char* scriptStr, completionHandlerFunc func)
{
  if (!mWebViewWnd)
    return;

  assert(mWebViewWnd);

  WCHAR scriptWide[IPLUG_WIN_MAX_WIDE_PATH]; // TODO: error check/size
  UTF8ToUTF16(scriptWide, scriptStr, IPLUG_WIN_MAX_WIDE_PATH); // TODO: error check/size

  mWebViewWnd->ExecuteScript(scriptWide, Callback<ICoreWebView2ExecuteScriptCompletedHandler>(
    [func](HRESULT errorCode, LPCWSTR resultObjectAsJson) -> HRESULT {
      WDL_String str;
      UTF16ToUTF8(str, resultObjectAsJson);
      func(str);
      return S_OK;
    }).Get());
}

void IWebView::EnableScroll(bool enable)
{
}

void IWebView::SetWebViewBounds(float x, float y, float w, float h, float scale)
{
  if (mWebViewCtrlr)
  {
    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;

    mWebViewCtrlr->put_Bounds({ (LONG)x, (LONG)y, (LONG)(x + w), (LONG)(y + h) });
  }
}
