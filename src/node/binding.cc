#ifndef NAPI_DISABLE_CPP_EXCEPTIONS
#define NAPI_DISABLE_CPP_EXCEPTIONS
#endif

#include <napi.h>
#include <node/node_calculator.h>

namespace node_caluclator {

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  NodeCalculator::Init(env, exports);
  return exports;
}

NODE_API_MODULE(node_wora, Init)

} // namespace node_caluclator