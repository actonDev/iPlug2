#include "IPlugEffect.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"
#include "IWebViewControl.h"

IPlugEffect::IPlugEffect(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPrograms))
{
  GetParam(kGain)->InitDouble("Gain", 0., 0., 100.0, 0.01, "%");

#if IPLUG_EDITOR // http://bit.ly/2S64BDd
  mMakeGraphicsFunc = [&]() {
    return MakeGraphics(*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, 1.);
  };
  
  mLayoutFunc = [&](IGraphics* pGraphics) {
    pGraphics->AttachCornerResizer(EUIResizerMode::Scale, false);
    pGraphics->AttachPanelBackground(COLOR_GRAY);
    pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);
    const IRECT b = pGraphics->GetBounds();
    
    auto readyFunc = [](IWebViewControl* pCaller){
      pCaller->LoadHTML(u8"<input type=\"range\" id=\"vol\" name=\"vol\" min=\"0\" max=\"100\" onchange='IPlugSendMsg({\"msg\":\"SAMFUI\"})'>");

//      pCaller->LoadHTML(u8"<button onclick='IPlugSendMsg({\"msg\":\"SAMFUI\"})'>Hello World</button>");
      pCaller->EnableScroll(false);
    };
    
    auto msgFunc = [](IWebViewControl* pCaller, const char* json){
      pCaller->GetUI()->GetBackgroundControl()->As<IPanelControl>()->SetPattern(IColor::GetRandomColor());
    };
    
    pGraphics->AttachControl(new IWebViewControl(b.GetCentredInside(200), false, readyFunc, msgFunc), 0);
//    pGraphics->AttachControl(new IWebViewControl(b.GetFromBottom(200)));
    pGraphics->AttachControl(new IVButtonControl(b.GetFromTRHC(50, 50), [b](IControl* pCaller){
      pCaller->GetUI()->GetControlWithTag(0)->As<IWebViewControl>()->EvaluateJavaScript(R"(document.body.style.background = "#000";)");
    }));
  };
#endif
}

#if IPLUG_DSP
void IPlugEffect::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  const double gain = GetParam(kGain)->Value() / 100.;
  const int nChans = NOutChansConnected();
  
  for (int s = 0; s < nFrames; s++) {
    for (int c = 0; c < nChans; c++) {
      outputs[c][s] = inputs[c][s] * gain;
    }
  }
}
#endif
