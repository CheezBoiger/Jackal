// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jackal {


template<typename K, typename V>
class JMap {
public:
  virtual ~JMap() { }
  virtual void Insert(const K &key, V &value) = 0;
  virtual V *Get(const K &key) = 0;
  virtual bool8 Remove(const K &key) = 0;
  
private:

};


template<typename K, typename V>
class JHTable : public JMap<K, V> {
public:
  JHTable(const uint32 size);
  JHTable(const JHTable &table);
  JHTable(const JHTable &&table);
  JHTable(uint32 size, V *data);
  

  void Insert(const K &key, V &value) override;
  V *Get(const K &key) override;
  bool8 Remove(const K &key) override;
  bool8 Contains(const K &key) const;

  void Clear();

private:

  struct TPair {
    V value;
    K key;
  };

  TPair *table;
};
} // jackal