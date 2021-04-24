#include <iostream>
#include <errno.h>

#include "test_utils.h"
#include "gtest/gtest.h"

using namespace librados;


TEST(ClsSDK, TestReadOp) {
  Rados cluster;
  std::string pool_name = get_temp_pool_name();
  ASSERT_EQ("", create_one_pool_pp(pool_name, cluster));
  IoCtx ioctx;
  cluster.ioctx_create(pool_name.c_str(), ioctx);

  bufferlist in, out;
  ASSERT_EQ(0, ioctx.exec("test_object", "cls_sdk", "read_op", in, out));

  ASSERT_EQ(0, destroy_one_pool_pp(pool_name, cluster));
}
