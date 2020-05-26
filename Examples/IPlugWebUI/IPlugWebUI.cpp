#include "IPlugWebUI.h"
#include "IPlug_include_in_plug_src.h"

IPlugWebUI::IPlugWebUI(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPrograms))
{
  GetParam(kGain)->InitGain("Gain");
  
  mEditorInitFunc = [&]() {
    LoadURL("https://github.com/olilarkin");
    //To load over http:// the host app needs to have NSAppTransportSecurity set to allow it, in its info.plist.
    //https://developer.apple.com/documentation/bundleresources/information_property_list/nsapptransportsecurity?language=objc
    //This is impractical for audio plugins, but perhaps viable for standalone apps
    //To serve content from the app you can use IWebsocketServer which wraps Civetweb
    
    //Otherwise you can load web content into WKWebView via the filesystem, but beware, many modern toolkits like React require content to be served!
    //LoadFile("index.html", GetBundleID());
  };
  
  MakePreset("One", 0.);
  MakePreset("Two", 10.);
  MakePreset("Three", 100.);
}

void IPlugWebUI::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  const double gain = GetParam(kGain)->DBToAmp();
  
  sample maxVal = 0.;
  
  mOscillator.ProcessBlock(inputs[0], nFrames); // comment for audio in

  for (int s = 0; s < nFrames; s++)
  {
    outputs[0][s] = inputs[0][s] * mGainSmoother.Process(gain);
    outputs[1][s] = outputs[0][s]; // copy left
    
    maxVal += std::fabs(outputs[0][s]);
  }
  
  mLastPeak = maxVal / (sample) nFrames;
}

void IPlugWebUI::OnReset()
{
  auto sr = GetSampleRate();
  mOscillator.SetSampleRate(sr);
  mGainSmoother.SetSmoothTime(20., sr);
}

bool IPlugWebUI::OnMessage(int msgTag, int ctrlTag, int dataSize, const void* pData)
{
  if(msgTag == kMsgTagButton1)
    Resize(512, 335);
  else if(msgTag == kMsgTagButton2)
    Resize(1024, 335);
  else if(msgTag == kMsgTagButton3)
    Resize(1024, 768);

  return false;
}

void IPlugWebUI::OnIdle()
{
  //SendControlValueFromDelegate(kCtrlTagMeter, mLastPeak);
}

void IPlugWebUI::OnParamChange(int paramIdx)
{
  //DBGMSG("gain %f\n", GetParam(paramIdx)->Value());
}
