#include <node/node_calculator.h>

namespace node_caluclator {

Napi::FunctionReference NodeCalculator::constructor;

Napi::Object NodeCalculator::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env, "NodeCalculator",
                  {InstanceMethod("add", &NodeCalculator::add),
                   InstanceMethod("subtract", &NodeCalculator::subtract),
                   InstanceMethod("divide", &NodeCalculator::divide),
                   InstanceMethod("multiply", &NodeCalculator::multiply)});

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("NodeCalculator", func);
  return exports;
}

NodeCalculator::NodeCalculator(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<NodeCalculator>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  m_calc = wora::Calculator();
}

Napi::Value NodeCalculator::add(const Napi::CallbackInfo &info) {
  Napi::Number a;
  Napi::Number b;

  if (info.Length() <= 1 || !info[0].IsNumber() || !info[1].IsNumber()) {
    return Napi::Number::New(info.Env(), 0);
  }

  a = info[0].As<Napi::Number>();
  b = info[1].As<Napi::Number>();

  double c = m_calc.add(a.DoubleValue(), b.DoubleValue());

  return Napi::Number::New(info.Env(), c);
}

Napi::Value NodeCalculator::subtract(const Napi::CallbackInfo &info) {
  Napi::Number a;
  Napi::Number b;

  if (info.Length() <= 1 || !info[0].IsNumber() || !info[1].IsNumber()) {
    return Napi::Number::New(info.Env(), 0);
  }

  a = info[0].As<Napi::Number>();
  b = info[1].As<Napi::Number>();

  double c = m_calc.subtract(a.DoubleValue(), b.DoubleValue());

  return Napi::Number::New(info.Env(), c);
}

Napi::Value NodeCalculator::divide(const Napi::CallbackInfo &info) {
  Napi::Number a;
  Napi::Number b;

  if (info.Length() <= 1 || !info[0].IsNumber() || !info[1].IsNumber()) {
    return Napi::Number::New(info.Env(), 0);
  }

  a = info[0].As<Napi::Number>();
  b = info[1].As<Napi::Number>();

  double c = m_calc.divide(a.DoubleValue(), b.DoubleValue());

  return Napi::Number::New(info.Env(), c);
}

Napi::Value NodeCalculator::multiply(const Napi::CallbackInfo &info) {
  Napi::Number a;
  Napi::Number b;

  if (info.Length() <= 1 || !info[0].IsNumber() || !info[1].IsNumber()) {
    return Napi::Number::New(info.Env(), 0);
  }

  a = info[0].As<Napi::Number>();
  b = info[1].As<Napi::Number>();

  double c = m_calc.multiply(a.DoubleValue(), b.DoubleValue());

  return Napi::Number::New(info.Env(), c);
}

} // namespace node_caluclator
