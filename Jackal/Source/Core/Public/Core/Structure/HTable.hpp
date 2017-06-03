// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jkl {


template<typename K, typename V>
class JMap {
public:

private:

};


template<typename K, typename V>
class JHTable : public JMap<K, V> {
public:
  JHTable(const uint32 size);
  JHTable(const JHTable &table);
  JHTable(const JHTable &&table);
  JHTable(uint32 size, V *data);
  

  void Insert(const K &key, const V &value);
  V *Get(const K &key);
  bool Remove(const K &key);
private:

  struct TPair {
    V value;
    K key;
  };

  TPair *table;
};
} // jkl