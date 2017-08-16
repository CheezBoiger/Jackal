// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderDevice.hpp"
#include "Dx12Config.hpp"


namespace jackal {


class Dx12Device : public RenderDevice {
public:



private:
  ID3D12Device*         mDevice;
  IDXGISwapChain*       mSwapChain;
  ID3D12CommandQueue*   mCommandQueue;
};
} // jackal