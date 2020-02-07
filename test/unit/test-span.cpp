//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC
// and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

///
/// Source file containing tests for Span
///

#include "RAJA/util/Span.hpp"
#include "RAJA_gtest.hpp"

TEST(Span, basic)
{
  int data[4] = {0, 1, 2, 3};
  auto span = RAJA::make_span(data, 4);
  ASSERT_EQ(0, *span.begin());
  ASSERT_EQ(0, *span.data());
  ASSERT_EQ(3, *(span.data() + 3));
  ASSERT_EQ(3, *(span.end() - 1));

  ASSERT_EQ(0, *span.cbegin());
  ASSERT_EQ(0, *span.data());
  ASSERT_EQ(3, *(span.data() + 3));
  ASSERT_EQ(3, *(span.cend() - 1));

  auto const cspan = span;
  ASSERT_EQ(0, *cspan.begin());
  ASSERT_EQ(3, *(cspan.end() - 1));

  ASSERT_FALSE(cspan.empty());
  ASSERT_EQ(4, cspan.size());

  auto const empty = RAJA::make_span((int*)nullptr, 0);
  ASSERT_TRUE(empty.empty());
  ASSERT_EQ(0, empty.size());
}
