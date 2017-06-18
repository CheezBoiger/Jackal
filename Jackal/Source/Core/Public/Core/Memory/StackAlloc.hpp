// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Allocator.hpp"


namespace jackal {


class StackAllocator : public Allocator {
public:
  StackAllocator();

  void *Allocate(size_t size, size_t alignment = 0) override;

  void Deallocate(void *pointer) override;

  size_t GetSizeBytes() override;

  void *ReConstruct() override;

};
} // jackal