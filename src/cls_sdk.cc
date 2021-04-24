#include "rados/objclass.h"

CLS_VER(1, 0)
CLS_NAME(cls_sdk)

cls_handle_t h_class;
cls_method_handle_t h_read_op;

static int read_op(cls_method_context_t hctx, ceph::buffer::list *in, ceph::buffer::list *out) {
    CLS_LOG(0, "hello");

  ceph::buffer::list bl;
  int ret = cls_cxx_read(hctx, 0, 0, &bl);
  if (ret < 0)
    return ret;
  return 0;
}

CLS_INIT(cls_sdk) {
  CLS_LOG(20, "loading cls_sdk class");

  cls_register("cls_sdk", &h_class);

  cls_register_cxx_method(h_class, "read_op",
                          CLS_METHOD_RD, read_op,
                          &h_read_op);
}
