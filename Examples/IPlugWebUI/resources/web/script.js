// FROM DELEGATE

function SPVFD(paramIdx, val) {
//  console.log("paramIdx: " + paramIdx + " value:" + val);
  OnParamChange(paramIdx, val);
}

function SCVFD(ctrlTag, val) {
  OnControlChange(ctrlTag, val);
//  console.log("SCVFD ctrlTag: " + ctrlTag + " value:" + val);
}

function SCMFD(ctrlTag, msgTag, dataSize, msg) {
//  var decodedData = window.atob(msg);
  console.log("SCMFD ctrlTag: " + ctrlTag + " msgTag:" + msgTag + "msg:" + msg);
}

function SAMFD(msgTag, dataSize, msg) {
  //  var decodedData = window.atob(msg);
  console.log("SAMFD msgTag:" + msgTag + " msg:" + msg);
}

function SMMFD(statusByte, dataByte1, dataByte2) {
  console.log("Got MIDI Message" + status + ":" + dataByte1 + ":" + dataByte2);
}

function SSMFD(offset, size, msg) {
  console.log("Got Sysex Message");
}

function doSendMessage(message) {
  if(typeof webkit !== 'undefined') // WkWebkitView
    webkit.messageHandlers.callback.postMessage(message);
  else // ICoreWebView2
    window.chrome.webview.postMessage(message);
}

// FROM UI
function SAMFUI(msgTag, ctrlTag = -1, dataSize = 0, data = 0) {
  var message = {
    "msg": "SAMFUI",
    "msgTag": msgTag,
    "ctrlTag": ctrlTag,
    "dataSize": dataSize,
    "data": data
  };
  
  doSendMessage(message);
}

function SMMFUI(statusByte, dataByte1, dataByte2) {
  var message = {
    "msg": "SMMFUI",
    "statusByte": statusByte,
    "dataByte1": dataByte1,
    "dataByte2": dataByte2
  };
  
  doSendMessage(message);
}

function SSMFUI(dataSize = 0, data = 0) {
  var message = {
    "msg": "SSMFUI",
    "dataSize": dataSize,
    "data": data
  };
  
  doSendMessage(message);
}

function EPCFUI(paramIdx) {
  var message = {
    "msg": "EPCFUI",
    "paramIdx": paramIdx,
  };
  
  doSendMessage(message);
}

function BPCFUI(paramIdx) {
  var message = {
    "msg": "BPCFUI",
    "paramIdx": paramIdx,
  };
  
  doSendMessage(message);
}

function SPVFUI(paramIdx, value) {
  var message = {
    "msg": "SPVFUI",
    "paramIdx": paramIdx,
    "value": value
  };

  doSendMessage(message);
}
