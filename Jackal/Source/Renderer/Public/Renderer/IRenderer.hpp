// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


namespace jackal {

// TODO(): These objects need to be 
class Mesh;
class Material;
class RenderCommand;
class JSceneNode;
class JScene;
class JCommandList;
class Light;
class RenderDevice;


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
class IRenderer {
public:
  virtual ~IRenderer() { }
  
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

  // Push back a scene node, in which the renderer will extract information 
  // about it, and render accordingly. Use pruning techniques to limit the 
  // tree traversal and save some time for performance.
  virtual void PushBack(JSceneNode *node) = 0;

  // Push back a Scene into the renderer, this will ultimately push the 
  // scene for rendering.
  virtual void PushBack(JScene *scene) = 0;

  // Simple light push back. 
  // NOTE(): This may not be needed!!
  virtual void PushBackLight(Light *light) = 0;

  // Get the command list from this renderer.
  virtual JCommandList &GetCommandList() = 0; 

  // Return the current rendering device. 
  RenderDevice *GetRenderDevice() { return mCurrentRenderDevice; }

  // Sets the new render device for this renderer.
  // Do not set to null, as this Renderer will not render anything on the screen.
  void SetRenderDevice(RenderDevice *device) { mCurrentRenderDevice = device; }

  // Get the last error from this render device.
  RendererErrorT GetLastError() { return mLastError; }
protected:
  // Current Render Device used for this Renderer.
  RenderDevice *mCurrentRenderDevice;

  // Error Verbose Handler for this Renderer object. Use this to update,
  // view, the last error that occured in this device.
  RendererErrorT mLastError;
  
};
} // jackal