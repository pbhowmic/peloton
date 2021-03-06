//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// sql_statement.cpp
//
// Identification: src/parser/sql_statement.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

/*-------------------------------------------------------------------------
 *
 * sql_statement.cpp
 * file description
 *
 * Copyright(c) 2015, CMU
 *
 * /n-store/src/parser/sql_statement.cpp
 *
 *-------------------------------------------------------------------------
 */

#include "parser/sql_statement.h"

#include "parser/parser_utils.h"

namespace peloton {
namespace parser {

//===--------------------------------------------------------------------===//
// Utilities
//===--------------------------------------------------------------------===//

const std::string SQLStatement::GetInfo() const {
  std::ostringstream os;

  os << "STATEMENT : Type :: " << stmt_type << "\n";

  int indent = 1;

  switch (stmt_type) {
    case STATEMENT_TYPE_SELECT:
      GetSelectStatementInfo((SelectStatement*)this, indent);
      break;
    case STATEMENT_TYPE_INSERT:
      GetInsertStatementInfo((InsertStatement*)this, indent);
      break;
    case STATEMENT_TYPE_CREATE:
      GetCreateStatementInfo((CreateStatement*)this, indent);
      break;
    default:
      break;
  }

  return os.str();
}

const std::string SQLStatementList::GetInfo() const {
  std::ostringstream os;

  if (is_valid) {
    for (auto stmt : statements) {
      os << stmt->GetInfo();
    }
  }
  else {
    os << "Invalid statement list \n";
  }

  return os.str();
}

}  // End parser namespace
}  // End peloton namespace
