#ifndef NODE_CALCULATOR_H
#define NODE_CALCULATOR_H

#ifndef NAPI_DISABLE_CPP_EXCEPTIONS
#define NAPI_DISABLE_CPP_EXCEPTIONS
#endif

#include <core/calculator.h>
#include <napi.h>

namespace node_caluclator {

class NodeCalculator : public Napi::ObjectWrap<NodeCalculator> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  NodeCalculator(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  wora::Calculator m_calc;

  Napi::Value add(const Napi::CallbackInfo &info);
  Napi::Value subtract(const Napi::CallbackInfo &info);
  Napi::Value divide(const Napi::CallbackInfo &info);
  Napi::Value multiply(const Napi::CallbackInfo &info);
};

} // namespace node_caluclator

#endif