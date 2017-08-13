// Copyright (c) 2017 Jackal Engine, MIT License
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "RenderObject.hpp"
#include "RenderDeviceTypes.hpp"

namespace jackal {


class FrameBuffer;

// RenderPass attachment information.
struct RenderPassAttachment {
  FormatT           Format;
  SampleCount       Samples;
  AttachmentLoadOp  LoadOp;
  AttachmentStoreOp StoreOp;
  ImageLayout       InitialLayout;
  ImageLayout       FinalLayout;
};


// RenderPass Attachment reference deals with the references that are 
// associated with the attachments in the renderpass. They define what
// is being used, and how it is being used, inside a Framebuffer. This
// can then transition to how data is being passed from one framebuffer to the
// next.
struct RenderPassAttachmentReference {
  uint32            Attachment;
  ImageLayout       Layout;
};


// Subpasses act as references that are provided by the previous pass, should
// any dependency be needed, such as post processing and whatnot.
struct SubPass {
  PipelineBindPoint               PipelineBindPoint;
  uint32                          ColorAttachmentCount;
  RenderPassAttachmentReference*  PColorAttachments;
  uint32                          DepthStencilAttachmentCount;
  RenderPassAttachmentReference*  PDepthStencilAttachments;
  uint32                          InputAttachmentCount;
  RenderPassAttachmentReference*  PInputAttachments;
  uint32                          ResolveAttachmentCount;
  RenderPassAttachmentReference*  PResolveAttachments;
};


struct RenderPassCreateInfoT {
  uint32                AttachmentCount;
  RenderPassAttachment* Attachments;
  uint32                SubPassCount;
  SubPass*              SubPasses;

  // TODO(): Will need to add in Dependencies, should we really need them...
};

// Render Pass object. Specifies the color, depth, 
// and stencil buffers that will be bound when rendering. They also
// serve as how these buffers will be handled throughout the rendering
// operation. They are mainly descriptions that are used to determine 
// how to use the buffers that are set in FrameBuffers.
class RenderPass : public RenderObject {
protected:
  RenderPass() { }

public:

  virtual ~RenderPass() { }

  
  // Get the frame buffer reference.
  FrameBuffer *GetFrameBufferReference() { return mFrameBufferReference; }

  virtual void Initialize(RenderPassCreateInfoT& info) = 0;
  virtual void CleanUp() = 0;

protected:
  FrameBuffer *mFrameBufferReference;
};
} // jackal