// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderDevice.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"

#include "Dx3D11Config.hpp"


namespace jackal {


// Direct X 11 rendering device.
class Dx3D11Device : public RenderDevice {
public:

private:
  ID3D11Device*           mNativeDevice;
  ID3D11DeviceContext*    mNativeContext;
  IDXGISwapChain*         mSwapChain;
};
} // jackal