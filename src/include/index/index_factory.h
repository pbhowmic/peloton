//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// index_factory.h
//
// Identification: src/include/index/index_factory.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <string>

#include "index/index.h"

namespace peloton {
namespace index {

//===--------------------------------------------------------------------===//
// IndexFactory
//===--------------------------------------------------------------------===//

class IndexFactory {
 public:
  // Get an index with required attributes
  static Index *GetIndex(IndexMetadata *metadata);

 private:
  static std::string GetInfo(IndexMetadata *metadata,
                             std::string comparatorType);

  //===--------------------------------------------------------------------===//
  // STX::BTREE
  //===--------------------------------------------------------------------===//

  static Index *GetBTreeIntsKeyIndex(IndexMetadata *metadata);

  static Index *GetBTreeGenericKeyIndex(IndexMetadata *metadata);

  //===--------------------------------------------------------------------===//
  // PELOTON::BWTREE
  //===--------------------------------------------------------------------===//

  static Index *GetBwTreeIntsKeyIndex(IndexMetadata *metadata);

  static Index *GetBwTreeGenericKeyIndex(IndexMetadata *metadata);
};

}  // End index namespace
}  // End peloton namespace
