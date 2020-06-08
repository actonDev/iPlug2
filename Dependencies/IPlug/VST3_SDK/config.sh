#!/bin/bash
SDK_URL="https://download.steinberg.net/sdk_downloads/vst-sdk_3.6.14_build-24_2019-11-29.zip"
SDK_SHA="1f61d847d4fbd570a2b3d3cc14210b4e7f808f87b641a44b146a07f708cb1552"

cd $(dirname ${BASH_SOURCE[0]})

echo "Configuring VST3 SDK in pwd: $(pwd)"

if [ -d "base" ] && [ -d "pluginterfaces" ] && [ -d "public.sdk" ]; then
  echo "sdk data already here, skipping"
  exit 0
fi

if [ ! -f "vst-sdk.zip" ]; then
    wget -O vst-sdk.zip "$SDK_URL"
fi

echo "$SDK_SHA  vst-sdk.zip" | shasum -a 256 -c
if [ $? != 0 ]; then
    echo 'vst-sdk.zip checksum is not valid'
    exit 1
fi

unzip -qq -o 'vst-sdk.zip' 'VST_SDK/VST3_SDK/base/**' 'VST_SDK/VST3_SDK/pluginterfaces/**' 'VST_SDK/VST3_SDK/public.sdk/source/**' -d out
mv -f out/VST_SDK/VST3_SDK/* .
rm -r out
