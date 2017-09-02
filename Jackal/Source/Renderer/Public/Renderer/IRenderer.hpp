// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/Threading.hpp"
#include "Core/Math/Vector3.hpp"

#include "Renderable.hpp"
#include "RenderEntity.hpp"


namespace jackal {

// TODO(): These objects need to be 
class Mesh;
class Material;
class RenderCommand;
class JCommandList;
class Light;
class Mesh;
class Texture;
class RenderDevice;
class EnvMap;
class RenderEntity;
class LightProbe;
class ReflectionProbe;


// Renderer resulting types from this Renderer.
typedef enum {
  RENDERER_NO_ERROR,
  RENDERER_NULL_RENDER_DEVICE,
  RENDERER_RENDER_DEVICE_ERROR, // Error came from the render device.
  RENDERER_NO_OBJECTS_TO_RENDER,
  RENDERER_NULL_SCENE_NODE,
  RENDERER_NULL_SCENE,
} RendererErrorT;


// Interface Renderer used for rendering scenes. 
// TODO(): Need to make this renderer multithreaded, and asyncronous.
// It's intention will be to read data, and rarely manipulate it. 
//
// To Perform  Multithreaded rendering, we must divide our process into tasks, 
// submit finished gpu friendly tasks to our core thread, and await until core 
// finishes the final frame. This is idealized by Destiny engine.
class IRenderer {
public:
  virtual ~IRenderer() { }

  // Set up the renderer.  
  virtual bool8 Initialize() = 0;

  // Clean up the renderer.
  virtual bool8 CleanUp() = 0;

  // Perform the rendering scheme on the given pushed back
  // scene. Once finished, the Renderer must flush out any
  // objects that where pushed back, in order to re fill for 
  // the next frame.
  virtual void Render() = 0;

  // Present the rendered surface onto the screen. This can have 
  // multiple intentions, such as OpenGL and DirectX 11 and less 
  // swapping buffers, or Vulkan and DirectX 12 using a presentation
  // queue.
  virtual void PresentToScreen() = 0;

  // Simple light push back. 
  virtual void PushBackLight(Light* light) = 0;
  virtual void PushBackRenderEntity(RenderEntity* renderentity) = 0;

  // Create a mesh object, handled by the renderer, so send over mesh id.
  virtual Mesh* CreateMesh() = 0;

  // Capture the enviroment map within a given position.
  virtual bool8 CaptureEnviromentMap(render_id_t envmap, Vector3 position) = 0;

  // Return the current rendering device. 
  RenderDevice *GetRenderDevice() { return mCurrentDevice; }

  // Sets the new render device for this renderer.
  // Do not set to null, as this Renderer will not render anything on the screen.
  void SetRenderDevice(RenderDevice *device) { mCurrentDevice = device; }

  // Get the last error from this render device.
  RendererErrorT GetLastError() { return mLastError; }
protected:
  // Current Render Device used for this Renderer.
  RenderDevice* mCurrentDevice;

  // Error Verbose Handler for this Renderer object. Use this to update,
  // view, the last error that occured in this device.
  RendererErrorT mLastError;
  
};
} // jackal