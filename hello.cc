#include <node.h>
#include <v8.h>
#include "hello-tp.h"

using namespace v8;

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  tracepoint(hello_world, my_first_tracepoint, 23, "hello from node!");
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  exports->Set(String::NewFromUtf8(isolate, "hello"),
      FunctionTemplate::New(isolate, Method)->GetFunction());
}

NODE_MODULE(hello, Init)
